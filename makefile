# https://stackoverflow.com/questions/12057852/multiple-makefiles-in-one-directory

all:
	$(MAKE) -C src -f makefile
	$(MAKE) -C test -f makefile

clean:
	$(MAKE) -C src -f makefile clean
	$(MAKE) -C test -f makefile clean

re:
	make -f makefile clean
	make -f makefile all

.PHONY: all clean re
