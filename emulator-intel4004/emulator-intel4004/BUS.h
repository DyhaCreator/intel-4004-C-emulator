#pragma once
#include "CPU.h"
#include "RAM.h"
#include "ROM.h"

class Bus {
public:
    short bus = 0;
    CPU cpu = CPU();
    ROM4001 rom = ROM4001();
    RAM4002 ram = RAM4002();
};