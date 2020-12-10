#ifndef APPLICATION_SENDMESSAGECMD_H
#define APPLICATION_SENDMESSAGECMD_H

#include <iostream>

#include "BaseCmd.h"
#include "ChatObjects/Message.h"
#include "Commands/CmdCreator/Commands.h"


class SendMessageCmd : public BaseCmd {
public:
    ~SendMessageCmd() override = default;

    SendMessageCmd(int numRequest, std::optional<std::string> error,
                   std::string  body);

    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};


#endif //APPLICATION_SENDMESSAGECMD_H
