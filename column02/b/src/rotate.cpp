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

void (*rotateFunc)(vector<int>&, int);

void rotate_juggling(vector<int>& array, int rotateCount) {
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

void swap(intVector& v, int firstIndex, int secondIndex, int numberOfSwap) {
    int temp = 0;
    for(int i = 0; i < numberOfSwap; i++) {
        temp = v[firstIndex + i];
        v[firstIndex + i] = v[secondIndex + i];
        v[secondIndex + i] = temp;
    }
}

void rotate_block_swap(intVector& v, int rotateCount) {
    int i, j;
    i = rotateCount;
    j = v.size() - rotateCount;

    while(i != j) {
        if(i < j) {
            swap(v, rotateCount - i, rotateCount + j - i, i);
            j = j - i;
        } else {
            swap(v, rotateCount - i, rotateCount, j);
            i = i - j;
        }
    }
    swap(v, rotateCount - i, rotateCount, i);
}

#define MAX_ARRAY_SIZE 100000

int main(int argc, char** argv) {
    intVector arr;
    int arraySize = -1;
    int rotateCount = -1;

    rotateFunc = NULL;
    if(argc == 4) {
        string rotateAlgorithm = string(argv[1]);
        if(rotateAlgorithm == "juggling") {
            rotateFunc = rotate_juggling;
        } else if(rotateAlgorithm == "block_swap") {
            rotateFunc = rotate_block_swap;
        } else {
        }
        arraySize = atoi(argv[2]);
        rotateCount = atoi(argv[3]);
    }
    if(rotateFunc == NULL || arraySize == -1 || rotateCount == -1) {
        cout << "need rotate algorithm.. juggling, block swap and array size, rotate count" << endl;
        cout << "./rotate juggling 100 3" << endl;
        return -1;
    }

    arr.reserve(arraySize);
    for(int i=0; i<arraySize; i++) {
        arr.push_back(i+1);
    }
    
    rotateFunc(arr, rotateCount);

/*
    for(intVector_it i=arr.begin(); i != arr.end() ; i++) {
        cout<<*i<<endl;
    }
*/
    
    cout << arr[arraySize - 1] << endl;

    return 0;
}
