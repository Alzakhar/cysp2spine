#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>

using namespace std; // because I am lazy


fstream skel;
ostringstream fname;
int total_offset = 0;

void extractAnimCount(string filename){
    fstream fs;
    char animCount[1];
    fs.open(filename, ios::in | ios::out | ios::binary);
    // cout << filename << endl; - if you want to see which file is being processed
    char buf[13];
    char byte;
    fs.read(buf, sizeof(buf));
    auto offset = ((uint32_t)(buf[12])+1)*32;
    auto count = (uint32_t)(buf[12]);

    if (offset == 4032) {
        cout << "File not found" << endl;
    } else {
       total_offset += count; 
    }

    fs.close();
}

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
    const string dir[10] = {
        pathFrag + "_CHARA_BASE.cysp",
        "offset",
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
        if (item != "offset") {
            extractAnimCount(item);
        }
    }
    
    for (auto& item : dir) {
        cout << item << endl;
        
        if (item == "offset") {
            skel.put(static_cast<char>(total_offset-1));
        } else {
            extractData(item);
        }
    }

    skel.close();
    return 0;
}


