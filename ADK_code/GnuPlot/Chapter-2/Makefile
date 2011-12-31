# Create all images for chapter 2

# default rule to build PS files
%.ps: %.plot
	@if [ -f $*.ps ]; then chmod 644 $*.ps ; fi
	gnuplot < $*.plot

# Figures to be built
FIGS = 2-2.ps \
	2-3.ps \
	2-4.ps \
	2-5.ps \
	2-6.ps \
	2-7.ps \
	2-8.ps \
	2-9.ps

# start everything...
all: $(FIGS)
	@chmod 444 $+
	@ls -l $+

test:
	@echo "No tests for Chapter-2"

# Clean up by removing all .ps and any .pdf files left around
clean:
	rm -f *~
	rm -f *.ps *.pdf
