#ifndef INI_H
#define INI_H

#include <QObject>

#include <QSettings>
#include <QDebug>

#define BASIC_INT_PATH    "./basic.ini"
#define BASIC_SERVER_ADDRESS    "Basic/address"
#define BASIC_PORT  "Basic/port"
#define BASIC_AUTO_ENABLE "Basic/autoEnable"
#define BASIC_RESOLUTION_INDEX  "Basic/index"


class Ini : public QObject
{
    Q_OBJECT
public:
    explicit Ini(QObject *parent = 0);
    bool WriteBasicIni(QString serverAddr, int port, bool autoEnable);
    bool ReadBasicIni(QString & serverAddr, int  & port);
    bool ReadBasicIni(QString & serverAddr, int  & port, bool & autoEnable);

signals:
    void WriteBasicIniFinish();
public slots:
};

#endif // INI_H
