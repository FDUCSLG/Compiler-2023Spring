#include "../slp.h"
#include "../prog1.h"
A_stm prog1(void) {
return
  A_CompoundStm(
    A_AssignStm("val",
      A_NumExp(5)),
    A_CompoundStm(
      A_AssignStm("val",
        A_OpExp(A_IdExp("val"),
            A_plus,
            A_OpExp(A_EseqExp(
                A_CompoundStm(
                A_PrintStm(A_LastExpList(A_IdExp("val"))),
                A_AssignStm("val",
                    A_NumExp(3))
                ),
                A_OpExp(A_IdExp("val"), A_minus, A_NumExp(1))
            ), A_times, A_IdExp("val")))),
      A_PrintStm(A_LastExpList(A_IdExp("val")))
    )
  );
}



/*

test EseqExp

source code:
    val:=5;
    val:=val+(print(val);val:=3,val-1)*val;
    print(val)

output:
    5
    11

*/