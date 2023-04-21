#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <vector>
#include <Windows.h>

using namespace std; // because I am lazy


    fstream skel;
    ostringstream fname;
    

void extractData(string filename){
    fstream fs;
    fs.open(filename, ios::in | ios::out | ios::binary);
    // cout << filename << endl; - if you want to see which file is being processed
    char buf[13];
    char byte;
    fs.read(buf, sizeof(buf));
    auto offset = ((uint32_t)(buf[12])+1)*32;
    cout << offset << endl;
    fs.seekg(offset, ios::beg);
    
    while (fs.get(byte)) {
        char holder[2] = {byte};
        //cout << byte; - watch content being written
        skel.write(holder, 1);
    }
    fs.close();
}

int main(int argc, char *argv[]) {
    string fileName = (argv[1]);

    fname << fileName << ".skel";
    skel.open(fname.str(), ios::in | ios::out | ios::binary | ios::app);
    
    const string pathFrag = fileName + "/" + fileName;
    const string dir[9] = {
        pathFrag + "_CHARA_BASE.cysp",
        pathFrag + "_COMMON_BATTLE.cysp",
        pathFrag + "_BATTLE.cysp",
        pathFrag + "_RUN_JUMP.cysp",
        pathFrag + "_NO_WEAPON.cysp",
        pathFrag + "_SMILE.cysp",
        pathFrag + "_RACE.cysp",
        pathFrag + "_DEAR.cysp",
        pathFrag + "_POSING.cysp",
    };
    

    for (auto& item : dir) {
        cout << item << endl;
        extractData(item);
    }

    skel.close();
    return 0;
}


