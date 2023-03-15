#pragma once
#include "BUS.h"

Bus bus = Bus();

class PC {
public:
	void tick() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        switch (byte) {
        case 0x00:NOP();break; case 0xE0:WRM();break;
        case 0xE1:WMP();break; case 0xE2:WRR();break;
        case 0xE4:WR(0);break; case 0xE5:WR(1);break;
        case 0xE6:WR(2);break; case 0xE7:WR(3);break;
        case 0xE8:SBM();break; case 0xE9:RDM();break;
        case 0xEA:RDR();break; case 0xEB:ADM();break;
        case 0xEC:RD(0);break; case 0xED:RD(0);break;
        case 0xEE:RD(0);break; case 0xEF:RD(0);break;
        case 0xF0:CLB();break; case 0xF1:CLC();break;
        case 0xF2:IAC();break; case 0xF3:CMC();break;
        case 0xF4:CMA();break; case 0xF5:RAL();break;
        case 0xF6:RAR();break; case 0xF7:TCC();break;
        case 0xF8:DAC();break; case 0xF9:TCS();break;
        case 0xFA:STC();break; case 0xFB:DAA();break;
        case 0xFC:KBP();break; case 0xFD:DCL();break;
        default:
            int hbyte = (byte & 0b11110000) >> 4;
            int hdbyte = (byte & 0b11110001);

            switch (hbyte) {
            case 0x1:JCN();break;
            case 0x4:JUN();break;
            case 0x5:JMS();break;
            case 0x6:INC();break;
            case 0x7:JSZ();break;
            case 0x8:ADD();break;
            case 0x9:SUB();break;
            case 0xA:LD(); break;
            case 0xB:XCH();break;
            case 0xC:BBL();break;
            case 0xD:LDM();break;
            }

            switch (hdbyte) {
            case 0x20:
                FIM();
                break;
            case 0x21:
                SRC();
                break;
            case 0x30:
                FIN();
                break;
            }
        }
        bus.cpu.CM_ROM++;
	}
    int switchPare(int pare) {
        int a = 0;
        switch (pare) {
        case 0:a = bus.cpu.registers[0] * 0b10000 + bus.cpu.registers[1];break;
        case 1:a = bus.cpu.registers[2] * 0b10000 + bus.cpu.registers[3];break;
        case 2:a = bus.cpu.registers[4] * 0b10000 + bus.cpu.registers[5];break;
        case 3:a = bus.cpu.registers[6] * 0b10000 + bus.cpu.registers[7];break;
        case 4:a = bus.cpu.registers[8] * 0b10000 + bus.cpu.registers[9];break;
        case 5:a = bus.cpu.registers[10] * 0b10000 + bus.cpu.registers[11];break;
        case 6:a = bus.cpu.registers[12] * 0b10000 + bus.cpu.registers[13];break;
        case 7:a = bus.cpu.registers[14] * 0b10000 + bus.cpu.registers[15];break;
        }
        return a;
    }
    void NOP() {
        //здесь очевидно ничего недолжно быть
    }
    void WRM() {
        int Bank = bus.cpu.Bank;
        int pare = bus.cpu.Src;
        int chip, reg, pos;
        int i = switchPare(pare);

        chip = (i & 0b11000000) >> 6;
        reg = (i & 0b00110000) >> 4;
        pos = (i & 0b00001111) >> 0;

        bus.ram.data[reg][pos] = bus.cpu.A;
    }
    void WMP() {
        int Bank = bus.cpu.Bank;
        int pare = bus.cpu.Src;
        int i = switchPare(pare);
        int chip;

        chip = (i & 0b11110000) >> 4;

        bus.ram.IO_PORT = bus.cpu.A;
    }
    void WRR() {
        int Bank = bus.cpu.Bank;
        int pare = bus.cpu.Src;
        int i = switchPare(pare);
        int chip;

        chip = (i & 0b11110000) >> 4;

        bus.rom.IO_PORT = bus.cpu.A;
    }
    void WR(int num) {
        int Bank = bus.cpu.Bank;
        int pare = bus.cpu.Src;
        int i = switchPare(pare);
        int chip,reg;

        chip = (i & 0b11000000) >> 6;
        reg = (i & 0b00110000) >> 4;

        bus.ram.data[reg][num] = bus.cpu.A;
    }
    void SBM() {
        int Bank = bus.cpu.Bank;
        int pare = bus.cpu.Src;
        int i = switchPare(pare);
        int chip, reg, pos;

        chip = (i & 0b11000000) >> 6;
        reg = (i & 0b00110000) >> 4;
        pos = (i & 0b00001111) >> 0;

        int data = bus.ram.data[reg][pos];

        data -= bus.cpu.A;

        if (bus.cpu.Carry) {
            data--;
        }

        if ( data > 0 ) {
            bus.cpu.Carry = true;
        }
        else {
            bus.cpu.Carry = false;
            data = 16 + data;
        }

        bus.cpu.A = data;
    }
    void RDM() {
        int Bank = bus.cpu.Bank;
        int pare = bus.cpu.Src;
        int chip, reg, pos;
        int i = switchPare(pare);

        chip = (i & 0b11000000) >> 6;
        reg = (i & 0b00110000) >> 4;
        pos = (i & 0b00001111) >> 0;

        bus.cpu.A = bus.ram.data[reg][pos];
    }
    void RDR(){
        int Bank = bus.cpu.Bank;
        int pare = bus.cpu.Src;
        int i = switchPare(pare);
        int chip;

        chip = (i & 0b11110000) >> 4;

        bus.cpu.A = bus.rom.IO_PORT;
    }
    void ADM() {
        int Bank = bus.cpu.Bank;
        int pare = bus.cpu.Src;
        int i = switchPare(pare);
        int chip, reg, pos;

        chip = (i & 0b11000000) >> 6;
        reg = (i & 0b00110000) >> 4;
        pos = (i & 0b00001111) >> 0;

        int data = bus.ram.data[reg][pos];

        data += bus.cpu.A;

        if (bus.cpu.Carry) {
            data++;
            bus.cpu.Carry = false;
        }

        if (data > 0xf) {
            bus.cpu.Carry = true;
            data = data - 0xf;
        }

        bus.cpu.A = data;
    }
    void RD(int num) {
        int Bank = bus.cpu.Bank;
        int pare = bus.cpu.Src;
        int i = switchPare(pare);
        int chip, reg;

        chip = (i & 0b11000000) >> 6;
        reg = (i & 0b00110000) >> 4;

        bus.cpu.A = bus.ram.data[reg][num];
    }
    void CLB() {
        bus.cpu.A = 0;
        bus.cpu.Carry = false;
    }
    void CLC() {
        bus.cpu.Carry = false;
    }
    void IAC() {
        bus.cpu.A++;

        if (bus.cpu.A > 0xF) {
            bus.cpu.A -= 0xF;
            bus.cpu.Carry = true;
        }
    }
    void CMC() {
        if (bus.cpu.Carry) {
            bus.cpu.Carry = false;
        }
        else {
            bus.cpu.Carry = true;
        }
    }
    void CMA() {
        bus.cpu.A = ~bus.cpu.A;
    }
    void RAL() {
        int c = (int)bus.cpu.Carry;
        int i = (bus.cpu.A & 0b1000) >> 3;

        bus.cpu.Carry = (bool)i;
        bus.cpu.A = bus.cpu.A << 1;
        bus.cpu.A += c;
    }
    void RAR() {
        int c = (int)bus.cpu.Carry << 3;
        int i = (bus.cpu.A & 0b0001);

        bus.cpu.Carry = (bool)i;
        bus.cpu.A = bus.cpu.A >> 1;
        bus.cpu.A += c;
    }
    void TCC() {
        bus.cpu.A = 0;

        bus.cpu.A = (int)bus.cpu.Carry;

        bus.cpu.Carry = false;
    }
    void DAC() {
        bus.cpu.A--;

        if (bus.cpu.A < 0) {
            bus.cpu.A = 0xF;
        }
    }
    void TCS() {
        if (!bus.cpu.Carry) {
            bus.cpu.A = 9;
        }
        else{
            bus.cpu.A = 10;
        }
        bus.cpu.Carry = 0;
    }
    void STC() {
        bus.cpu.Carry = true;
    }
    void DAA() {
        bus.cpu.A = bus.cpu.A + (0b0000 | 0b0110);
    }
    void KBP() {
        if (bus.cpu.A > 0b0100) {
            bus.cpu.A = 0xF;
        }
        else{}
    }
    void DCL() {
        int i = bus.cpu.A & 0b0111;
        bus.cpu.Bank = i;
    }
    void JCN() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = byte & 0b00001111;
        bus.cpu.CM_ROM++;
        byte = bus.rom.data[bus.cpu.CM_ROM];
        bool c0 = (c & 0b1000) >> 3;
        bool c1 = (c & 0b0100) >> 2;
        bool c2 = (c & 0b0010) >> 1;
        bool c3 = (c & 0b0001);
        if (c0) {
            if (c1 && bus.cpu.A != 0) {
                bus.cpu.CM_ROM = byte - 1;
            }
            else if (c2 && bus.cpu.Carry != true) {
                bus.cpu.CM_ROM = byte - 1;
            }
            else if (c3 && bus.cpu.Test != false) {
                bus.cpu.CM_ROM = byte - 1;
            }
        }
        else {
            if (c1 && bus.cpu.A == 0) {
                bus.cpu.CM_ROM = byte - 1;
            }
            else if (c2 && bus.cpu.Carry == true) {
                bus.cpu.CM_ROM = byte - 1;
            }
            else if (c3 && bus.cpu.Test == false) {
                bus.cpu.CM_ROM = byte - 1;
            }
        }
    }
    void JUN() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = byte & 0b00001111;
        bus.cpu.CM_ROM++;
        byte = bus.rom.data[bus.cpu.CM_ROM];
        byte += c * 0b100000000;
        bus.cpu.CM_ROM = byte-1;
    }
    void JMS() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = byte & 0b00001111;
        bus.cpu.CM_ROM++;
        byte = bus.rom.data[bus.cpu.CM_ROM];
        byte += c * 0b100000000;
        bus.cpu.CM_ROM = byte - 1;
        bus.cpu.Stack[bus.cpu.StackPointer] = bus.cpu.CM_ROM + 1;
    }
    void INC() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = byte & 0b00001111;
        bus.cpu.registers[c]++;
        if (bus.cpu.registers[c] > 0xF) {
            bus.cpu.registers[c] = 0;
        }
    }
    void JSZ() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = byte & 0b00001111;
        bus.cpu.registers[c]++;
        if (bus.cpu.registers[c] > 0xF) {
            bus.cpu.registers[c] = 0;
            bus.cpu.CM_ROM++;
            byte = bus.rom.data[bus.cpu.CM_ROM];
            bus.cpu.CM_ROM = byte - 1;
        }
        else {
            bus.cpu.CM_ROM++;
        }
    }
    void ADD() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = byte & 0b00001111;
        bus.cpu.A += bus.cpu.registers[c];
        if (bus.cpu.A > 0xF) {
            bus.cpu.A = 0;
            bus.cpu.Carry = true;
        }
    }
    void SUB() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = byte & 0b00001111;
        bus.cpu.A += bus.cpu.registers[c];
        if (bus.cpu.A < 0x0) {
            bus.cpu.A = 16 + bus.cpu.A;
        }
        else {
            bus.cpu.Carry = true;
        }
    }
    void LD() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = byte & 0b00001111;
        bus.cpu.A = bus.cpu.registers[c];
    }
    void XCH() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = byte & 0b00001111;
        int a = bus.cpu.A;
        bus.cpu.A = bus.cpu.registers[c];
        bus.cpu.registers[c] = a;
    }
    void BBL() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = byte & 0b00001111;
        bus.cpu.A = c;
        
        bus.cpu.CM_ROM = bus.cpu.Stack[bus.cpu.StackPointer];

        bus.cpu.Stack[bus.cpu.StackPointer] = 0;
        bus.cpu.StackPointer--;
    }
    void LDM() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = byte & 0b00001111;
        bus.cpu.A = c;
    }
    void FIM() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = (byte & 0b00001110) >> 1;

        bus.cpu.CM_ROM++;

        byte = bus.rom.data[bus.cpu.CM_ROM];
        short byte1, byte2;
        byte1 = (byte & 0b11110000) >> 4;
        byte2 = (byte & 0b00001111);

        //set pair

        switch (c) {
        case 0:
            bus.cpu.registers[0] = byte1;
            bus.cpu.registers[1] = byte2;
            break;
        case 1:
            bus.cpu.registers[2] = byte1;
            bus.cpu.registers[3] = byte2;
            break;
        case 2:
            bus.cpu.registers[4] = byte1;
            bus.cpu.registers[5] = byte2;
            break;
        case 3:
            bus.cpu.registers[6] = byte1;
            bus.cpu.registers[7] = byte2;
            break;
        case 4:
            bus.cpu.registers[8] = byte1;
            bus.cpu.registers[9] = byte2;
            break;
        case 5:
            bus.cpu.registers[10] = byte1;
            bus.cpu.registers[11] = byte2;
            break;
        case 6:
            bus.cpu.registers[12] = byte1;
            bus.cpu.registers[13] = byte2;
            break;
        case 7:
            bus.cpu.registers[14] = byte1;
            bus.cpu.registers[15] = byte2;
            break;
        }
    }
    void SRC() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = (byte & 0b00001110) >> 1;

        bus.cpu.Src = c;
    }
    void FIN() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = (byte & 0b00001110) >> 1;

        short byte1, byte2;

        byte1 = 3;
        byte2 = (c << 1) + 0;

        //serch pair

        switch (c) {
        case 0:
            bus.cpu.registers[0] = byte1;
            bus.cpu.registers[1] = byte2;
            break;
        case 1:
            bus.cpu.registers[2] = byte1;
            bus.cpu.registers[3] = byte2;
            break;
        case 2:
            bus.cpu.registers[4] = byte1;
            bus.cpu.registers[5] = byte2;
            break;
        case 3:
            bus.cpu.registers[6] = byte1;
            bus.cpu.registers[7] = byte2;
            break;
        case 4:
            bus.cpu.registers[8] = byte1;
            bus.cpu.registers[9] = byte2;
            break;
        case 5:
            bus.cpu.registers[10] = byte1;
            bus.cpu.registers[11] = byte2;
            break;
        case 6:
            bus.cpu.registers[12] = byte1;
            bus.cpu.registers[13] = byte2;
            break;
        case 7:
            bus.cpu.registers[14] = byte1;
            bus.cpu.registers[15] = byte2;
            break;
        }
    }
    void JIN() {
        short byte = bus.rom.data[bus.cpu.CM_ROM];
        short c = (byte & 0b00001110) >> 1;

        byte = switchPare(c);

        bus.cpu.CM_ROM = byte;
    }
};