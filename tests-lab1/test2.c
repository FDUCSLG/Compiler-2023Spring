#include "../slp.h"
#include "../prog1.h"
A_stm prog1(void) {
return
  A_CompoundStm(
    A_AssignStm("a",
      A_NumExp(216)),
    A_PrintStm(A_LastExpList(A_IdExp("a")))
  );
}


/*

test CompundStm, AssignStm and IdExp

source code:
    a:=216;
    print(a)

output:
    216

*/