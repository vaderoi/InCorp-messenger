//
// Created by Иван Коваленко on 14.12.2020.
//

#ifndef APPLICATION_COMPANYCOMMAND_H
#define APPLICATION_COMPANYCOMMAND_H
#include "BaseCommand.h"

class CompanyCommand: public BaseCommand {
public:
    explicit CompanyCommand(boost::property_tree::ptree& params);

    ~CompanyCommand() override = default;

    boost::property_tree::ptree execute(std::shared_ptr<Controller> controller) override;
};

#endif //APPLICATION_COMPANYCOMMAND_H