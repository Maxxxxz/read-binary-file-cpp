#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <bitset>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

void run(unsigned short type, string filename);

int main(int argc, char * argv[])
{
    cout << "Hello, World!" << endl;

    if(argc >= 2)
    {
        string arg = string(argv[1]);
        unsigned short type = 0;

        if(arg == "-text")
        {
            type = 0;
        }
        else if(arg == "-bin")
        {
            type = 1;
        }
        else if(arg == "-hex")
        {
            type = 2;
        }
        else
        {
            cout << "Invalid option: " << arg << ". Please use -{text|hex|bin}." << endl;
            return 0;
        }
        

        run(type, string((argv[2])));
    }
    else
    {
        cout << "Run with a type and file name! (ie program.exe -{text|hex|bin} file.ext" << endl;
    }

    return 0;
}

void run(unsigned short type, string filename)
{
    std::ifstream inFile(filename, std::ios::binary);
    std::vector<unsigned char> fileBuf(std::istreambuf_iterator<char>(inFile), {});

    // cout << fileBuf.size() << endl;

    switch (type)
    {
    case 0: // TEXT
        for(size_t i = 0; i <= fileBuf.size(); i++)
        {
            // if(i % 5 == 0)
            // {
            //     fileBuf[i] += 15;
            // }
            printf("%c", fileBuf[i]);
        }
        break;
    case 1: // BIN
        for(size_t i = 0; i <= fileBuf.size(); i++)
        {
            std::bitset<8> bs(fileBuf[i]);
            cout << bs;
        }
        break;
    case 2: // HEX
        for(size_t i = 0; i <= fileBuf.size(); i++)
        {
            std::bitset<8> bs(fileBuf[i]);
            cout << std::hex << bs.to_ulong();
        }
        break;
    default:
        break;
    }
    
}