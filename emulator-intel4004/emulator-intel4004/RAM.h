#pragma once
class RAM4002 {
public:
    short data[4][20] = {
        {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,  0x0,0x0,0x0,0x0},
        {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,  0x0,0x0,0x0,0x0},
        {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,  0x0,0x0,0x0,0x0},
        {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,  0x0,0x0,0x0,0x0}
    };
    short IO_PORT = 0b0000;

    void reset() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; i < 20; i++) {
                this->data[i][j] = 0x0;
            }
            this->IO_PORT = 0b0000;
        }
    }
};