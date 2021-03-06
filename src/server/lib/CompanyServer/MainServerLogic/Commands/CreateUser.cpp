#include "CreateUser.h"

boost::property_tree::ptree CreateUser::execute(std::shared_ptr<Controller> controller) {
    return controller->registerUser(commandParams);
}

CreateUser::CreateUser(boost::property_tree::ptree &params) : BaseCommand("CreateChat") {
    commandParams = params;
}
