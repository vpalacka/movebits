# Makefile - for testvgetbits

# Regular compilation command, just as it would be written on
# the command line
testvgetbits: testvgetbits.c vgetbits.c
	c99 -Wall -g -o testvgetbits testvgetbits.c vgetbits.c

# Target to clean files created during compilation
clean:
	rm -f *.o testvgetbits 
#	cp ./makedir/Makefile.orig Makefile