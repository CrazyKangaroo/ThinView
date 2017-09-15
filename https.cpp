#include "https.h"

Https::Https(QObject *parent) : QObject(parent)
{

}

void Https::HttpInit(QString url, QString username, QString password)
{
    SslInit();
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(slot_ReplyFinished(QNetworkReply *)));

    QByteArray text((username + ":" + password).toUtf8());
    QNetworkRequest request;
    request.setUrl(url);
    request.setSslConfiguration(sslConfig);
    request.setRawHeader("filter", "false");
    //request.setRawHeader("Prefer", "persistent-auth");
    //request.setRawHeader("Connection", "close");
    request.setRawHeader("Authorization", "Basic " + text.toBase64());
    manager->get(request);
}

void Https::SslInit()
{
    sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    sslConfig.setProtocol(QSsl::TlsV1_2);
}

void Https::slot_ReplyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QTextCodec * pCodec = QTextCodec::codecForName("utf8");
        xmlText = pCodec->toUnicode(reply->readAll());
        reply->deleteLater();
        XML xml;
        vmList = xml.ParseXML(xmlText);

        /*
        for (int i = 0; i < vmList.size(); i++)
        {
            qDebug()<<vmList[i].name<<"#"<<vmList[i].os<<"#" \
                    <<vmList[i].state<<"#"<<vmList[i].vCpu<<"#" \
                    <<vmList[i].memory<<"#"<<vmList[i].address<<"#" \
                    <<vmList[i].usbEnable;
        }*/
        emit SendVmList(vmList);
    }
    else
    {
        qDebug()<<"handle errors here";
        QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        qDebug("found error .... code: %d %d", statusCodeV.toInt(), (int)reply->error());
    }
}
