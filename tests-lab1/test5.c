#include "../slp.h"
#include "../prog1.h"
A_stm prog1(void) {
return
  A_CompoundStm(
    A_AssignStm("v5",
      A_NumExp(5)),
    A_CompoundStm(
      A_PrintStm(A_PairExpList(A_NumExp(2),
          A_PairExpList(A_NumExp(3),
          A_LastExpList(A_IdExp("v5"))))),
      A_CompoundStm(
        A_AssignStm("v7",
          A_OpExp(A_NumExp(17), A_minus, A_OpExp(A_OpExp(A_NumExp(4), A_times, A_IdExp("v5")), A_div, A_NumExp(2)))),
        A_CompoundStm(
          A_AssignStm("v9",
            A_EseqExp(
              A_PrintStm(A_LastExpList(A_IdExp("v7"))),
              A_OpExp(A_NumExp(3), A_times, A_NumExp(3))
            )),
          A_CompoundStm(
            A_AssignStm("v13",
              A_EseqExp(
                A_CompoundStm(
                  A_AssignStm("v11",
                    A_OpExp(A_OpExp(A_IdExp("v7"), A_minus, A_NumExp(1)), A_plus, A_IdExp("v5"))),
                  A_CompoundStm(
                    A_AssignStm("v17",
                      A_EseqExp(
                        A_CompoundStm(
                          A_AssignStm("v9",
                            A_IdExp("v9")),
                          A_PrintStm(A_LastExpList(A_IdExp("v9")))
                        ),
                        A_OpExp(A_OpExp(A_IdExp("v7"), A_times, A_IdExp("v5")), A_minus, A_NumExp(18))
                      )),
                    A_CompoundStm(
                      A_PrintStm(A_LastExpList(A_IdExp("v11"))),
                      A_AssignStm("v19",
                          A_OpExp(A_OpExp(A_NumExp(2), A_times, A_NumExp(5)), A_plus, A_OpExp(A_NumExp(900), A_div, A_NumExp(100))))
                    )
                  )
                ),
                A_NumExp(13)
              )),
            A_PrintStm(A_PairExpList(A_IdExp("v13"),
                  A_PairExpList(A_IdExp("v17"),
                  A_LastExpList(A_IdExp("v19")))))
          )
        )
      )
    )
  );
}



/*

full test

source code:
    v5:=5;
    print(2,3,v5);
    v7:=17-4*v5/2;
    v9:=(print(v7),3*3);
    v13:=(v11:=v7-1+v5;v17:=(v9:=v9;print(v9),v7*v5-18);print(v11);v19:=2*5+900/100,13);
    print(v13,v17,v19)

output:
    2
    3
    5
    7
    9
    11
    13
    17
    19

*/