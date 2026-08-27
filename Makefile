#
# Makefile for clist
#

CC = gcc

CFLAGS = -std=c99 -Og -g -Wall -Wextra -Wpedantic -Wconversion
CFLAGS += -Wstrict-prototypes -Wwrite-strings -Werror -Wvla
CFLAGS += -Wno-unused-parameter

# Targets to compile
FILES = ltest

.PHONY: all
all: $(FILES)

# List header dependencies
ltest.o: harness.h list.h text.h report.h console.h
harness.o: harness.h
console.o: report.h console.h
report.o: report.h
list.o: harness.h list.h
text.o: harness.h text.h

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# Compile ltest binaries
ltest: ltest.o report.o console.o harness.o list.o text.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: run
run: ltest
	./ltest

.PHONY: test
test: ltest driver.py
	chmod +x driver.py
	./driver.py

.PHONY: clean
clean:
	rm -rf $(FILES)
	rm -rf *.o *~ *.pyc *.dSYM
	(cd traces; rm -f *~)
