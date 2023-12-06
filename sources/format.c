/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:41:03 by algautie          #+#    #+#             */
/*   Updated: 2019/02/01 09:40:40 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_delret(char *piece)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_strdup(piece);
	ft_strdel(&piece);
	if (!(piece = (char*)malloc(sizeof(char) * 17)))
		return (NULL);
	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (tmp[i] != '\n')
			piece[j++] = tmp[i];
		i++;
	}
	piece[j] = '\0';
	ft_strdel(&tmp);
	return (piece);
}

int		*ft_convert_tetri(int *tetri, char *piece)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (piece[++i])
		if (piece[i] == '#')
			tetri[j++] = i;
	tetri[j] = -1;
	ft_strdel(&piece);
	return (tetri);
}

int		**ft_create_list(int **list, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (!(list = (int**)malloc(sizeof(int*) * (i + 1))))
		ft_error(NULL, tab, list);
	list[i] = NULL;
	while (--i >= 0)
	{
		if (!(list[i] = (int*)malloc(sizeof(int) * 5)))
			ft_error(NULL, tab, list);
	}
	while (tab[++i])
		list[i] = ft_convert_tetri(list[i], tab[i]);
	free(tab);
	return (list);
}
