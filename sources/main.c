/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:25:50 by mde-laga          #+#    #+#             */
/*   Updated: 2019/02/02 10:44:59 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(char *line, char **tab, int **list)
{
	int i;

	i = -1;
	if (line)
		ft_strdel(&line);
	if (tab)
		while (tab[++i] != NULL)
			ft_strdel(&tab[i]);
	free(tab);
	if (list)
		ft_freelist(list);
	ft_putstr("error\n");
	exit(0);
}

void	ft_use(void)
{
	ft_putstr("usage: ./fillit file\n");
	exit(-1);
}

void	ft_freelist(int **list)
{
	int i;

	i = -1;
	while (list[++i])
		ft_memdel((void**)&list[i]);
	free(list);
}

int		**ft_getlist(int **list, int fd)
{
	char	*line;
	char	**tab;
	int		i;

	line = NULL;
	tab = NULL;
	if (!line && (!(line = ft_strnew(1))))
		ft_error(line, NULL, NULL);
	line = ft_getline(fd, line);
	ft_strlen(line) == 0 ? ft_error(line, tab, list) : 0;
	if (ft_verifline(line) == -1)
		ft_error(line, tab, list);
	tab = ft_cutline(line, tab);
	ft_strdel(&line);
	i = -1;
	while (tab[++i])
	{
		if (ft_check_neighbours(tab[i]) == -1)
			ft_error(line, tab, list);
		if (!(tab[i] = ft_delret(tab[i])))
			ft_error(line, tab, list);
	}
	list = ft_create_list(list, tab);
	return (list);
}

int		main(int ac, char **av)
{
	int		fd;
	int		**list;
	char	*square;
	int		nb;
	int		size;

	ac != 2 ? ft_use() : 0;
	fd = open(av[1], O_RDONLY);
	fd == -1 ? ft_error(NULL, NULL, NULL) : 0;
	list = NULL;
	list = ft_getlist(list, fd);
	nb = 0;
	while (list[nb])
		nb++;
	size = ft_smallest_square(nb);
	ft_upleft_all(list, 4);
	while (ft_convert_coor(list, 4, size) == -1)
		size++;
	square = NULL;
	square = ft_create_square(square, size);
	ft_backtrack(&square, list, size, nb) == 0 ? ft_error(NULL, NULL, list) : 0;
	ft_print_sq(square);
	ft_strdel(&square);
	ft_freelist(list);
	return (0);
}
