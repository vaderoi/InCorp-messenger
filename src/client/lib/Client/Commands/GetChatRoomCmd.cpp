#include "GetChatRoomCmd.h"

GetChatRoomCmd::GetChatRoomCmd(int numRequest, const std::optional<std::string>& error,
                               const std::string& body)
        : BaseCmd(numRequest, error, body) {}

void GetChatRoomCmd::execute(std::shared_ptr<CallbacksHolder> holder) {
    std::shared_ptr<BaseObject> chatRoom = std::make_shared<ChatRoom>();
    chatRoom->decode(body);

    auto func = holder->getCallback(Commands::GetSelectChatRoom, numRequest).get();
    (*func)(chatRoom, error);
}
