#pragma once
class ROM4001 {
public:
    short data[256];
    short IO_PORT = 0b0000;
    void reset() {
        for (int i = 0; i < 256; i++) {
            this->data[i] = 0x0;
        }
        this->IO_PORT = 0b0000;
    }
};