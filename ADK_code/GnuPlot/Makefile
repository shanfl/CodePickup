SUBDIRS = Chapter-1 \
	Chapter-2 \
	Chapter-7 \
	Chapter-9

all: 
	for i in $(SUBDIRS); do (cd "$${i}"; $(MAKE);  if [ $$? -ne 0 ]; then exit -1; fi;) done

test:
	for i in $(SUBDIRS); do (cd "$${i}"; $(MAKE) test; if [ $$? -ne 0 ]; then exit -1; fi;) done

clean:
	for i in $(SUBDIRS); do (cd "$${i}"; $(MAKE) clean;) done
