# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 18:00:39 by mlegendr          #+#    #+#              #
#    Updated: 2024/07/24 18:05:13 by mlegendr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

#SRC		=	main.cpp Phonebook.cpp Contact.cpp
SRC		=	main.cpp

CC		=	c++

FLAGS	=	-Wall -Werror -Wextra -std=c++98

RM		=	rm -rf

all		:	$(NAME)

$(NAME)	:
			$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean	:
			$(RM) $(NAME)

fclean	:	clean

re		:	fclean all

.PHONY	:	all clean fclean re