#ifndef MEDIASERVER_H
#define MEDIASERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>

class MediaServer : public QObject
{
    Q_OBJECT
public:
    explicit MediaServer(QObject *parent = nullptr);
    ~MediaServer();

    void initSocket(int port);
    void readPendingDatagrams();


private:
    QUdpSocket* SOCKET;
    void sendMessage(QString& data, QHostAddress& addr, quint16 port);


private slots:
    void readmsg();

};

#endif // MEDIASERVER_H
