#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>


using namespace std; // because I am lazy


    fstream skel;
    ostringstream fname;
    char y = 0x20;
// different way: get 12th byte and multiply numerical value +1 by 32 to get offset
void extractData(string filename){
    fstream fs;
    fs.open(filename, ios::in | ios::out | ios::binary);
    // cout << filename << endl; - if you want to see which file is being processed
    char buf[13];
    char byte;
    fs.read(buf, sizeof(buf));
    auto offset = ((uint32_t)(buf[12])+1)*32;
    fs.seekg(offset, ios::beg);
    
    while (fs.get(byte)) {
        char holder[2] = {byte};
        char space[2] = {y};
        if (byte == 0x00) {
            skel.write(space, 1);

        } else {
            skel.write(holder, 1);
        }
        
        cout << byte; //- watch content being written
        
    }
    fs.close();
}

int main(int argc, char *argv[]) {
    string fileName = (argv[1]);

    //open dir and check
    fname << fileName << ".skel";
    skel.open(fname.str(), ios::in | ios::out | ios::binary | ios::app);
    
    //if (argc < 9) cout << "Not enough variables" << endl;
    //cout << argv[0] << "\n";
    //cout << argv[1] << "\n";
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


