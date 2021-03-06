#ifndef TP_PPROJECT_COMMANDPARSER_H
#define TP_PPROJECT_COMMANDPARSER_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/BaseCommand.h"
#include "src/server/lib/CompanyServer/MainServerLogic/Commands/Login.h"

/*
 * Enum of command numbers
 */
enum Command {
    PING=-1,
    LOGIN,
    WRITE_MESSAGE,
    LOGOUT,
    CREATE_CHAT,
    DELETE_CHAT,
    DELETE_USER,
    CREATE_USER,
    USERCHATSPREVIEW=20,
    CHATINFO=21,
    CHATMESSAGES=22,
    CHATLASTMESSAGE=23,
    MESSAGEAUTHORINFO=24,
    SERVERLOGS=25,
    COMPANYCOMMAND=26,
    REGISTERUSER=27,
};

/*
 * Creates an object of the Command class from the received query string
 */
class CommandCreator {
public:
    /*
     * The query string is parsed and an object class Command is created
     */
    std::shared_ptr<BaseCommand> createCommand(std::string &message);
};

#endif
