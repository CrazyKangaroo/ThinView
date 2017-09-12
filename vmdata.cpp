#include "vmdata.h"

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
