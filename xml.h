#ifndef XML_H
#define XML_H

#include <QXmlStreamReader>
#include "vmdata.h"
#include <QDebug>

class XML
{
public:
    XML();
    QList<VmData> ParseXML(QString xmlText);
private:
    VmData * tempVmData;
    QList<VmData> vmList;
    QString xmlText;
    void ParseStartElement(QXmlStreamReader &reader, QList<VmData> &vmList);
};

#endif // XML_H
