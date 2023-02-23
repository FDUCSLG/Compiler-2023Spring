TESTCASE_DIR := tests
TESTCASES = $(wildcard $(TESTCASE_DIR)/*.c)
EXEUTABLES = $(patsubst $(TESTCASE_DIR)/%.c,$(TESTCASE_DIR)/%.o,$(TESTCASES))
MAINFILES = $(patsubst $(TESTCASE_DIR)/%.c,$(TESTCASE_DIR)/%.main.o,$(TESTCASES))
EXPECTS = $(patsubst $(TESTCASE_DIR)/%.c,$(TESTCASE_DIR)/%.exp,$(TESTCASES))
OUTS = $(patsubst $(TESTCASE_DIR)/%.c,$(TESTCASE_DIR)/%.out,$(TESTCASES))
OUTPUTS = $(patsubst $(TESTCASE_DIR)/%.c,$(TESTCASE_DIR)/%.output,$(TESTCASES))
LLFILES = $(patsubst $(TESTCASE_DIR)/%.c,$(TESTCASE_DIR)/%.ll,$(TESTCASES))

.SECONDARY: $(LLFILES)

autograde: $(patsubst $(TESTCASE_DIR)/%.c,$(TESTCASE_DIR)/%.output,$(TESTCASES))

$(TESTCASE_DIR)/%.output: $(TESTCASE_DIR)/%.ll $(TESTCASE_DIR)/%.exp lib.ll
	@llvm-link $< lib.ll -S -o out.ll
	@lli out.ll > $@
	@diff $@ $(word 2,$^)
	@echo PASS $*
	@echo 

lib.ll: libsysy.c libsysy.h
	@clang -S -emit-llvm libsysy.c -o lib.ll -O0

$(TESTCASE_DIR)/%.ll: $(TESTCASE_DIR)/%.out
	@echo TEST $*
	@./$< $@

$(TESTCASE_DIR)/%.out: $(TESTCASE_DIR)/%.o $(TESTCASE_DIR)/%.main.o slp.o util.o print_slp.o interp.o table.o
	@cc -g $^ -o $@

$(TESTCASE_DIR)/%.o: $(TESTCASE_DIR)/%.c slp.h util.h prog1.h
	@cc -g -c $< -o $@

$(TESTCASE_DIR)/%.main.o: main.c slp.h slp.c util.h util.c prog1.h $(TESTCASE_DIR)/%.c print_slp.h print_slp.c
	@cc -g -c main.c -o $@

print_slp.o: print_slp.c slp.h util.h 
	@cc -g -c print_slp.c

interp.o: interp.c interp.h slp.h table.h
	@cc -g -c interp.c

slp.o: slp.c slp.h util.h
	@cc -g -c slp.c

table.o: table.c table.h util.h
	@cc -g -c table.c

util.o: util.c util.h
	@cc -g -c util.c

clean:
	rm util.o slp.o print_slp.o out.ll lib.ll interp.o table.o
