#include "ini.h"

Ini::Ini()
{

}

bool Ini::WriteBasicIni(QString serverAddr, int port, bool autoEnable, int resolutionIndex)
{
    try
    {
        QSettings settings(BASIC_INT_PATH, QSettings::IniFormat);

        settings.setValue(BASIC_SERVER_ADDRESS, serverAddr);
        settings.setValue(BASIC_PORT, port);
        settings.setValue(BASIC_AUTO_ENABLE, autoEnable);
        settings.setValue(BASIC_RESOLUTION_INDEX, resolutionIndex);

        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool Ini::ReadBasicIni(QString & serverAddr, int  & port)
{
    serverAddr = QString::null;
    port = 0;

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

bool Ini::ReadBasicIni(QString & serverAddr, int  & port, bool & autoEnable, int & resolutionIndex)
{
    serverAddr = QString::null;
    port = 0;
    autoEnable = false;
    resolutionIndex = 0;

    try
    {
        QSettings settings(BASIC_INT_PATH, QSettings::IniFormat);

        serverAddr = settings.value(BASIC_SERVER_ADDRESS).toString();
        port = settings.value(BASIC_PORT).toInt();
        autoEnable = settings.value(BASIC_AUTO_ENABLE).toBool();
        resolutionIndex = settings.value(BASIC_RESOLUTION_INDEX).toInt();
        //qDebug()<<serverAddr<<port<<autoEnable<<resolutionIndex;

        return true;
    }
    catch (...)
    {
        return false;
    }
}
