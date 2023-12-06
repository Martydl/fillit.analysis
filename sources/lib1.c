/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algautie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:33:19 by algautie          #+#    #+#             */
/*   Updated: 2019/01/19 17:36:47 by algautie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
	else
		return ;
}

void	ft_putstr(char const *s)
{
	int		i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
	else
		return ;
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!(s2 = (char*)malloc(sizeof(char) * ft_strlen((char*)s1) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(s2 = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		s2[i] = s[start + i];
	s2[i] = '\0';
	return (s2);
}
