#include "Message.h"

Message::Message()
        : chatId(-1), ownerId(-1), timeSend(0), number(0) {}

Message::Message(int chatId, const std::string &text,
                 int ownerId, time_t timeSend, unsigned int number)
        : chatId(chatId), text(text),
          ownerId(ownerId), timeSend(timeSend), number(number) {}

Message::Message(int chatId)
        : chatId(chatId) {}

std::string Message::encode() const {
    parser->clear();

    parser->addValue(chatId, KeyWords::chatId);
    parser->addValue(text, KeyWords::text);
    parser->addValue(ownerId, KeyWords::ownerId);
    parser->addValue(timeSend, KeyWords::timeSend);
    parser->addValue(number, KeyWords::number);
    return parser->getJson();
}

void Message::decode(const std::string &jsonStr) {
    parser->setJson(jsonStr);

    text = parser->getValue<std::string>(KeyWords::text);
    ownerId = parser->getValue<int>(KeyWords::ownerId);
    chatId = parser->getValue<int>(KeyWords::chatId);
    timeSend = parser->getValue<int>(KeyWords::timeSend);
    isChecked = parser->getValue<bool>(KeyWords::isChecked);
    number = parser->getValue<unsigned int>(KeyWords::number);
}
