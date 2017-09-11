#ifndef HTTPS_H
#define HTTPS_H

#include <QtNetwork>
#include "xml.h"

#define URL "https://192.168.110.222/ovirt-engine/api/vms"

class Https
{
public:
    Https();
    Https(QString url, QString username, QString password);
private:
    QString xmlText;
    QNetworkAccessManager * manager;
    QSslConfiguration sslConfig;
    QList vmList;
private slots:
    void slot_ReplyFinished(QNetworkReply * reply);
    void SslInit();
};

#endif // HTTPS_H
