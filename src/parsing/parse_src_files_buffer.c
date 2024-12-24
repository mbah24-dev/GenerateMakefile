/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_src_files_buffer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:18:38 by mbah              #+#    #+#             */
/*   Updated: 2024/12/23 21:07:39 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/GenMakefile.h"
#include "../../inc/utils.h"

static size_t	get_nb_files(const char *str)
{
	size_t	i;
	size_t	nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			nb++;
		i++;
	}
	return (nb);
}

static size_t	get_reslen(const char *str)
{
	size_t	files = get_nb_files(str);
	size_t	extra_chars = (files / 6) * 6;
	return (strlen(str) + extra_chars);
}

char	*parse_src_files_buffer(const char *src_buffer)
{
	char	*res;
	size_t	res_len;
	size_t	count = 0;
	int		i = 0;
	int		j = 0;

	res_len = get_reslen(src_buffer);
	res = (char *) malloc(sizeof(char) * (res_len + 1));
	if (!res)
		return (NULL);
	while (src_buffer[i])
	{
		res[j++] = src_buffer[i];
		if (src_buffer[i] == ' ' && src_buffer[i + 1] != ' ' && src_buffer[i + 1] != '\0')
		{
			count++;
			if (count == 3)
			{
				res[j++] = '\\';
				res[j++] = '\n';
				res[j++] = '\t';
				res[j++] = '\t';
				res[j++] = '\t';
				res[j++] = ' ';
				count = 0;
			}
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}
