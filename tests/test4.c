#include "../slp.h"
#include "../prog1.h"

A_stm prog1(void) {

//a:=5+3; b:=(print(a, a-1), a*10); print(b)

return 
 A_CompoundStm(A_AssignStm("a",
                 A_OpExp(A_NumExp(5), A_plus, A_NumExp(3))),
  A_CompoundStm(A_AssignStm("b",
      A_EseqExp(A_PrintStm(A_PairExpList(A_IdExp("a"),
                 A_LastExpList(A_OpExp(A_IdExp("a"), A_minus, 
                                       A_NumExp(1))))),
              A_OpExp(A_NumExp(10), A_times, A_IdExp("a")))),
   A_PrintStm(A_LastExpList(A_IdExp("b")))));

//a:=(4/2+3*2); a:=a+2; print(a)
// return
//     A_CompoundStm(
//         A_CompoundStm(
//             A_AssignStm(
//                 "a",
//                 A_OpExp(
//                     A_OpExp(
//                         A_NumExp(4),
//                         A_div,
//                         A_NumExp(2)
//                     ),
//                     A_plus,
//                     A_OpExp(
//                         A_NumExp(3),
//                         A_times,
//                         A_NumExp(2)
//                     )
//                 )
//             ),
//             A_AssignStm(
//                 "a",
//                 A_OpExp(
//                     A_IdExp("a"),
//                     A_plus,
//                     A_NumExp(2)
//                 )
//             )
//         ),
//         A_PrintStm(
//             A_LastExpList(
//                 A_IdExp("a")
//             )
//         )
//     );

//a:=4+(3*2+8/4); b:=(print(a, a + a*2), print(a), 1+9); print(b, a)
// return
//     A_CompoundStm(
//         A_AssignStm(
//             "a",
//             A_OpExp(
//                 A_NumExp(4),
//                 A_plus,
//                 A_OpExp(
//                     A_OpExp(
//                         A_NumExp(3),
//                         A_times,
//                         A_NumExp(2)
//                     ),
//                     A_plus,
//                     A_OpExp(
//                         A_NumExp(8),
//                         A_div,
//                         A_NumExp(4)
//                     )
//                 )
//             )
//         ),
//         A_CompoundStm(
//             A_AssignStm(
//                 "b",
//                 A_EseqExp(
//                     A_PrintStm(
//                         A_PairExpList(
//                             A_IdExp("a"),
//                             A_LastExpList(
//                                 A_OpExp(
//                                     A_IdExp("a"),
//                                     A_plus,
//                                     A_OpExp(
//                                         A_IdExp("a"),
//                                         A_times,
//                                         A_NumExp(2)
//                                     )
//                                 )
//                             )
//                         )
//                     ),
//                     A_EseqExp(
//                         A_PrintStm(
//                             A_LastExpList(
//                                 A_IdExp("a")
//                             )
//                         ),
//                         A_OpExp(
//                             A_NumExp(1),
//                             A_plus,
//                             A_NumExp(9)
//                         )
//                     )
//                 )
//             ),
//             A_PrintStm(
//                 A_PairExpList(
//                     A_IdExp("b"),
//                     A_LastExpList(
//                         A_IdExp("a")
//                     )
//                 )
//             )
//         )
//     );

}
