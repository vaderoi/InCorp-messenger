#ifndef APPLICATION_COMMANDS_H
#define APPLICATION_COMMANDS_H


enum Commands {
    ChatObserver = -2,
    ChatUpdate = -1,
    LogIn = 0,
    SendMessage = 1,
    GetListOfChats = 20,
    GetSelectChatRoom = 21,
    GetMessagesInChat = 22,
    GetLastMessageInChat = 23,
    GetUserData = 24,

};


#endif //APPLICATION_COMMANDS_H