#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <bitset>
#include <cassert>
#include <algorithm>

using namespace std; 

string divider(string& sourceFile, unsigned int mask, int& size);

int getShiftCount(unsigned int mask) {
    int shiftcount = -1;
    for(int i=0; i<16; i++) {
        if((mask == 0x3 << (i*2))) {
            shiftcount = i*2;
            break;
        }
    }
    assert(shiftcount != -1);
    return shiftcount;
}

int main(int argc, char** argv) {
    if(argc < 2) {
        cout << "invalid input" << endl;
        return -1;
    }
    string originInput(argv[1]);
    int size = 0;
    unsigned int mask = 0x3 << 30;
    string input = originInput;
    string output;
    do {
        output = divider(input, mask, size);
        input = output;
        mask = mask >> 2;
        cout << "size: " << size << " mask: " << mask << endl;
    } while(size > 1024);

    string bitString = output.substr(originInput.size());
    int shiftcount = 32 - bitString.size();
    bitset<32> minimum_bitset(bitString);
    unsigned int minimum = minimum_bitset.to_ulong() << shiftcount;
    unsigned int maximum = minimum + ((1 << shiftcount) - 1);

    unsigned int i = 1;
    ifstream source(output);

    // 선택된 파일을 정렬하는 코드가 추가되어야 함!! 
    int count = 0;
    while(source >> i) {
        if( (minimum + count++) != i) {
            break;
        }
    }
    
    cout << "result: " << i << endl;
    return 0;
}

string divider(string& sourceFile, unsigned int mask, int& size) {
    vector<int> lengthList;
    vector< shared_ptr<ofstream> > outputs;
    for(int i=0; i<4; i++) {
        ostringstream s;
        bitset<2> b(i);
        s << sourceFile << b;
        outputs.push_back( make_shared<ofstream>(s.str()) );
        lengthList.push_back(0);
    }

    unsigned int i = 0;
    int shiftcount = getShiftCount(mask);

    ifstream source(sourceFile);
    while(source>>i) {
        int s = (i & mask) >> shiftcount;
        if(s > 3) {
            cout << "weird" << endl;
        }
        *outputs[s] << i << endl;
        lengthList[s]++;
    }
    vector<int>::iterator iter = min_element(lengthList.begin(), lengthList.end());
    bitset<2> b(distance(lengthList.begin(), iter));

    for(int i=0; i<4; i++) {
        (*outputs[i]).flush();
        (*outputs[i]).close();
    }
    size = *iter;
    return sourceFile + b.to_string();
}
