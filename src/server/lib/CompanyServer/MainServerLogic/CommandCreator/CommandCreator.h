#ifndef TP_PPROJECT_COMMANDPARSER_H
#define TP_PPROJECT_COMMANDPARSER_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/BaseCommand.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Login.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Logout.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/WriteMessage.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/CreateChat.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/DeleteChat.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/DeleteUser.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/CreateUser.h"

enum Command {
    PING=-1,
    LOGIN,
    WRITE_MESSAGE,
    LOGOUT,
    CREATE_CHAT,
    DELETE_CHAT,
    DELETE_USER,
    CREATE_USER
};

class CommandCreator {
public:
    std::shared_ptr<BaseCommand> createCommand(std::string message);
};

#endif