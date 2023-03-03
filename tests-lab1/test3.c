#include "../slp.h"
#include "../prog1.h"
A_stm prog1(void) {
return
  A_CompoundStm(
    A_AssignStm("a",
      A_NumExp(5)),
    A_CompoundStm(
      A_AssignStm("b",
        A_OpExp(A_IdExp("a"), A_plus, A_NumExp(22))),
      A_CompoundStm(
        A_PrintStm(A_PairExpList(A_IdExp("a"),
            A_LastExpList(A_IdExp("b")))),
        A_CompoundStm(
          A_AssignStm("d",
            A_OpExp(A_OpExp(A_IdExp("a"), A_times, A_NumExp(2)), A_minus, A_OpExp(A_IdExp("b"), A_div, A_NumExp(3)))),
          A_PrintStm(A_LastExpList(A_IdExp("d")))
        )
      )
    )
  );
}



/*

test OpExp and ExpList

source code:
    a:=5;
    b:=a+22;
    print(a,b);
    d:=a*2-b/3;
    print(d)

output:
    5
    27
    1

*/