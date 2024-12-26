/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:32:14 by mbah              #+#    #+#             */
/*   Updated: 2024/12/26 21:47:49 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include "GenMakefile.h"

size_t	ft_strlen(const char *str);
void	safe_write(int fd, const char *content, size_t length);
void	write_makefile(int fd, const char *src_content, char type);

#endif