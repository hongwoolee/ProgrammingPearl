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

string divider(string& sourceFile, int mask);

int main(int argc, char** argv) {
/*    
    vector< shared_ptr<fstream> > outputs;
    for(int i=0; i<4; i++) {
        ostringstream s;
        s << "out" << i;
        outputs.push_back( make_shared<fstream>(s.str()) );
    }

    vector<int> lengthList;
    unsigned int i = 0;
    while(cin>>i) {
        int s = (i & 0xC0000000) >> 30;
        *outputs[s] << i << endl;
        lengthList[s]++;
    }

    vector<int>::iterator iter = min_element(lengthList.begin(), lengthList.end());
    fstream* m = outputs[iter];
    while(m>>i) {
        int s = (i & 0x30000000) >> 28);
    }
*/

    string input(argv[1]);
    divider(input, 0xC0000000);  
    return 0;
}

string divider(string& sourceFile, int mask) {
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
    int shiftcount = -1;
    for(int i=0; i<16; i++) {
        if((mask == 0x3 << (i*2))) {
            shiftcount = i*2;
            break;
        }
    }
    assert(shiftcount != -1);

    ifstream source(sourceFile);
    while(source>>i) {
        int s = (i & mask) >> shiftcount;
        *outputs[s] << i << endl;
        lengthList[s]++;
    }
    vector<int>::iterator iter = min_element(lengthList.begin(), lengthList.end());
    bitset<2> b(distance(lengthList.begin(), iter));

    return sourceFile + b.to_string();
}
