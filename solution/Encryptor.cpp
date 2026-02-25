#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

unsigned char ROR(unsigned char value,int shift) {
    shift &=7;
    return (value >>shift) | (value <<(8-shift));
}

int main() {
    std::ifstream file("flag.enc",std::ios::binary);
    unsigned int seed;
    file.read(reinterpret_cast<char*>(&seed),4);
    srand(seed);

    std::vector<unsigned char> buffer(
        (std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>()
        );

    for (int i=0;i<buffer.size();++i) {
        int xor_value=rand();
        int shift_value=rand();
        buffer[i]=ROR(buffer[i],shift_value);
        buffer[i]^=xor_value;

    }
    for (char byte:buffer) {
        std::cout<<byte;
    }


    return 0;
}