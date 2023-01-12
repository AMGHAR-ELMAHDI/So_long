/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_functions1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:27:47 by eamghar           #+#    #+#             */
/*   Updated: 2023/01/11 12:36:50 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		*p++ = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero (p, size * count);
	return (p);
}

void	ft_player_position(t_list *so_long)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			ft_player_position2(so_long, i, j);
			j++;
		}
		i++;
	}
}

void	ft_player_position2(t_list *so_long, int i, int j)
{
	if (so_long->map[i][j] == 'P')
	{
		so_long->px = i;
		so_long->py = j;
	}
	if (so_long->map[i][j] == 'E')
	{
		so_long->ex = i;
		so_long->ey = j;
	}
	if (so_long->map[i][j] == 'C')
	{
		so_long->cx = i;
		so_long->cy = j;
	}
}
