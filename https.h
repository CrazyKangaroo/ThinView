#ifndef HTTPS_H
#define HTTPS_H

#include <QtNetwork>
#include "xml.h"
#include <QObject>
#include "vmdata.h"

#define URL "https://192.168.110.254/ovirt-engine/api/vms"
#define USERNAME "admin@internal"
#define PASSWORD "shencloud"

class Https : public QObject
{
    Q_OBJECT
public:
    explicit Https(QObject *parent = 0);
    void HttpInit(QString url, QString username, QString password);
private:
    QString xmlText;
    QNetworkAccessManager * manager;
    QSslConfiguration sslConfig;
    QList<VmData> vmList;
    void SslInit();
signals:
    void SendVmList(QList<VmData> &);
public slots:
    void slot_ReplyFinished(QNetworkReply * reply);
};

#endif // HTTPS_H
