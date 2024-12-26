/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GenMakefile.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:44:39 by mbah              #+#    #+#             */
/*   Updated: 2024/12/26 21:45:14 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENMAKEFILE_H
# define GENMAKEFILE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>

# define RESET   "\033[0m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"

struct	s_makefile
{
	const char	*make_header;
	const char	*make_footer;
};

typedef struct s_makefile	t_makefile;

t_makefile  makefile_constants(char *exec_name);
int			an_error(int fd, const char *src, const char *inc);
char		*parse_src_files_buffer(const char *src_buffer);
void	scan_files(const char *dir_path, char *src_buffer, 
				size_t buffer_size, size_t *offset, char *type);

#endif