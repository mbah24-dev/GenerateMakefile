/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:31:51 by mbah              #+#    #+#             */
/*   Updated: 2024/12/26 21:41:20 by mbah             ###   ########.fr       */
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
