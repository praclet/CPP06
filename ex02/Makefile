NAME			:=	ex02

SRCS			:=	

SRCS_DIR		:=	./srcs/
HEADERS_DIR		:=	./headers/
OBJS_DIR		:=	./objs/
DEP_DIR			:=	./dependencies/

#################################################################

vpath				%.cpp $(SRCS_DIR)
vpath				%.hpp $(HEADERS_DIR)
vpath				%.o $(OBJS_DIR)
vpath				%.d $(DEP_DIR)

OBJS			:=	$(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
DEP				:=	$(addprefix $(DEP_DIR), $(SRCS:.cpp=.d))

CC				:=	clang++
CFLAGS			:=	-Wall -Wextra -Werror -I$(HEADERS_DIR) -std=C++98
DEPFLAGS		=	-MT $@ -MMD -MP -MF $(DEP_DIR)$*.d

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o	:	%.cpp $(DEP_DIR)%.d
					@mkdir -p $(DEP_DIR)
					@mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) $(DEPFLAGS) -o $@ -c $<

clean			:
					rm -rf $(OBJS_DIR)

fclean			:	clean
					rm -rf $(DEP_DIR)
					rm -rf $(NAME)

re				:	fclean	all

.PHONY			:	all clean fclean re

$(DEP)			:
include $(wildcard $(DEP))
