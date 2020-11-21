##
## EPITECH PROJECT, 2019
## OOP_arcade_2019
## File description:
## Makefile
##

libs 	= 	nibbler
libs 	+= 	solarfox
libs 	+= 	qix
libs 	+= 	pacman
libs 	+= 	centipede

all:
	@for MAKE_PATH in $(libs) ; do \
		make -C $$MAKE_PATH all --no-print-directory; \
		mv $$MAKE_PATH/*.so .;\
	done

clean:
	@for MAKE_PATH in $(libs) ; do \
		make -C $$MAKE_PATH clean --no-print-directory; \
	done

fclean:
	@for MAKE_PATH in $(libs) ; do \
		make -C $$MAKE_PATH fclean --no-print-directory ; \
		rm -rf ./*.so; \
	done

re:
	@for MAKE_PATH in $(libs) ; do \
		make -C $$MAKE_PATH re --no-print-directory; \
		mv $$MAKE_PATH/*.so .; \
	done