#include <stdio.h>

#define SIZEOF_NUMBERS 10000000

static int Numbers[SIZEOF_NUMBERS/sizeof(int)];

inline void setNumber(int n) {
    int index = n/sizeof(int);
    int bitIndex = n%sizeof(int);
    Numbers[index] = Numbers[index] | 1 << bitIndex;
}

inline bool isSet(int n) {
    int index = n/sizeof(int);
    int bitIndex = n%sizeof(int);
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


