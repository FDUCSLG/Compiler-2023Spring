#include "../slp.h"
#include "../prog1.h"
A_stm prog1(void) {
return
  A_PrintStm(A_LastExpList(A_NumExp(10000000)));
}


/*

test PrintStm and NumExp

source code:
    print(10000000)

output:
    10000000

*/