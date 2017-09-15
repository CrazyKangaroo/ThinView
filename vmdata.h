#ifndef VMDATA_H
#define VMDATA_H

#include <QString>

enum VmState
{
    DOWN = 0,
    UP,
};

class VmData
{
public:
    VmData();

    QString id;
    QString name;
    QString os;
    VmState state;
    int vCpu;
    unsigned int memory;
    QString address;
    QString usbEnable;
};

#endif // VMDATA_H
