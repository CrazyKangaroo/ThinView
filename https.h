#ifndef HTTPS_H
#define HTTPS_H

#include <QtNetwork>
#include "xml.h"
#include <QObject>
#include "vmdata.h"

#define URL "https://192.168.110.254:443/ovirt-engine/api/vms"
#define HEAD "https://"
#define PORT 443
#define POSTFIX  "/ovirt-engine/api/vms"
#define USERNAME "admin@internal"
#define PASSWORD "shencloud"

class Https : public QObject
{
    Q_OBJECT
public:
    explicit Https(QObject *parent = 0);
    //void HttpInit(QString url, QString username, QString password);
    void HttpInit(QString serverAddr = 0, int port = 0, QString userName = 0, QString passWord = 0);
private:
    QString serverAddr;
    int port;
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
