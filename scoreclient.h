#ifndef SCORECLIENT_H
#define SCORECLIENT_H

#include <QString>
#include <QTcpSocket>

class ScoreClient
{
private:
    QString host;
    int port;
    QTcpSocket sock;
public:
    ScoreClient(QString host, int port);
};

#endif // SCORECLIENT_H
