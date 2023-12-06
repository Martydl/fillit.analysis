/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:40:39 by mde-laga          #+#    #+#             */
/*   Updated: 2019/02/02 10:50:11 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(char *square, int *tetri, int letter)
{
	int i;

	i = -1;
	while (++i < 4)
		if (square[tetri[i]] != '.')
			return (-1);
	while (--i >= 0)
		square[tetri[i]] = 'A' + letter;
	return (1);
}

int		ft_del_tetri(char *square, int letter)
{
	int i;
	int ret;

	i = -1;
	ret = -1;
	while (square[++i])
		if (square[i] == 'A' + letter && (square[i] = '.'))
			ret = 0;
	return (ret);
}

char	*ft_new_sq(int **list, char *square, int size)
{
	ft_upleft_all(list, size);
	ft_convert_coor(list, size, size + 1);
	square = ft_create_square(square, size + 1);
	return (square);
}

int		ft_backtrack(char **square, int **list, int size, int nb)
{
	static int	z = 0;

	if (z == nb)
		return (1);
	if (ft_del_tetri(*square, z) == -1 || ft_next(list[z], size) == 1)
		while (1)
		{
			if (ft_check(*square, list[z], z) == 1 && (z += 1))
				if (ft_backtrack(square, list, size, nb) == 1)
					return (1);
			if (ft_next(list[z], size) != 1)
			{
				ft_upleft(list[z--], size);
				ft_del_tetri(*square, z);
				break ;
			}
		}
	if (z == -1 && (*square = ft_new_sq(list, *square, size++)) != NULL)
	{
		z = 0;
		if (ft_backtrack(square, list, size, nb) == 1)
			return (1);
	}
	return (0);
}
