#ifndef APPLICATION_GETCHATLASTMESSAGE_H
#define APPLICATION_GETCHATLASTMESSAGE_H

#include "BaseCommand.h"

/*
 * Get chat last message command class
 */
class GetChatLastMessage: public BaseCommand {
public:
    explicit GetChatLastMessage(boost::property_tree::ptree& params);

    ~GetChatLastMessage() override = default;
    /*
     * Executing a command
     */
    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};
#endif //APPLICATION_GETCHATLASTMESSAGE_H
