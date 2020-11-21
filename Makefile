##
## EPITECH PROJECT, 2019
## OOP_arcade_2019
## File description:
## Makefile
##

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

NAME	=	arcade
COLOR_THEME	=	$(YELLO_C)

ROOT_PATH	=	./
SRC_NAME	=	src
INCL_NAME	=	include
INCL_PATH	=	$(ROOT_PATH)$(INCL_NAME)
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)

SRC	=	CoreModule.cpp \
		error/Error.cpp \
		Prompt.cpp \
		Highscore.cpp

SRCS	=	$(SRC:%=$(SRC_PATH)/%) $(SRC_PATH)/main.cpp
OBJ	=	$(SRCS:.cpp=.o)

CC	= g++
CFLAGS	=	-I $(INCL_PATH) \
			$(LIB_PATHS_FLAG) \
			$(LIBRARIES) \
			-std=c++17	\
			-ldl	\
			-g3

all:	games graphicals message core

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" ____        _ _     _"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| __ ) _   _(_) | __| |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|  _ \| | | | | |/ _\` |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |_) | |_| | | | (_| |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|____/ \__,_|_|_|\__,_|"$(DEFAULT)
	@$(LINE_RETURN)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(RED_C)$(BOLD_T)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

clean:
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"$(NAME)'s object files"$(DEFAULT)
	@$(RM) vgcore.*
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Valgrind files"$(DEFAULT);
	@make clean -C games --no-print-directory
	@make clean -C lib --no-print-directory 

fclean: clean
	@$(RM) $(NAME)
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary $(NAME)"$(DEFAULT)
	@make fclean -C games --no-print-directory
	@make fclean -C lib --no-print-directory 

re:	fclean all

core: $(NAME)

games: 
	@make -B -C games --no-print-directory

graphicals:
	@make -B -C lib --no-print-directory

%.o: %.cpp
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)$(BOLD_T)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all games graphicals message clean fclean re
