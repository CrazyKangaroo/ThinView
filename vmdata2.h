#ifndef VMDATA_H
#define VMDATA_H

//#include <QObject>

//class VmData : public QObject
//{
//    Q_OBJECT
//public:
//    VmData(QObject *parent = 0);
//    enum VmState
//    {
//        DOWN = 0,
//        UP,
//    };
//    Q_ENUM(VmState)
//    QString id;
//    QString name;
//    QString os;
//    VmState state;
//    int vCpu;
//    unsigned int memory;
//    QString address;
//    QString usbEnable;

//signals:

//public slots:
//};

class VmData
{
public:
    VmData();
    ~VmData();
    enum VmState
    {
        DOWN = 0,
        UP
    };
public:
    QString name;
    QString os;
    int vCpu;
    int memory;
    QString address;
    int usbEnable;
    VmState state;
};

#endif // VMDATA_H
