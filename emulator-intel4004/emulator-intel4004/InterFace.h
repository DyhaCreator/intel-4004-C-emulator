#pragma once
#include "ROM.h"
#include "RAM.h"
#include "CPU.h"
#include "Disassembly.h"

class InterFace {
public:
	ROM4001 rom;
	RAM4002 ram;
	CPU cpu;
	Disassembly dis = Disassembly(rom);

	InterFace(ROM4001 rom, RAM4002 ram, CPU cpu) {
		this->rom = rom;
		this->ram = ram;
		this->cpu = cpu;
		dis = Disassembly(rom);
	}

	void draw() {
		system("cls");

		int i = cpu.CM_ROM;

		cout << "|---------------------------------------------------------|-----------------|";																			cout << "-----------------" << endl;
		cout << "| RAM 4002                                                | FLAGS           |";																			cout << " DISASMEMBLER    " << endl;
		cout << "| $"; drawRamStr(0x00);                          cout << "| CARRY > " << cpu.Carry << "       |";															cout << " " << dis.disasm(i + 0) << endl;
		cout << "| $"; drawRamStr(0x01);                          cout << "| TEST  > " << cpu.Test << "       |";					 										cout << " " << dis.disasm(i + 1) << endl;
		cout << "| $"; drawRamStr(0x02);                          cout << "|-----------------|";																			cout << " " << dis.disasm(i + 2) << endl;
		cout << "| $"; drawRamStr(0x03);                          cout << "| REGISTERS       |";																			cout << " " << dis.disasm(i + 3) << endl;
		cout << "|---------------------------------------------------------| R0  > " << hex << cpu.registers[0] << " " << "R1  > " << hex << cpu.registers[1] << " |";		cout << " " << dis.disasm(i + 4) << endl;
		cout << "| ROM 4001                                                | R2  > " << hex << cpu.registers[2] << " " << "R3  > " << hex << cpu.registers[3] << " |";		cout << " " << dis.disasm(i + 5) << endl;
		cout << "| $"; drawRomStr(0x00);                       cout << "   | R4  > " << hex << cpu.registers[4] << " " << "R5  > " << hex << cpu.registers[5] << " |";		cout << " " << dis.disasm(i + 6) << endl;
		cout << "| $"; drawRomStr(0x01);                       cout << "   | R6  > " << hex << cpu.registers[6] << " " << "R7  > " << hex << cpu.registers[7] << " |";		cout << " " << dis.disasm(i + 7) << endl;
		cout << "| $"; drawRomStr(0x02);                       cout << "   | R8  > " << hex << cpu.registers[8] << " " << "R9  > " << hex << cpu.registers[9] << " |";		cout << " " << dis.disasm(i + 8) << endl;
		cout << "| $"; drawRomStr(0x03);                       cout << "   | R10 > " << hex << cpu.registers[10] << " " << "R11 > " << hex << cpu.registers[11] << " |";	cout << " " << dis.disasm(i + 9) << endl;
		cout << "| $"; drawRomStr(0x04);                       cout << "   | R12 > " << hex << cpu.registers[12] << " " << "R13 > " << hex << cpu.registers[13] << " |";	cout << " " << dis.disasm(i + 10) << endl;
		cout << "| $"; drawRomStr(0x05);                       cout << "   | R14 > " << hex << cpu.registers[14] << " " << "R15 > " << hex << cpu.registers[15] << " |";	cout << " " << dis.disasm(i + 11) << endl;
		cout << "| $"; drawRomStr(0x06);                       cout << "   | ACC > " << hex << cpu.A << "         |";														cout << " " << dis.disasm(i + 12) << endl;
		cout << "| $"; drawRomStr(0x07);                       cout << "   |-----------------|";																			cout << " " << dis.disasm(i + 13) << endl;
		cout << "| $"; drawRomStr(0x08);                       cout << "   | STACK           |";																			cout << " " << dis.disasm(i + 14) << endl;
		cout << "| $"; drawRomStr(0x09);                       cout << "   | PC   > " << hex << cpu.CM_ROM << "        |";													cout << " " << dis.disasm(i + 15) << endl;
		cout << "| $"; drawRomStr(0x0A);                       cout << "   | LVL0 > " << hex << cpu.Stack[0] << "        |";												cout << " " << dis.disasm(i + 16) << endl;
		cout << "| $"; drawRomStr(0x0B);                       cout << "   | LVL1 > " << hex << cpu.Stack[1] << "        |";												cout << endl;
		cout << "| $"; drawRomStr(0x0C);                       cout << "   | LVL2 > " << hex << cpu.Stack[2] << "        |";												cout << endl;
		cout << "| $"; drawRomStr(0x0D);                       cout << "   |                 |" << endl;
		cout << "| $"; drawRomStr(0x0E);                       cout << "   |                 |" << endl;
		cout << "| $"; drawRomStr(0x0F);                       cout << "   |                 |" << endl;
		cout << "|---------------------------------------------------------|-----------------|" << endl;
	}

	void drawRom() {
		for (int y = 0; y < 16; y++) {
			cout << hex << y;
			cout << "0> ";
			for (int x = 0; x < 16; x++) {
				if (rom.data[x + (y * 0xf)] > 0xf) {
					cout << rom.data[x + (y * 0xf)] << " ";
				}
				else {
					cout << "0" << rom.data[x + (y * 0xf)] << " ";
				}
			}
			cout << endl;
		}
	}

	void drawRomStr(int num) {
		cout << hex << num;
		cout << "0> ";
		for (int x = 0; x < 16; x++) {
			if (rom.data[x + (num * 0xf)] > 0xf) {
				cout << rom.data[x + (num * 0xf)] << " ";
			}
			else {
				cout << "0" << rom.data[x + (num * 0xf)] << " ";
			}
		}
	}
	void drawRamStr(int num) {
		cout << "Register" << num << " > ";
		for (int i = 0; i < 16; i++) {
			cout << hex << ram.data[num][i] << " ";
		}
		cout << "   ";
		for (int i = 0; i < 4; i++) {
			cout << hex << ram.data[num][16 + i] << " ";
		}
	}

	void drawDisasm(int o,int d) {
		for (int i = o; i <= d; i++) {
			string a = dis.disasm(i);

			if (a.at(8) != ' ') {
				i++;
			}

			cout << a << endl;
		}
	}
};