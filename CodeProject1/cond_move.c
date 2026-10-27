include <stdio.h>
#include<stdlib.h>

//abs diff
long absdiff(long x, long y){
        long result;
        if(x>y){
                result = x-y;
        }
        else{
                result = y-x;
        }
        return result;
}

int main(){
        long r;
        r = absdiff(5, 6);
        printf("absolute difference is %lu\n", r);
        return EXIT_SUCCESS;
}
