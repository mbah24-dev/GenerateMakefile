/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GenMakefile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:06:48 by mbah              #+#    #+#             */
/*   Updated: 2024/12/23 21:20:42 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/GenMakefile.h"
#include "../inc/utils.h"

int	main(void)
{
	t_makefile	makefile;
	int			fd;
	char		src_buffer[4096] = {0};
	char		inc_buffer[4096] = {0};
	size_t		offset;
	

	makefile = makefile_constants();
	offset = 0;
	fd = open("./makefile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (an_error(fd, "./src", "./inc"))
		return (1);
	scan_files("src", src_buffer, sizeof(src_buffer), &offset, ".c");
	offset = 0;
	scan_files("inc", inc_buffer, sizeof(inc_buffer), &offset, ".h");
	write_makefile_with_signature("./makefile");
	safe_write(fd, makefile.make_header, ft_strlen(makefile.make_header));
	write_makefile(fd, inc_buffer, 'i');
	write_makefile(fd, parse_src_files_buffer(src_buffer), 's');
	safe_write(fd, makefile.make_footer, ft_strlen(makefile.make_footer));
	close(fd);
    printf("                                                                                \n");
	printf("🔥 Bienvenue dans ForgeMaker,(Mamadou BAH 😎)le forgeron des Makefiles ! 🔧\n");
    printf("%s\n", YELLOW);
	printf("*    __ __   ___           _____  ______   __  __    ____     ______    _   __  ______ *\n");
	printf("*   / // /  |__ \\         / ___/ /_  __/  / / / /   / __ \\   / ____/   / | / / /_  __/ *\n");
	printf("*  / // /_  __/ /         \\__ \\   / /    / / / /   / / / /  / __/     /  |/ /   / /    *\n");
	printf("* /__  __/ / __/         ___/ /  / /    / /_/ /   / /_/ /  / /___    / /|  /   / /     *\n");
	printf("*   /_/   /____/        /____/  /_/     \\____/   /_____/  /_____/   /_/ |_/   /_/      *\n");
	printf("                                                                                \n");
	printf("                                                                                \n");
	printf("*     ______   ____     ____    ______    ______           __  ___    ___     __ __    ______    ____ *\n");
	printf("*    / ____/  / __ \\   / __ \\  / ____/   / ____/          /  |/  /   /   |   / //_/   / ____/   / __ \\ *\n");
	printf("*   / /_     / / / /  / /_/ / / / __    / __/            / /|_/ /   / /| |  / ,<     / __/     / /_/ / *\n");
	printf("*  / __/    / /_/ /  / _, _/ / /_/ /   / /___           / /  / /   / ___ | / /| |   / /___    / _, _/  *\n");
	printf("* /_/       \\____/  /_/ |_|  \\____/   /_____/          /_/  /_/   /_/  |_|/_/ |_|  /_____/   /_/ |_|   *\n");
	printf("                                                                                \n");
	printf("%s", RESET);
	printf("   Makefile généré/mis à jour avec succès ✅🎉\n");
	printf("                                                                                \n");
	return (0);
}
