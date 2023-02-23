#include "../slp.h"
#include "../prog1.h"
A_stm prog1(void) {
return
  A_CompoundStm(
    A_AssignStm("a",
      A_OpExp(A_NumExp(1900), A_plus, A_NumExp(5))),
    A_CompoundStm(
      A_AssignStm("b",
        A_OpExp(A_OpExp(A_IdExp("a"), A_minus, A_NumExp(1905)), A_plus, A_NumExp(527))),
      A_CompoundStm(
        A_AssignStm("e",
          A_NumExp(5)),
        A_CompoundStm(
          A_AssignStm("c",
            A_OpExp(A_OpExp(A_OpExp(A_NumExp(1), A_times, A_IdExp("e")), A_div, A_IdExp("e")), A_plus, A_OpExp(A_NumExp(20), A_times, A_NumExp(30)))),
          A_AssignStm("d",
              A_EseqExp(
                A_CompoundStm(
                  A_PrintStm(A_LastExpList(A_IdExp("a"))),
                  A_PrintStm(A_PairExpList(A_IdExp("b"),
                        A_LastExpList(A_IdExp("c"))))
                ),
                A_NumExp(0)
              ))
        )
      )
    )
  );
}


/*

source code:
    a:=1900+5;
    b:=a-1905+527;
    e:=5;
    c:=1*e/e+20*30;
    d:=(print(a);print(b,c),0)

output:
    1905
    527
    601

*/