#ifndef APPLICATION_GETUSERCMD_H
#define APPLICATION_GETUSERCMD_H

#include <iostream>

#include "BaseCmd.h"
#include "Commands/CmdCreator/Commands.h"
#include "ChatObjects/UserPreview.h"


// Command for get user
class GetUserCmd : public BaseCmd {
public:
    ~GetUserCmd() override = default;

    GetUserCmd(int numRequest, const std::optional<std::string>& error,
               const std::string& body);

    // Execute command
    void execute(std::shared_ptr<CallbacksHolder> holder) override;
};

#endif //APPLICATION_GETUSERCMD_H
