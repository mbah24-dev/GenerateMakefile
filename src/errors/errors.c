/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:09:30 by mbah              #+#    #+#             */
/*   Updated: 2024/12/24 01:35:30 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/GenMakefile.h"

static int	check_directory_exists(const char *dir_name)
{
	struct stat	statbuf;

	if (stat(dir_name, &statbuf) == 0 && S_ISDIR(statbuf.st_mode))
		return 1;
	else
		return 0;
}

int	an_error(int fd, const char *src, const char *inc)
{
	if (fd < 0)
	{
		printf("open: Impossible d'ouvrir le fichier Makefile");
		return (1);
	}
	if (!check_directory_exists(src) || !check_directory_exists(inc))
	{
		printf("👎 Le Makefile n'a pas été généré car les répertoires \'%s\' et \'%s\' doivent être présents dans le répertoire courant avant de lancer le générateur.\n", inc, src);
		return (1);
	}
	return (0);
}
