##############################################################################
# File:    Makefile
# Author:  Pete Goodliffe
# Date:    2003-07-20
# Purpose: Example Makefile to test the dbg library
#          (The only interesting bits are how to create tests in debug
#          mode and release mode.)
##############################################################################

##############################################################################
# Initial rules

CFLAGS    = -O4 -Wall -s
VERSION   = $(shell cat VERSION)
DBGNAME   = dbg-${VERSION}
TARBALL   = ${DBGNAME}.tgz
DISTFILES = README LICENSE VERSION dbg.h dbg.cpp Makefile test.cpp

all: test test-dbg test-nothing
	@ls -l test-dbg
	@ls -l test
	@ls -l test-nothing

dist: ${TARBALL}

##############################################################################
# Building the library

clean:
	rm -rf core a.out *.o test test-dbg test-nothing dbg*.tgz www.tgz SRC1.out SRC2.out www/*.pdf dbg*.tgz dbg.h.html dbg.cpp.html test.cpp.html

dbg.o: dbg.h dbg.cpp
	g++ $(CFLAGS) -c dbg.cpp

##############################################################################
# Building the test files

test-dbg: dbg.o test.cpp
	g++ $(CFLAGS) -DDBG_ENABLED test.cpp -c -o test-dbg.o
	g++ $(CFLAGS) -o test-dbg test-dbg.o dbg.o

test: test.cpp
	g++ $(CFLAGS) test.cpp -c -o test.o
	g++ $(CFLAGS) -o test test.o

test-nothing: test.cpp
	g++ $(CFLAGS) -DTEST_WITHOUT_ANY_LIBRARY_USAGE test.cpp -c -o test.o
	g++ $(CFLAGS) -o test-nothing test.o

##############################################################################
# Building the distribution

${TARBALL}: ${DISTFILES}
	mkdir -p ${DBGNAME}
	for i in "${DISTFILES}"; do cp $$i ${DBGNAME}; done && \
            tar cfz ${TARBALL} ${DBGNAME} &&\
            rm -rf ${DBGNAME}

# End
##############################################################################
