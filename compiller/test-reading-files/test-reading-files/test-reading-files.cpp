#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    ofstream fout;
    string path = "file.txt";
    fout.open(path);
    if (fout.is_open()) {
        cout << "win!\n";
        fout << "win";
    }
    return 0;
}