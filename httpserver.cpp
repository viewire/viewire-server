#include "httpserver.h"
#include "QtCore"
#include "qhttpengine/server.h"
#include "qhttpengine/filesystemhandler.h"

httpserver::httpserver()
{
    QHttpEngine::Server server;
    server.listen(QHostAddress::Any, 7726);

    QHttpEngine::FilesystemHandler handler("/testweb");
    server.setHandler(&handler);
}
