#ifndef INI_H
#define INI_H

#include <QSettings>
#include <QDebug>

#define BASIC_INT_PATH    "./basic.ini"
#define BASIC_SERVER_ADDRESS    "Basic/address"
#define BASIC_PORT  "Basic/port"
#define BASIC_AUTO_ENABLE "Basic/autoEnable"
#define BASIC_RESOLUTION_INDEX  "Basic/index"

class Ini
{
public:
    Ini();
    static bool WriteBasicIni(QString serverAddr, int port, bool autoEnable, int resolutionIndex);
    static bool ReadBasicIni(QString & serverAddr, int  & port);
    static bool ReadBasicIni(QString & serverAddr, int  & port, bool & autoEnable, int & resolutionIndex);
};

#endif // INI_H
