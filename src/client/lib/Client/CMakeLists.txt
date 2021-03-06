cmake_minimum_required(VERSION 3.16)
project(Client)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Chat objects
set(CHAT_OBJECTS_HEADERS
        ChatObjects/KeyWords.h
        ChatObjects/BaseObject.h
        ChatObjects/UserInfo.h
        ChatObjects/ChatUpdates.h
        ChatObjects/Message.h
        ChatObjects/Request.h
        ChatObjects/ChatUpdates.h
        ChatObjects/ChatItem.h
        ChatObjects/ListChats.h
        ChatObjects/ChatRoom.h
        ChatObjects/UserPreview.h
        ChatObjects/ChatAction.h
        ChatObjects/MessageStatus.h
        ChatObjects/Log.h
        ChatObjects/LogUpdates.h
        )

set(CHAT_OBJECTS_SOURCES
        ChatObjects/UserInfo.cpp
        ChatObjects/ChatUpdates.cpp
        ChatObjects/Message.cpp
        ChatObjects/Request.cpp
        ChatObjects/ChatUpdates.cpp
        ChatObjects/ChatItem.cpp
        ChatObjects/ListChats.cpp
        ChatObjects/ChatRoom.cpp
        ChatObjects/UserPreview.cpp
        ChatObjects/ChatAction.cpp
        ChatObjects/MessageStatus.cpp
        ChatObjects/Log.cpp
        ChatObjects/LogUpdates.cpp
        )

# Callback holder
set(CALLBACK_HOLDER_HEADERS
        CallbacksHolder/CallbacksHolder.h
        CallbacksHolder/Callback/BaseCallback.h
        )

set(CALLBACK_HOLDER_SOURCES
        )

# Client
set(CLIENT_HEADERS
        Client/BaseClient.h
        Client/Client.h
        )

set(CLIENT_SOURCES
        Client/Client.cpp
        )

# Commands
set(COMMANDS_HEADERS
        Commands/CmdCreator/Commands.h
        Commands/CmdCreator/CommandCreator.h
        Commands/AuthorizationCmd.h
        Commands/BaseCmd.h
        Commands/SendMessageCmd.h
        Commands/ChatUpdateCmd.h
        Commands/GetListChatsCmd.h
        Commands/GetChatRoomCmd.h
        Commands/GetLastMessageCmd.h
        Commands/GetChatMessagesCmd.h
        Commands/GetUserCmd.h
        Commands/ChatObserverCmd.h
        Commands/GetLogCmd.h
        Commands/SystemUpdateCmd.h
        Commands/RegistrationCmd.h
        )

set(COMMANDS_SOURCES
        Commands/CmdCreator/CommandCreator.cpp
        Commands/AuthorizationCmd.cpp
        Commands/BaseCmd.cpp
        Commands/SendMessageCmd.cpp
        Commands/ChatUpdateCmd.cpp
        Commands/GetListChatsCmd.cpp
        Commands/GetChatRoomCmd.cpp
        Commands/GetLastMessageCmd.cpp
        Commands/GetChatMessagesCmd.cpp
        Commands/GetUserCmd.cpp
        Commands/ChatObserverCmd.cpp
        Commands/GetLogCmd.cpp
        Commands/SystemUpdateCmd.cpp
        Commands/RegistrationCmd.cpp
        )

# Parser
set(PARSER_HEADERS
        Parser/Parser.h
        )

set(PARSER_SOURCES
        Parser/Parser.cpp
        )

# User options
set(USER_OPTIONS_HEADERS
        UserOptions/BaseUserOptions.h
        UserOptions/EmployeeOptions.h
        UserOptions/GuestOptions.h
        UserOptions/ManagerOptions.h
        )

set(USER_OPTIONS_SOURCES
        UserOptions/BaseUserOptions.cpp
        UserOptions/EmployeeOptions.cpp
        UserOptions/GuestOptions.cpp
        UserOptions/ManagerOptions.cpp
        )

# Controller
set(CONTROLLER_HEADERS
        Controller/Controller.h
        )

set(CONTROLLER_SOURCES
        Controller/Controller.cpp
        )

# Role controller
set(ROLE_CONTROLLER_HEADERS
        RoleController/RoleController.h
        )

set(ROLE_CONTROLLER_SOURCES
        RoleController/RoleController.cpp
        )

add_library(Client STATIC
        ${CHAT_OBJECTS_HEADERS} ${CHAT_OBJECTS_SOURCES}
        ${CALLBACK_HOLDER_HEADERS} ${CALLBACK_HOLDER_SOURCES}
        ${CLIENT_HEADERS} ${CLIENT_SOURCES}
        ${COMMANDS_HEADERS} ${COMMANDS_SOURCES}
        ${PARSER_HEADERS} ${PARSER_SOURCES}
        ${USER_OPTIONS_HEADERS} ${USER_OPTIONS_SOURCES}
        ${CONTROLLER_HEADERS} ${CONTROLLER_SOURCES}
        ${ROLE_CONTROLLER_HEADERS} ${ROLE_CONTROLLER_SOURCES}
        )

target_include_directories(Client PUBLIC "${PROJECT_SOURCE_DIR}")
