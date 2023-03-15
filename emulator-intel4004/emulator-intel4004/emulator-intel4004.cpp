#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <string>
#include "Disassembly.h"
#include "PC.h"
#include "InterFace.h"

using namespace std;

void loadData() {
    //загружаем данные в ПЗУ
    string rom = "ROM";
    vector<short> data;
    char ch = '0';
    ifstream fin;
    fin.open(rom, ios::binary);

    string str;
    
    while (fin.get(ch)) {
        data.push_back((int)ch);
        //cout << (int)ch << " ";
    }

    //cout << endl;

    fin.close();

    for (int i = 0; i < data.size(); i++) {
        bus.rom.data[i] = data[i];
    }
}

int main()
{
    //ресетим все
    bus.cpu.reset();
    bus.rom.reset();
    bus.ram.reset();

    loadData();

    for (int i = 0; i < 256; i++) {
        if (bus.rom.data[i] < 0) {
            bus.rom.data[i] = 0x100 + bus.rom.data[i];
        }
    }

    InterFace inface = InterFace(bus.rom,bus.ram,bus.cpu);
    PC pc = PC();

    inface.draw();

    while (true) {
        system("pause");

        pc.tick();

        inface = InterFace(bus.rom, bus.ram, bus.cpu);
        inface.draw();
    }


    system("pause");
    return 0;
}