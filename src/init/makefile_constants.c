/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makefile_constants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:24:12 by mbah              #+#    #+#             */
/*   Updated: 2024/12/23 17:46:46 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/GenMakefile.h"

t_makefile	makefile_constants(void)
{
	t_makefile	base_of_makefile;

	base_of_makefile.make_header =
		"NAME      ?= exec\n"
		"CC         = cc\n"
		"DIR        = src\n"
		"INC        = inc\n"
		"CFLAGS     = -Wall -Werror -Wextra -I ./\n";
	base_of_makefile.make_footer =
		"\nOBJS       = $(SRC:.c=.o)\n\n"
		"$(NAME): $(OBJS)\n"
		"\t$(CC) $(CFLAGS) $(OBJS) -o $(NAME)\n\n"
		"%.o: %.c $(HEADER)\n"
		"\t$(CC) $(CFLAGS) -c $< -o $@\n\n"
		"all: $(NAME)\n\t\n"
		"clean:\n\trm -rf $(OBJS)\n\n"
		"fclean: clean\n\trm -rf $(NAME)\n\n"
		"re: fclean all\n\n"
		".PHONY: all clean fclean re\n";
	return (base_of_makefile);
}
