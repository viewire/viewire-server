#include "server.h"
#include <iostream>

Server::Server(QObject *parent) : QObject(parent) {}


void Server::initSocket(int port) {
    SOCKET = new QUdpSocket(this);
    bool connected = SOCKET->bind(QHostAddress::LocalHost, port);

    /*
     * The most common way to use this class is to bind to an address and port using bind(), then call writeDatagram() and readDatagram() / receiveDatagram() to transfer data. If                                                                *    * you want to use the standard QIODevice functions read(), readLine(), write(), etc., you must first connect the socket directly to a peer by
     * calling connectToHost().
     *
     */
    connect(SOCKET, &QUdpSocket::readyRead, this, &Server::readPendingDatagrams);

    std::cout << (connected ? "CONNECTED!" : "ERROR: CONNECTION FAILED.") << std::endl;

}

void Server::readPendingDatagrams()
{
    // While there are datagrams to read, read them.
    while (SOCKET->hasPendingDatagrams()) {
        QNetworkDatagram datagram = SOCKET->receiveDatagram();

        //processTheDatagram(datagram);
    }
}

Server::~Server() {
    delete SOCKET;
}
