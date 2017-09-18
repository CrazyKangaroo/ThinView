#ifndef INI_H
#define INI_H

#include <QSettings>

#define BASIC_INT_PATH    "./basic.ini"
#define BASIC_SERVER_ADDRESS    "Basic/address"
#define BASIC_PORT  "Basic/port"

class Ini
{
public:
    Ini();
    static bool WriteBasicIni();
    static bool ReadBasicIni(QString & serverAddr, int  & port);
};

#endif // INI_H
