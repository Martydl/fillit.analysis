/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-laga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:26:25 by mde-laga          #+#    #+#             */
/*   Updated: 2019/01/25 15:30:35 by mde-laga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_up_or_left(int *p, int sp, int dec)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < sp || i < dec)
	{
		tmp = i * sp;
		j = 0;
		while (j < 4)
		{
			if (p[j] == tmp)
				return (0);
			j++;
		}
		i++;
	}
	i = -1;
	while (++i < 4)
		p[i] = p[i] - dec;
	return (1);
}

void	ft_upleft_all(int **list, int size)
{
	int i;

	i = -1;
	while (list[++i] != NULL)
	{
		while (ft_up_or_left(list[i], 1, size))
			;
		while (ft_up_or_left(list[i], size, 1))
			;
	}
}

void	ft_upleft(int *tetri, int size)
{
	while (ft_up_or_left(tetri, 1, size))
		;
	while (ft_up_or_left(tetri, size, 1))
		;
}

int		ft_down1left(int *tetri, int size)
{
	int i;

	i = -1;
	while (++i < 4)
		if (tetri[i] + size >= size * size)
			return (-1);
	while (ft_up_or_left(tetri, size, 1))
		;
	while (--i >= 0)
		tetri[i] += size;
	return (1);
}

int		ft_next(int *tetri, int size)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (tetri[i] + 1 >= size * size)
			return (-1);
		if ((tetri[i] + 1) % size == 0)
		{
			if (ft_down1left(tetri, size) == 1)
				return (1);
			else
				return (-1);
		}
	}
	while (--i >= 0)
		tetri[i] += 1;
	return (1);
}
