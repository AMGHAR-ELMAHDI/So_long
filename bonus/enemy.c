/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:58:39 by eamghar           #+#    #+#             */
/*   Updated: 2023/01/11 12:34:55 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_enemy_random(int *x, int *y)
{
	int		res;

	*x = rand() % 3 - 1;
	*y = rand() % 3 - 1;
	res = rand() % 2;
	if (res)
		*x = 0;
	else
		*y = 0;
}

void	ft_move_enemy(t_list *so_long)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j] && so_long->map[i][j] != '\n')
		{
			if (so_long->map[i][j] == 'N')
				ft_move_enemy2(so_long, i, j);
			j++;
		}
		i++;
	}
}

void	ft_move_enemy2(t_list *so_long, int i, int j)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_enemy_random(&x, &y);
	if (so_long->map[i + x][j + y] == 'P')
		ft_end_of_game(so_long);
	if (so_long->map[i + x][j + y] == '0')
	{
		so_long->map[i][j] = '0';
		so_long->map[i + x][j + y] = 'N';
	}
}

void	ft_end_of_game(t_list *so_long)
{
	ft_putstr("\n\n\n\t\t\t\t\t\t\t\tYOU DIED!!!!\n\n\n");
	mlx_clear_window(so_long->mlx, so_long->win);
	exit(0);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}
