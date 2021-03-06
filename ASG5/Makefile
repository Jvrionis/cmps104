MKFILE  = Makefile
NOINCLUDE = ci clean spotless
NEEDINCL  = ${filter ${NOINCLUDE}, ${MAKECMDGOALS}}
CPP       = g++ -g -O0 -Wall -Wextra -std=gnu++14
MKDEPS    = g++ -MM -std=gnu++14
GRIND     = valgrind --leak-check=full --show-reachable=yes
BISON = bison --defines=${PARSEHDR} --output=${PARCECPP}

HDRSRC = astree.h auxlib.h lyutils.h string_set.h typecheck.h \
           symstack.h symtable.h emit.h
CPPSRC = astree.cpp auxlib.cpp lyutils.cpp string_set.cpp main.cpp \
           typecheck.cpp symstack.cpp symtable.cpp emit.cpp
LSOURCES  = scanner.l
YSOURCES  = parser.y 
HYGEN     = yyparse.h 
CLGEN     = yylex.cpp
CYGEN     = yyparse.cpp 
CGENS     = ${CLGEN} ${CYGEN}
ALLGENS   = ${HYGEN} ${CGENS}
EXECBIN   = oc
OBJECTS   = ${CPPSRC:.cpp=.o} yylex.o yyparse.o
LREPORT   = yylex.output 
YREPORT   = yyparse.output 
REPORTS   = ${LREPORT} ${YREPORT}
PSOURCES  = ${LSOURCES} ${YSOURCES}
ALLSRC    = README ${HDRSRC} {CPPSRC} ${LSOURCES} ${YSOURCES} Makefile
TESTINS   = ${wildcard test*.in}
LISTSRC   = ${ALLSRC} ${DEPSFILE} ${HYGEN}


all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${CPP} -o${EXECBIN} ${OBJECTS}

${OBJECTS} : ${CPPSRC} ${CGENS}
	${CPP} -Wno-sign-compare -c ${CPPSRC}
	${CPP} -Wno-sign-compare -c ${CGENS}

${CLGEN} : ${LSOURCES}
	flex --outfile=${CLGEN} ${LSOURCES} 2>${LREPORT}
	- grep -v '^ ' ${LREPORT}

${CYGEN} ${HYGEN} : ${YSOURCES}
	bison --defines=${HYGEN} --output=${CYGEN} ${YSOURCES}

ci : ${ALLSRC} ${TESTINS}
	cid + ${ALLSRC} ${TESTINS} test?.inh

lis : ${LISTSRC} tests
	mkpspdf List.source.ps ${LISTSRC}
	mkpspdf List.output.ps ${REPORTS} \
		${foreach test, ${TESTINS:.in=}, \
		${patsubst %, ${test}.%, in out err log}}

clean :
	- rm ${OBJECTS} ${ALLGENS} ${REPORTS} checksource.log gmake.log 

spotless : clean
	- rm ${EXECBIN} 
	- rm *.err 
	- rm *.out 
	- rm *.ast 
	- rm *.sym 
	- rm *.tok 
	- rm *.str 
	- rm *.oil
	- rm *.oc

checksource : ${ALLSRC}
	checksource ${ALLSRC}

dep : ${ALLCSRC}
	@ echo "# ${DEPSFILE} created `date` by ${MAKE}" >${DEPSFILE}
	${MKDEPS} ${ALLCSRC} >>${DEPSFILE}


${DEPSFILE} :
	@ touch ${DEPSFILE}
	${MAKE} --no-print-directory deps

tests : ${EXECBIN}
	touch ${TESTINS}
	make --no-print-directory ${TESTINS:.in=.out}

%.out %.err : %.in
	${GRIND} --log-file=$*.log ${EXECTEST} $< 1>$*.out 2>$*.err; \
	echo EXIT STATUS = $$? >>$*.log

again :
	gmake --no-print-directory spotless deps ci all lis

submit :
	- submit cmps104a-wm.f17 asg5 astree.cpp astree.h auxlib.cpp \
	auxlib.h emit.cpp emit.h lyutils.cpp lyutils.h main.cpp \
	Makefile parser.y README scanner.l string_set.cpp \
	string_set.h symstack.cpp symstack.h symtable.cpp symtable.h \
	typecheck.cpp typecheck.h
	
ifeq "${NEEDINCL}" ""
include ${DEPSFILE}
endif
