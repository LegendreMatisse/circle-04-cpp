# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 21:55:10 by mlegendr          #+#    #+#              #
#    Updated: 2024/08/17 21:55:10 by mlegendr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	moreWeirdShit

SRC		=	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

INC		=	Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

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