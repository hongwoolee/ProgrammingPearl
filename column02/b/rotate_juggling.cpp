#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> intVector;
typedef vector<int>::iterator intVector_it;

int gcd(int a,int b) {
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

void rotate(vector<int>& array, int rotateCount) {
    int sizeOfArray = array.size();
    int loopCount = gcd(rotateCount, sizeOfArray);
    int tmp = 0;
    int sourceIndex = 0;
    int targetIndex = 0;

    for(int i=0; i<loopCount; i++) {
        tmp = array[i];
        sourceIndex = i;
        while(1) {
            targetIndex = sourceIndex + rotateCount;
            if(targetIndex >= sizeOfArray)
                targetIndex -= sizeOfArray;
            if(targetIndex==i)
                break;
            array[sourceIndex] = array[targetIndex];
            sourceIndex = targetIndex;
        }
        array[sourceIndex] = tmp;
    }
}

#define MAX_ARRAY_SIZE 1000000

int main(int argc, char** argv) {
    intVector arr;

    arr.reserve(MAX_ARRAY_SIZE);
    for(int i=0; i<MAX_ARRAY_SIZE; i++) {
        arr.push_back(i+1);
    }
    
    rotate(arr, 2);

    for(intVector_it i=arr.begin(); i != arr.end() ; i++) {
        cout<<*i<<endl;
    }

    return 0;
}
