cmake_minimum_required(VERSION 3.16)
project(ServerApp)

set(CMAKE_CXX_STANDARD 17)


add_library(ServerApp STATIC
        Server/Server.cpp
        Server/WorkerThread.cpp
        MainServerLogic/CommandHandler/CommandHandler.cpp
        MainServerLogic/CommandCreator/CommandCreator.cpp
        MainServerLogic/Commands/Login.cpp
        MainServerLogic/Commands/GetServerLogs.cpp
        MainServerLogic/Commands/CompanyCommand.cpp
        MainServerLogic/Commands/RegisterUser.cpp
        MainServerLogic/MainLogic/MainLogic.cpp
        MainServerLogic/MainLogic/Controller/Controller.cpp
        MainServerLogic/MainLogic/Managers/AuthorizationManager.cpp
        ../Connection/Connection.cpp
        )


if (APPLE)
    target_include_directories(ServerApp PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)
    target_link_libraries(ServerApp
            #-lboost_system
            -lpthread
            -std=c++17)

elseif (UNIX)
    find_package(libmongocxx REQUIRED)
    find_package(libbsoncxx REQUIRED)
    find_package(Boost 1.71.0 COMPONENTS system filesystem REQUIRED)
    include_directories(${Boost_INCLUDE_DIRS})
    include_directories(${Boost_LIBRARIES})
    include_directories(${BOOST_ROOT})

    target_include_directories(ServerApp PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
            ${LIBMONGOCXX_INCLUDE_DIRS}
            ${LIBBSONCXX_INCLUDE_DIR}
            ${PROJECT_SOURCE_DIR})
    target_link_libraries(ServerApp
            -lboost_system
            -lpthread
            -std=c++17
            -pthread
            -lpthread -lboost_thread
            ${LIBMONGOCXX_LIBRARIES}
            ${LIBBSONCXX_LIBRARIES})




    #    target_compile_definitions(test_mongocxx PUBLIC ${LIBMONGOCXX_DEFINITIONS})
endif()