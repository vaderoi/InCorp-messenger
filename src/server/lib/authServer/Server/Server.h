#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include "src/server/lib/CompanyServer/MainServerLogic/CommandHandler/CommandHandler.h"
#include "src/server/lib/Connection/Connection.h"

/*
 * Singleton responsible for storing user IDs and their connections
 */
class ClientsCollection {
public:
    static std::shared_ptr<ClientsCollection> getInstance();
    std::map<int, std::shared_ptr<Connection>> clientsCollection;
private:
    ClientsCollection() : clientsCollection() {};
};


/*
 * Server class
 */
class Server: public std::enable_shared_from_this<Server>  {
public:
    Server(boost::asio::io_service& io_service,
           boost::asio::io_service::strand& strand,
           const boost::asio::ip::tcp::endpoint& endpoint);
    ~Server() = default;

private:
    /*
     * Starting async accept method
     */
    void run();
    void on_accept(std::shared_ptr<Connection> connection, const boost::system::error_code& error);
    boost::asio::io_service &io_service;
    boost::asio::ip::tcp::acceptor acceptor;
    boost::asio::io_service::strand& strand;
};
#endif
