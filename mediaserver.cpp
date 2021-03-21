#include "mediaserver.h"
#include <iostream>

MediaServer::MediaServer(QObject *parent) : QObject(parent) {}


MediaServer::~MediaServer()
{
    delete SOCKET;
}


void MediaServer::initSocket(int port)
{
    SOCKET = new QUdpSocket(this);
    bool connected = SOCKET->bind(QHostAddress::Any, port);

    connect(SOCKET, SIGNAL(readyRead()), this, SLOT(readmsg()));

    std::cout << (connected ? "Server started." : "ERROR: Could not start server.") << std::endl;
}

void MediaServer::readmsg()
{
    // Creates and resizes the buffer to
    // the size of the incoming datagram.
    QByteArray buffer;
    QHostAddress sender_addr;
    quint16 sender_port;

    buffer.resize(SOCKET->pendingDatagramSize());

    // reads the datagram to the buffer.
    SOCKET->readDatagram(buffer.data(), buffer.size(), &sender_addr, &sender_port);

    QString data = sender_addr.toString();
    std::cout << "Message from " << data.toStdString() << ":" << sender_port << " -> " << buffer.data() << std::endl;

    // Notifies the client that the message has been received.
    QByteArray clientData;
    clientData.append("Message received.");
    SOCKET->writeDatagram(clientData, QHostAddress::LocalHost, sender_port);
}
