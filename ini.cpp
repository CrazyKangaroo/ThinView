#include "ini.h"

Ini::Ini()
{

}

bool Ini::WriteBasicIni()
{

}

bool Ini::ReadBasicIni(QString & serverAddr, int  & port)
{
    try
    {
        QSettings settings(BASIC_INT_PATH, QSettings::IniFormat);

        serverAddr = settings.value(BASIC_SERVER_ADDRESS).toString();
        port = settings.value(BASIC_PORT).toInt();

        //qDebug()<<serverAddr<<port;

        return true;
    }
    catch (...)
    {
        return false;
    }
}
