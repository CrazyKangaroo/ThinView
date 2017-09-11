#include "vmdata.h"

VmData::VmData()
{
    id = NULL;
    name = NULL;
    os = NULL;
    state = VmState::DOWN;
    vCpu = 0;
    memory = 0;
    address = NULL;
    usbEnable = NULL;
}
