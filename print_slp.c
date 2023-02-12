#include <stdio.h>
#include "print_slp.h"
#include "slp.h"

void print_slp_exp(FILE *stream, A_exp exp) {
    switch (exp->kind) {
    case A_idExp: 
	   fprintf(stream, "%s", exp->u.id);
	   break;
    case A_numExp:
	   fprintf(stream, "%d", exp->u.num);
	   break;
    case A_opExp:
	   print_slp_exp(stream, exp->u.op.left);
           switch (exp->u.op.oper) {
           case A_plus: fprintf(stream, "+"); break;
	   case A_minus: fprintf(stream, "-"); break;
	   case A_times: fprintf(stream, "*"); break;
	   case A_div: fprintf(stream, "/"); break;
	   }
	   print_slp_exp(stream, exp->u.op.right);
	   break;
    case A_eseqExp:
	   fprintf(stream, "(");
	   print_slp_stmt(stream, exp->u.eseq.stm);
	   fprintf(stream, ", ");
	   print_slp_exp(stream, exp->u.eseq.exp);
	   fprintf(stream, ")");
	   break;
    }
    return;
}

void print_slp_expList(FILE *stream, A_expList expList) {
    switch (expList->kind) {
    case A_pairExpList: 
	   print_slp_exp(stream, expList->u.pair.head);
           fprintf(stream, ", ");
	   print_slp_expList(stream, expList->u.pair.tail);
	   break;
    case A_lastExpList:
	   print_slp_exp(stream, expList->u.last);
	   break;
    }
    return;
}

void print_slp_stmt(FILE *stream, A_stm stm) {

    switch (stm->kind) {
    case A_compoundStm:
            //fprintf (stream, "It's a compoundStm!\n");
            print_slp_stmt(stream, stm->u.compound.stm1);
	    //fprintf(stream, "; ");
            print_slp_stmt(stream, stm->u.compound.stm2);
	    //fprintf(stream, "\n");
            break;
        case A_assignStm:
            //fprintf (stream, "It's an assignStm!\n");
	    fprintf(stream, "%s:=", stm->u.assign.id);
            print_slp_exp(stream, stm->u.assign.exp);
	    fprintf(stream, "; ");
            break;
        case A_printStm:
            //fprintf (stream, "It's a printStm!\n");
	    fprintf(stream, "print(");
            print_slp_expList(stream, stm->u.print.exps);
	    fprintf(stream, ")");
	    break;
    }

    return;
}
