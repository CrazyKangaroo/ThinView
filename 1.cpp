#include "vmdata.h"
#include <QObject>

VmData::VmData()
{
    id = "";
    name = "";
    os = "";
    state = VmState::DOWN;
    vCpu = 0;
    memory = 0;
    address = "";
    usbEnable = "";
}
