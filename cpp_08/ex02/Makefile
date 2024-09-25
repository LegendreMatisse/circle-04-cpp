# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 18:25:15 by mlegendr          #+#    #+#              #
#    Updated: 2024/09/24 18:25:16 by mlegendr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Mutatant

SRC		=	main.cpp

INC		=	MutantStack.hpp MutantStack.tpp

OBJ		=	$(SRC:.cpp=.o)

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o		:	%.cpp $(INC)
			$(CC) $(FLAGS) -c $< -o $@

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re