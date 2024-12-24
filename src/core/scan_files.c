/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:50:43 by mbah              #+#    #+#             */
/*   Updated: 2024/12/23 21:06:03 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/GenMakefile.h"
#include "../../inc/utils.h"

static int	is_valid_file(const char *filename, char *type)
{
	// Ignorer les fichiers .gch
	if (strstr(filename, ".gch"))
		return (0);
	// Vérifie si le fichier correspond au type (par exemple .h ou .c)
	if (strstr(filename, type))
		return (1);
	return (0);
}

// Fonction pour supprimer un préfixe donné d'un chemin
static const char	*strip_prefix(const char *path, const char *prefix)
{
	size_t	prefix_len = strlen(prefix);

	if (strncmp(path, prefix, prefix_len) == 0)
		return (path + prefix_len);
	return (path);
}

static void	append_file(char *src_buffer, size_t *offset, 
				size_t buffer_size, const char *file_path, char *type)
{
	size_t	written;
	char	*base;

	if (type[1] == 'h')
		base = "$(INC)/%s ";
	else
		base = "$(DIR)/%s ";
	written = snprintf(src_buffer + *offset, buffer_size - *offset, base, file_path);
	if (written < 0 || written >= buffer_size - *offset)
	{
		write(2, "Buffer overflow while building SRC\n", 36);
		exit(EXIT_FAILURE);
	}
	*offset += written;
}

void	scan_files(const char *dir_path, char *src_buffer, 
				size_t buffer_size, size_t *offset, char *type)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		statbuf;
	char			full_path[1024];

	dir = opendir(dir_path);
	if (!dir)
	{
		perror("Erreur d'ouverture du répertoire");
		exit(EXIT_FAILURE);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		// Ignore les entrées spéciales . et ..
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;
		// Construire le chemin complet
		snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
		// Récupére les informations du fichier
		if (stat(full_path, &statbuf) == -1)
		{
			perror("Erreur avec stat");
			closedir(dir);
			exit(EXIT_FAILURE);
		}

		// Si c'est un dossier, appele récursive
		if (S_ISDIR(statbuf.st_mode))
		{
			scan_files(full_path, src_buffer, buffer_size, offset, type);
		}
		// Si c'est un fichier valide, ajoute le au buffer
		else if (is_valid_file(entry->d_name, type))
		{
			// Supprime dynamiquement le préfixe des chemins (par exemple "src/")
			const char *relative_path = strip_prefix(full_path, "src/");
			if (type[1] == 'h') // Si c'est un header, utiliser "inc/" comme préfixe
				relative_path = strip_prefix(full_path, "inc/");
			append_file(src_buffer, offset, buffer_size, relative_path, type);
		}
	}

	closedir(dir);
}
