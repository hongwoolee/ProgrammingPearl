#include <stdio.h>

#define SIZEOF_NUMBERS 10000000
#define BITSPERWORD 32
#define MASK 0x1F
#define SHIFT 5

static int Numbers[SIZEOF_NUMBERS/BITSPERWORD+1];

inline void setNumber(int n) {
    int index = n>>SHIFT;
    int bitIndex = n & MASK;
    Numbers[index] = Numbers[index] | 1 << bitIndex;
}

inline bool isSet(int n) {
    int index = n>>SHIFT;
    int bitIndex = n & MASK;
    return Numbers[index] & (1 << bitIndex);
}

int main(int argc, char** argv)
{
    int i = 0;
    int n = 0;
    while(scanf("%d", &i) != EOF) {
        setNumber(i);
        n++;
    }
    
    for(i=0; i<n; i++) {
        if(isSet(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}


