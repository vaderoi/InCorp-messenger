#ifndef APPLICATION_CHAT_H
#define APPLICATION_CHAT_H

#include <QObject>

#include <CallbacksHolder/Callback/BaseCallback.h>
#include <ChatObjects/ChatUpdates.h>
#include <Controller/Controller.h>
#include "ui/LoginWidget/loginwidget.h"
#include "ui/MainWidget/mainwidget.h"


// Callback for Update Messages
class UpdateMessagesCallback : public BaseCallback {
public:
    UpdateMessagesCallback(std::shared_ptr<MainWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto updates = std::static_pointer_cast<ChatUpdates>(data);
        widget->chatModel->setData(updates->messages);
        emit widget->chatModel->updateItems();
    }

private:
    std::shared_ptr<MainWidget> widget;
};


// Callback for Get Chat Messages
class GetChatMessagesCallback : public BaseCallback {
public:
    GetChatMessagesCallback(std::shared_ptr<MainWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto updates = std::static_pointer_cast<ChatUpdates>(data);
        widget->chatModel->setData(updates->messages);

        if (updates->messages.size() == updates->maxNumMessages) {
            ChatUpdates chatUpdates(updates->chatId, updates->lastMessageNum + updates->maxNumMessages,
                                    updates->maxNumMessages);
            Controller::getInstance()->chatUpdate(chatUpdates, UserData::getInstance()->userId,
                                                    std::make_shared<GetChatMessagesCallback>(widget));
        }
        emit window->chatModel->updateItems();
    }

private:
    std::shared_ptr<MainWidget> widget;
};


// Callback for Get List Of Chats
class GetListChatsCallback : public BaseCallback {
public:
    GetListChatsCallback(std::shared_ptr<MainWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto list = std::static_pointer_cast<ListChats>(data);

        window ->groupModel->setData(list->chats);
        emit window->groupModel->updateItems();
    }

private:
    std::shared_ptr<MainWidget> widget;
};


// Callback for Get Chat Room
class GetChatRoomCallback : public BaseCallback {
public:
    GetChatRoomCallback(std::shared_ptr<MainWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto chatRoom = std::static_pointer_cast<ChatRoom>(data);
        emit window->groupModel->chatRoomInfo(*chatRoom);
    }

private:
    std::shared_ptr<MainWidget> widget;
};


// Callback for Get User In Chat
class GetUserForChatCallback : public BaseCallback {
public:
    GetUserForChatCallback(std::shared_ptr<ChatModel> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto user = std::static_pointer_cast<UserPreview>(data);
        std::for_each(widget->items.begin(),widget->items.end(),[user](MessageView& message){
            if (message.ownerId == user->userId){
                message.firstName = QString::fromStdString(user->firstName);
                message.lastName = QString::fromStdString(user->lastName);
                message.role = QString::fromStdString(user->role);
            }
        });
        emit window->updateItems();
    }

private:
    std::shared_ptr<ChatModel> widget;
};


// Callback for Get User In Group
class GetUserForGroupCallback : public BaseCallback {
public:
    GetUserForGroupCallback(std::shared_ptr<GroupModel> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto user = std::static_pointer_cast<UserPreview>(data);

        std::for_each(widget->items.begin(),widget->items.end(),[user](GroupView &group) {
            if (group.lastMessage.ownerId == user->userId){
                group.lastMessage.firstName = QString::fromStdString(user->firstName);
                group.lastMessage.lastName = QString::fromStdString(user->lastName);
                group.lastMessage.role = QString::fromStdString(user->role);
            }
        });
        emit window->updateItems();
    }

private:
    std::shared_ptr<GroupModel> widget;
};


// Callback for Get Last Message
class GetLastMessageCallback : public BaseCallback {
public:
    GetLastMessageCallback(std::shared_ptr<GroupModel> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto message = std::static_pointer_cast<Message>(data);
        auto it = std::find_if(widget->items.begin(),
                               widget->items.end(),[message](const GroupView &chat) {
                    return  chat.chatId == message->chatId;
                });
        MessageView newMessage(*message);
        it.base()->lastMessage = newMessage;
        UserPreview user(newMessage.ownerId, message->chatId);
        Controller::getInstance()->getUser(user, UserData::getInstance()->userId,
                                           std::make_shared<GetUserForGroupCallback>(window));

        emit window->updateItems();
    }

private:
    std::shared_ptr<GroupModel> widget;
};


// Callback for Chat Observer
class ChatObserverCallback : public BaseCallback {
public:
    ChatObserverCallback(std::shared_ptr<GroupModel> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto action = std::static_pointer_cast<ChatAction>(data);
        if (action->chatAction == 1) {
            auto message = std::static_pointer_cast<Message>(action->data);
            if (message->chatId == UserData::getInstance()->currentChatId) {
                emit window->addNewMessage(*message);
            }
            auto it = std::find_if(widget->items.begin(), widget->items.end(), [message](GroupView &chat) {
                return chat.chatId == message->chatId;
            });

            MessageView newMessage(*message);

            it.base()->lastMessage = newMessage;
            UserPreview user(newMessage.ownerId, newMessage.chatId);
            Controller::getInstance()->getUser(user, UserData::getInstance()->userId,
                                               std::make_shared<GetUserForGroupCallback>(widget));
        }
        else if (action->chatAction == 2) {
            auto checked = std::static_pointer_cast<MessageStatus>(action->data);
            if (UserData::getInstance()->currentChatId == checked->chatId) {
                emit window->messageChecked();
            }
        }
        emit window->updateItems();
    }

private:
    std::shared_ptr<GroupModel> widget;
};


// Callback for Send Message
class SendMessageCallback : public BaseCallback {
public:
    SendMessageCallback(std::shared_ptr<MainWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto message = std::static_pointer_cast<Message>(data);
        window->chatModel->updateMessageStatus(message->number, MessageView::MessageType::MESSAGE_WAS_SEND);
        UserPreview user(message->ownerId, message->chatId);
        Controller::getInstance()->getUser(user, UserData::getInstance()->userId,
                                           std::make_shared<GetUserForChatCallback>(window->chatModel));
        emit window->chatModel->updateItems();
    }

private:
    std::shared_ptr<MainWidget> widget;
};


// Callback for System Update
class SystemUpdateCallback : public BaseCallback {
public:
    SystemUpdateCallback(std::shared_ptr<MainWidget> widget) : widget(widget) {};

public:
    void operator()(std::shared_ptr<BaseObject> data,
                    const std::optional<std::string>& error) override {
        auto window = widget;
        auto action = std::static_pointer_cast<ChatAction>(data);
        if (action->chatAction == 1) {
            auto chat = std::static_pointer_cast<ChatItem>(action->data);
            emit window->groupModel->newChat(*chat);
        }
        emit window->groupModel->updateItems();
    }

private:
    std::shared_ptr<MainWidget> widget;
};

#endif //APPLICATION_CHAT_H
