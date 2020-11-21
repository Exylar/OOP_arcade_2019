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
DEFAULT_C	=	"\e[39m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	i"\e[96m"
LINE_RETURN	=	$(ECHO) ""
COLOR_THEME		=	$(MAGEN_C)

CXX		=	g++

NAME		=	lib_arcade_centipede.so

RM		=	rm -rf

SRC		=	centipede.cpp \

CXXFLAGS	 =	-I include -I ../../include
CXXFLAGS	+=	-fPIC

LDFLAGS	 =	-shared

OBJ	=	$(SRC:.cpp=.o)

all:	message	$(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" _     _ _                          " $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |   (_) |__  _ __ __ _ _ __ _   _ " $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |   | | '_ \| '__/ _\` | '__| | | |" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |___| | |_) | | | (_| | |  | |_| |" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|_____|_|_.__/|_|  \__,_|_|   \__, |" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"                              |___/ " $(DEFAULT)
	@$(LINE_RETURN)

$(NAME):	$(OBJ)
		@$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)" $(DEFAULT) "\n" || \
		$(ECHO) $(RED_C)$(BOLD_T)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)"$(DEFAULT) "\n"

clean:
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"lib$(NAME)'s object files"$(DEFAULT)

fclean:	clean
	@$(RM) ./lib$(NAME).a
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary lib$(NAME).a"$(DEFAULT)

%.o: %.cpp
	@$(CXX) -c $(CXXFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)$(BOLD_T)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

re:		fclean clean all message
