# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anakin <anakin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 15:29:15 by anakin            #+#    #+#              #
#    Updated: 2025/03/13 15:29:32 by anakin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fixed
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
INCLUDE	=	-I includes
RM		=	rm -rf

SRCS	=	$(wildcard *.cpp)

OBJ_D 	=	objs/
OBJ		=	$(SRCS:.cpp=)
OBJS	=	$(addprefix $(OBJ_D), $(addsuffix .o, $(OBJ)))

$(OBJ_D)%.o : $(SRC_D)%.cpp
			@mkdir -p $(OBJ_D)
			@($(CC) $(FLAGS) $(INCLUDE) -c $< -o $@)

all:		$(NAME)

$(NAME):	$(OBJS)
			@($(CC) $(FLAGS) $(INCLUDE) $(OBJS) -o $(NAME))

clean:
			@($(RM) $(OBJ_D))

fclean: 	clean
			@($(RM) $(NAME))

re: 		fclean all

.PHONY:		all clean fclean re