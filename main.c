#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "slp.h"
#include "prog1.h"
#include "print_slp.h"

void generate_main_ll(FILE *stream, A_stm stm) {
    
//declare extern func + function head
    fprintf(stream, "declare void @putint(i32 noundef) #1\n");
    fprintf(stream, "declare void @putch(i32 noundef) #1\n");
    fprintf(stream, "define dso_local i32 @main() #0 {\n");

//actual code emitter:
//Here is a "hardcoded" one. You need to redo this so it works for all legitimate prog1.c
    fprintf(stream, "    %%1 = add i32 5, 3\n");
    fprintf(stream, "    call void @putint(i32 noundef %%1)\n");
    fprintf(stream, "    call void @putch(i32 noundef 10)\n");
    fprintf(stream, "    %%2 = sub i32 %%1, 1\n");
    fprintf(stream, "    call void @putint(i32 noundef %%2)\n");
    fprintf(stream, "    call void @putch(i32 noundef 10)\n");
    fprintf(stream, "    %%3 = mul i32 10, %%1\n");
    fprintf(stream, "    call void @putint(i32 noundef %%3)\n");
    fprintf(stream, "    call void @putch(i32 noundef 10)\n");
    
//End of the function
    fprintf(stream, "    ret i32 0;\n }\n");

    return;
}

int main(int argc, const char * argv[]) {

    FILE *stream;
    
//  print_slpis testing purpose:
    print_slp_stmt(stdout, prog1());
    fprintf(stdout, ";\n");

    stream = fopen("main.ll", "w");
    
    generate_main_ll(stream, prog1()); //generate main.ll for prog1()
    
    return 0;
}
