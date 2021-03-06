#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

    void initSocket(int port);
    void readPendingDatagrams();

private:
    QUdpSocket* SOCKET;

};

#endif // SERVER_H
