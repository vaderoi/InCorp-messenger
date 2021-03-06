#ifndef APPLICATION_GETLOG_H
#define APPLICATION_GETLOG_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/LogUpdates.h"


// Command for get log
class GetLogCmd : public BaseCmd {
public:
    ~GetLogCmd() override = default;

    GetLogCmd(int numRequest, const std::optional<std::string>& error,
              const std::string&  body);

    // Execute command
    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};

#endif //APPLICATION_GETLOG_H
