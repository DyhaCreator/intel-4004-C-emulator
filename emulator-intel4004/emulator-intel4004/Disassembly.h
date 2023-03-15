#pragma once
#include "ROM.h"
#include <string>
#include <sstream>

using namespace std;

class Disassembly {
public:
	ROM4001 rom;

	Disassembly(ROM4001 rom) {
		this->rom = rom;
	}

	void dw() {
		cout << rom.data[0] << endl;
	}

	string disasm(int index) {
		if (index < 255) {
			short byte = rom.data[index];
			short secByte = rom.data[index + 1];
			string str, indexStr, byteStr, comand, secByteStr;


			if (index > 0xf) {
				indexStr = "";
			}
			else {
				indexStr = "0";
			}

			if (byte > 0xf) {
				byteStr = "";
			}
			else {
				byteStr = "0";
			}

			if (secByte > 0xf) {
				secByteStr = "";
			}
			else {
				secByteStr = "0";
			}

			ostringstream ss;
			ss << hex << index;
			indexStr += ss.str();

			ostringstream sb;
			sb << hex << byte;
			byteStr += sb.str();

			ostringstream sd;
			sd << hex << secByte;
			secByteStr += sd.str();

			switch (byte) {
			case 0x00:comand = "NOP"; break;
			case 0x10:comand = "JCN CN=0"; break;			case 0x11:comand = "JCN CN=1 also JNT"; break;
			case 0x12:comand = "JCN CN=2 also JC"; break;	case 0x13:comand = "JCN CN=3"; break;
			case 0x14:comand = "JCN CN=4 also JZ"; break;	case 0x15:comand = "JCN CN=5"; break;
			case 0x16:comand = "JCN CN=6"; break;			case 0x17:comand = "JCN CN=7"; break;
			case 0x18:comand = "JCN CN=8"; break;			case 0x19:comand = "JCN CN=9 also JT"; break;
			case 0x1A:comand = "JCN CN=10 also JNC"; break;	case 0x1B:comand = "JCN CN=11"; break;
			case 0x1C:comand = "JCN CN=12 also JNZ"; break;	case 0x1D:comand = "JCN CN=13"; break;
			case 0x1E:comand = "JCN CN=14"; break;			case 0x1F:comand = "JCN CN=15"; break;
			case 0x20:comand = "FIM 0"; break;				case 0x21:comand = "SRC 0"; break;
			case 0x22:comand = "FIM 2"; break;				case 0x23:comand = "SRC 2"; break;
			case 0x24:comand = "FIM 4"; break;				case 0x25:comand = "SRC 4"; break;
			case 0x26:comand = "FIM 6"; break;				case 0x27:comand = "SRC 6"; break;
			case 0x28:comand = "FIM 8"; break;				case 0x29:comand = "SRC 8"; break;
			case 0x2A:comand = "FIM 10"; break;				case 0x2B:comand = "SRC 10"; break;
			case 0x2C:comand = "FIM 12"; break;				case 0x2D:comand = "SRC 12"; break;
			case 0x2E:comand = "FIM 14"; break;				case 0x2F:comand = "SRC 14"; break;

			case 0x30:comand = "FIN 0"; break;				case 0x31:comand = "JIN 0"; break;
			case 0x32:comand = "FIN 2"; break;				case 0x33:comand = "JIN 2"; break;
			case 0x34:comand = "FIN 4"; break;				case 0x35:comand = "JIN 4"; break;
			case 0x36:comand = "FIN 6"; break;				case 0x37:comand = "JIN 6"; break;
			case 0x38:comand = "FIN 8"; break;				case 0x39:comand = "JIN 8"; break;
			case 0x3A:comand = "FIN 10"; break;				case 0x3B:comand = "JIN 10"; break;
			case 0x3C:comand = "FIN 12"; break;				case 0x3D:comand = "JIN 12"; break;
			case 0x3E:comand = "FIN 14"; break;				case 0x3F:comand = "JIN 14"; break;
			case 0xE0:comand = "WRM"; break;				case 0xE1:comand = "WMP"; break;
			case 0xE2:comand = "WRR"; break;				case 0xE3:comand = "WPM"; break;
			case 0xE4:comand = "WR0"; break;				case 0xE5:comand = "WR1"; break;
			case 0xE6:comand = "WR2"; break;				case 0xE7:comand = "WR3"; break;
			case 0xE8:comand = "SBM"; break;				case 0xE9:comand = "RDM"; break;
			case 0xEA:comand = "RDR"; break;				case 0xEB:comand = "ADM"; break;
			case 0xEC:comand = "RD0"; break;				case 0xED:comand = "RD1"; break;
			case 0xEE:comand = "RD2"; break;				case 0xEF:comand = "RD3"; break;

			case 0xF0:comand = "CLB"; break;
			case 0xF1:comand = "CLC"; break;
			case 0xF2:comand = "IAC"; break;
			case 0xF3:comand = "CMC"; break;
			case 0xF4:comand = "CMA"; break;
			case 0xF5:comand = "RAL"; break;
			case 0xF6:comand = "RAR"; break;
			case 0xF7:comand = "TCC"; break;
			case 0xF8:comand = "DAC"; break;
			case 0xF9:comand = "TCS"; break;
			case 0xFA:comand = "STC"; break;
			case 0xFB:comand = "DAA"; break;
			case 0xFC:comand = "KBP"; break;
			case 0xFD:comand = "DCL"; break;
			case 0xFE:comand = " - "; break;
			case 0xFF:comand = " - "; break;

			default:
				int b = (byte & 0b11110000) >> 4;

				int sec = (byte & 0b00001111);
				switch (b) {
				case 0x6:comand = "INC " + to_string(sec); break;
				case 0x7:comand = "ISZ " + to_string(sec); break;
				case 0x8:comand = "ADD " + to_string(sec); break;
				case 0x9:comand = "SUB " + to_string(sec); break;
				case 0xA:comand = "LD  " + to_string(sec); break;
				case 0xB:comand = "XCH " + to_string(sec); break;
				case 0xC:comand = "BBL " + to_string(sec); break;
				case 0xD:comand = "LDM " + to_string(sec); break;

				default:
					int pos = rom.data[index + 1];
					switch (b) {
					case 0x4:comand = "JUN " + to_string(pos); break;
					case 0x5:comand = "JMS " + to_string(pos); break;
					}
				}
			}

			string com = comand.substr(0,3);

			//cout << byteStr << endl;
			//cout << secByteStr << endl;

			if (com == "JCN" ||
				com == "FIM" ||
				com == "JUN" ||
				com == "JMS" ||
				com == "ISZ") {
				str = indexStr + "> " + byteStr + " " + secByteStr + " " + comand;
			}
			else {
				str = indexStr + "> " + byteStr + "    " + comand;
			}

			/*if (com != "JCN" ||
				com != "FIM" ||
				com != "JUN" ||
				com != "JMS" ||
				com != "ISZ") {

			}
			else {
				cout << "eah" << endl;

			}*/

			return str;
		}
		else {
			return "END";
		}
	}
};