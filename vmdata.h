#ifndef VMDATA_H
#define VMDATA_H

#include <QString>



class VmData
{
public:
    VmData();
    enum VmState
    {
        DOWN = 0,
        UP,
    };
    enum UsbPolicy
    {
        Enable = 0,
        Disable,
    };
    QString id;
    QString name;
    QString os;
    VmState state;
    int vCpu;
    unsigned int memory;
    QString address;
    UsbPolicy usbEnable;
};

#endif // VMDATA_H
