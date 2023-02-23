#include "../slp.h"
#include "../prog1.h"
A_stm prog1(void) {
return
  A_CompoundStm(
    A_AssignStm("a",
      A_OpExp(A_NumExp(1), A_plus, A_NumExp(1))),
    A_CompoundStm(
      A_AssignStm("b",
        A_EseqExp(
          A_CompoundStm(
            A_PrintStm(A_LastExpList(A_IdExp("a"))),
            A_PrintStm(A_LastExpList(A_OpExp(A_IdExp("a"), A_plus, A_NumExp(1))))
          ),
          A_NumExp(3)
        )),
      A_PrintStm(A_LastExpList(A_IdExp("b")))
    )
  );
}


/*

source code:
    a:=1+1;
    b:=(print(a);print(a+1),3);
    print(b)

output:
    2
    3
    3

*/