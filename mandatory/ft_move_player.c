/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:55:52 by eamghar           #+#    #+#             */
/*   Updated: 2023/01/10 23:02:57 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_list *so_long)
{
	int			x;
	int			y;
	static int	once;

	x = 0;
	y = 0;
	once = 0;
	if (keycode == 53)
	{
		mlx_clear_window(so_long->mlx, so_long->win);
		exit(0);
	}
	if (so_long->moves == 0)
	{
		ft_put_nbr(so_long->moves);
		ft_putchar('\n');
	}
	ft_move_up(keycode, so_long, x, y);
	ft_move_right(keycode, so_long, x, y);
	ft_move_down(keycode, so_long, x, y);
	ft_move_left(keycode, so_long, x, y);
	if (so_long->c == 1)
		so_long->win_c = mlx_xpm_file_to_image(so_long->mlx,
				"mandatory/pixels/final_pokeball.xpm", &x, &y);
	return (0);
}

int	ft_move_up(int keycode, t_list *so_long, int x, int y)
{
	if (keycode == 13 || keycode == 126)
	{
		if (so_long->map[so_long->px - 1][so_long->py] == 'E'
			&& so_long->c == 0)
			ft_exit(so_long);
		if (so_long->map[so_long->px - 1][so_long->py] == '1'
		|| so_long->map[so_long->px - 1][so_long->py] == 'E')
			return (0);
		if (so_long->map[so_long->px - 1][so_long->py] == 'C')
			so_long->c--;
		mlx_destroy_image(so_long->mlx, so_long->win_p);
		so_long->map[so_long->px][so_long->py] = '0';
		so_long->px -= 1;
		so_long->map[so_long->px][so_long->py] = 'P';
		so_long->win_p = mlx_xpm_file_to_image(so_long->mlx,
				"mandatory/pixels/pikachu_down.xpm", &x, &y);
		ft_print_map(so_long, x, y);
		ft_put_nbr(++so_long->moves);
		ft_putchar('\n');
	}
	return (0);
}

int	ft_move_right(int keycode, t_list *so_long, int x, int y)
{
	if (keycode == 2 || keycode == 124)
	{
		if (so_long->map[so_long->px][so_long->py + 1] == 'E'
			&& so_long->c == 0)
			ft_exit(so_long);
		if (so_long->map[so_long->px][so_long->py + 1] == '1'
		|| so_long->map[so_long->px][so_long->py + 1] == 'E')
			return (0);
		if (so_long->map[so_long->px][so_long->py + 1] == 'C')
			so_long->c--;
		mlx_destroy_image(so_long->mlx, so_long->win_p);
		so_long->map[so_long->px][so_long->py] = '0';
		so_long->py += 1;
		so_long->map[so_long->px][so_long->py] = 'P';
		so_long->win_p = mlx_xpm_file_to_image(so_long->mlx,
				"mandatory/pixels/pikachu_right.xpm", &x, &y);
		ft_print_map(so_long, x, y);
		ft_put_nbr(++so_long->moves);
		ft_putchar('\n');
	}
	return (0);
}

int	ft_move_down(int keycode, t_list *so_long, int x, int y)
{
	if (keycode == 1 || keycode == 125)
	{
		if (so_long->map[so_long->px + 1][so_long->py] == 'E'
			&& so_long->c == 0)
			ft_exit(so_long);
		if (so_long->map[so_long->px + 1][so_long->py] == '1'
			|| so_long->map[so_long->px + 1][so_long->py] == 'E')
			return (0);
		if (so_long->map[so_long->px + 1][so_long->py] == 'C')
			so_long->c--;
		mlx_destroy_image(so_long->mlx, so_long->win_p);
		so_long->map[so_long->px][so_long->py] = '0';
		so_long->px += 1;
		so_long->map[so_long->px][so_long->py] = 'P';
		so_long->win_p = mlx_xpm_file_to_image(so_long->mlx,
				"mandatory/pixels/pikachu_up.xpm", &x, &y);
		ft_print_map(so_long, x, y);
		ft_put_nbr(++so_long->moves);
		ft_putchar('\n');
	}
	return (0);
}

int	ft_move_left(int keycode, t_list *so_long, int x, int y)
{
	if (keycode == 0 || keycode == 123)
	{
		if (so_long->map[so_long->px][so_long->py - 1] == 'E'
				&& so_long->c == 0)
			ft_exit(so_long);
		if (so_long->map[so_long->px][so_long->py - 1] == '1'
			|| so_long->map[so_long->px][so_long->py - 1] == 'E')
			return (0);
		if (so_long->map[so_long->px][so_long->py - 1] == 'C')
			so_long->c--;
		mlx_destroy_image(so_long->mlx, so_long->win_p);
		so_long->map[so_long->px][so_long->py] = '0';
		so_long->py -= 1;
		so_long->map[so_long->px][so_long->py] = 'P';
		so_long->win_p = mlx_xpm_file_to_image(so_long->mlx,
				"mandatory/pixels/pikachu_left.xpm", &x, &y);
		ft_print_map(so_long, x, y);
		ft_put_nbr(++so_long->moves);
		ft_putchar('\n');
	}
	return (0);
}
