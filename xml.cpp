#include "xml.h"

XML::XML()
{

}

QList<VmData> XML::ParseXML(QString xmlText)
{
    this->xmlText = xmlText;

    vmList = new QList<VmData>();
    QXmlStreamReader reader(xmlText);
    while (!reader.atEnd())
    {
        QXmlStreamReader::TokenType nType = reader.readNext();

        switch (nType)
        {
            case QXmlStreamReader::StartDocument:
            {
                QString strVersion = reader.documentVersion().toString();
                QString strEncoding = reader.documentEncoding().toString();
                bool bAlone = reader.isStandaloneDocument();
                qDebug()<<"strVersion:"<<strVersion<<"strEncoding:"<<strEncoding<<"bAlone"<<bAlone;
            }
            break;
            case QXmlStreamReader::Comment:
            {
                QString strComment = reader.text().toString();
                qDebug()<<"strComment:"<<strComment;
            }
            break;
            case QXmlStreamReader::ProcessingInstruction:
            {
                QString strProcInstr = reader.processingInstructionData().toString();
                qDebug()<<"strProcInstr"<<strProcInstr;
            }
            break;
            case QXmlStreamReader::DTD:
            {
                QString strDTD = reader.text().toString();
                //QXmlStreamNotationDeclarations notationDeclarations = reader.notationDeclarations();
                //QXmlStreamEntityDeclarations entityDeclarations = reader.entityDeclarations();

                QString strDTDName = reader.dtdName().toString();
                QString strDTDPublicId = reader.dtdPublicId().toString();
                QString strDTDSystemId = reader.dtdSystemId().toString();

                qDebug()<<"DTD:"<<strDTD;
                qDebug()<<"DTD name:"<<strDTDName;
                qDebug()<<"DTD PublicId:"<<strDTDPublicId;
                qDebug()<<"DTD SystemId:"<<strDTDSystemId<<"\n";
            }
            break;
        case QXmlStreamReader::StartElement:
        {
            QString strElementName = reader.name().toString();
            if (strElementName == "vms")
            {
                ParseStartElement(reader, vmList);
            }
        }
        break;
        case QXmlStreamReader::EndDocument:
        {
            qDebug()<<"end";
        }
        break;
        }
    }

    return vmList;
}

void XML::ParseStartElement(QXmlStreamReader &reader, QList<VmData> &vmList)
{
    while (!reader.atEnd())
    {
        reader.readNext();
        if (reader.isStartElement())
        {
            QString strElementName = reader.name().toString();
            if (strElementName == "vm")
            {
                QXmlStreamAttributes attributes = reader.attributes();
                if (attributes.hasAttribute("id"))
                {
                    tempVmData = new VmData;
                    QString strId = attributes.value("id").toString();
                    tempVmData.id = strId;
                    //qDebug()<<"strId:"<<strId;
                }
            }
            else if (strElementName == "name")
            {
                //qDebug()<<"name:"<<reader.readElementText();
                tempVmData.name = reader.readElementText();
            }
            else if (strElementName == "topology")
            {
                QXmlStreamAttributes attributes = reader.attributes();
                if (attributes.hasAttribute("sockets"))
                {
                    int nSocket = attributes.value("sockets").toInt();
                    tempVmData.vCpu = nSocket;
                    //qDebug()<<"strSocket:"<<strSocket;
                }
            }
            else if (strElementName == "os")
            {
                QXmlStreamAttributes attributes = reader.attributes();
                if (attributes.hasAttribute("type"))
                {
                    QString strType = attributes.value("type").toString();
                    //qDebug()<<"os type:"<<strSocket;
                    tempVmData.os = strType;
                }
            }
            else if (strElementName == "state")
            {
                //qDebug()<<"state:"<<reader.readElementText();
                QString strState = reader.readElementText();
                if (strState.toUpper() == VmState::DOWN)
                {
                    tempVmData.state = VmState::DOWN;
                }
                else if (strState.toUpper() == VmState::UP)
                {
                    tempVmData.state = VmState::UP;
                }
            }
            else if (strElementName == "memory")
            {
                //qDebug()<<"memory:"<<reader.readElementText();
                unsigned int memory = reader.readElementText().toUInt();
                tempVmData.memory = memory / (1024 * 1024 * 1024);
            }
            else if (strElementName == "usb")
            {
                reader.readNextStartElement();
                QString strElementName = reader.name().toString();
                if (strElementName == "enabled")
                {
                    //qDebug()<<"usb enabled:"<<reader.readElementText();
                    tempVmData.usbEnable = reader.readElementText();
                    vmList.append(tempVmData);
                }
            }
            else if (strElementName == "address")
            {
                //qDebug()<<"address:"<<reader.readElementText();
                tempVmData.address = reader.readElementText();
            }
            /*
            else if (strElementName == "port")
            {
                qDebug()<<"port:"<<reader.readElementText();
            }*/
        }
    }
}
