# Create all images for chapter 2

# default rule to build PS files
%.ps: %.plot
	@if [ -f $*.ps ]; then chmod 644 $*.ps ; fi
	gnuplot < $*.plot

# Figures to be built
FIGS = 1-3.ps

# start everything...
all: $(FIGS)
	@chmod 444 $+
	@ls -l $+

test:
	@echo "No tests for Chapter-1"

# Clean up by removing all .ps and any .pdf files left around
clean:
	rm -f *~
	rm -f *.ps *.pdf
