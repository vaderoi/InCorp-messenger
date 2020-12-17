#include "User.h"

User::User() : userId(-1) {}

User::User(int userId, int chatId)
        : userId(userId), chatId(chatId) {}

std::string User::encode() const {
    parser->clear();

    parser->addValue(userId, KeyWords::userId);
    parser->addValue(chatId, KeyWords::chatId);
    return parser->getJson();
}

void User::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    userId = parser->getValue<int>(KeyWords::userId);
    firstName = parser->getValue<std::string>(KeyWords::firstName);
    lastName = parser->getValue<std::string>(KeyWords::lastName);
    role = parser->getValue<std::string>(KeyWords::role);
}
