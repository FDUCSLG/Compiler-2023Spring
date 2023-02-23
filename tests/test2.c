#include "../slp.h"
#include "../prog1.h"
A_stm prog1(void) {
return
  A_CompoundStm(
    A_AssignStm("a",
      A_OpExp(A_NumExp(2), A_times, A_NumExp(2))),
    A_CompoundStm(
      A_AssignStm("c",
        A_OpExp(A_IdExp("a"), A_div, A_NumExp(1))),
      A_CompoundStm(
        A_AssignStm("b",
          A_EseqExp(
            A_CompoundStm(
              A_PrintStm(A_LastExpList(A_IdExp("a"))),
              A_PrintStm(A_LastExpList(A_OpExp(A_IdExp("a"), A_minus, A_IdExp("a"))))
            ),
            A_IdExp("c")
          )),
        A_PrintStm(A_LastExpList(A_IdExp("b")))
      )
    )
  );
}

/*

source code:
    a:=2*2;
    c:=a/1;
    b:=(print(a);print(a-a),c);
    print(b)

output:
    4
    0
    4

*/