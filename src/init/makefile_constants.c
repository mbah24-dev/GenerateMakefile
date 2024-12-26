/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makefile_constants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:24:12 by mbah              #+#    #+#             */
/*   Updated: 2024/12/26 21:46:28 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/GenMakefile.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_makefile  makefile_constants(char *exec_name)
{
    t_makefile  base_of_makefile;
	
	base_of_makefile.make_header = "";
	base_of_makefile.make_footer = "";
    char        *header_format = "NAME      ?= %s\n"
                                 "CC         = cc\n"
                                 "DIR        = src\n"
                                 "INC        = inc\n"
                                 "CFLAGS     = -Wall -Werror -Wextra -I ./\n";
    char        *header = malloc(strlen(header_format) + strlen(exec_name) + 1);
    if (!header)
        return base_of_makefile; // Gestion de l'erreur

    sprintf(header, header_format, exec_name);

    base_of_makefile.make_header = header;
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

    return base_of_makefile;
}
