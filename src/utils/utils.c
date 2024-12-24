/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:31:51 by mbah              #+#    #+#             */
/*   Updated: 2024/12/23 21:42:21 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	safe_write(int fd, const char *content, size_t length)
{
	if (write(fd, content, length) < 0)
	{
		perror("write");
		close(fd);
		exit(EXIT_FAILURE);
	}
}

void	write_makefile(int fd, const char *src_content, char type)
{
	if (type == 's')
		safe_write(fd, "SRC        = ", 13);
	else
		safe_write(fd, "HEADER     = ", 13);
	safe_write(fd, src_content, ft_strlen(src_content));
	safe_write(fd, "\n", 1);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char	*generate_unique_signature() 
{
    time_t rawtime;
    struct tm *timeinfo;
    char *signature = (char *)malloc(64 * sizeof(char));
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(signature, 64, "%Y-%m-%d %H:%M:%S", timeinfo);
    return (signature);
}

void	write_makefile_with_signature(const char *makefile_name)
{
    FILE *file = fopen(makefile_name, "w");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier Makefile");
        exit(EXIT_FAILURE);
    }
    char *signature = generate_unique_signature();

    fprintf(file, "# ----------------------------------------------------------------------------\n");
    fprintf(file, "#  Developed by Mamadou Bah in Lyon, France\n");
    fprintf(file, "#  Where the magic of Makefiles happens!\n");
    fprintf(file, "#  Signature unique : %s\n", signature);
    fprintf(file, "# ----------------------------------------------------------------------------\n");
    fclose(file);
    free(signature);
}

