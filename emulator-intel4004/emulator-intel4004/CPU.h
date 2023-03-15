#pragma once
class CPU {
public:
    short registers[16] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    short A = 0;
    int Cycles = 0;
    short PC[3] = { 0,0,0 };
    short StackPointer = 0;
    short Stack[3] = {
        0, 0, 0 
    };
    bool Carry = false;
    bool Test = false;
    bool Sync = false;
    short CM_ROM = 0;
    short Bank = 0;
    short Src = 0;

    void reset() {
        for (int i = 0; i < 16; i++) {
            this->registers[i] = 0;
        }
        this->A = 0;
        this->Cycles = 0;
        short StackPointer = 0;
        for (int i = 0; i < 3; i++) {
            this->PC[i] = 0;
            this->Stack[i] = 0;
        }
        this->Carry = false;
        this->Test = false;
        this->Sync = false;
    }
};