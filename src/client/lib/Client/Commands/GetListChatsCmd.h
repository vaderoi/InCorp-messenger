#ifndef APPLICATION_GETLISTCHATSCMD_H
#define APPLICATION_GETLISTCHATSCMD_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/ListChats.h"


// Command for get list of chat
class GetListChatsCmd : public BaseCmd {
public:
    ~GetListChatsCmd() override = default;

    GetListChatsCmd(int numRequest, const std::optional<std::string>& error,
                    const std::string& body);

    // Execute command
    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};


#endif //APPLICATION_GETLISTCHATSCMD_H
