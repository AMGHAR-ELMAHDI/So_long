/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:57:30 by eamghar           #+#    #+#             */
/*   Updated: 2023/01/10 23:22:45 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_exit(t_list *so_long)
{
	ft_putstr("\n\n\n\t\t\t\t\t\t\t\tYOU WON!!!!!\n\n\n");
	mlx_clear_window(so_long->mlx, so_long->win);
	exit(0);
}

void	ft_variables_to_print(t_list *so_long, int x, int y)
{
	so_long->mlx = mlx_init();
	so_long->win = mlx_new_window(so_long->mlx, so_long->width * 64,
			so_long->height * 64, "My Window");
	if (!so_long->mlx || !so_long->win)
		ft_error();
	so_long->win_0 = mlx_xpm_file_to_image(so_long->mlx,
			"bonus/pixels/grass1.xpm", &x, &y);
	so_long->win_1 = mlx_xpm_file_to_image(so_long->mlx,
			"bonus/pixels/wall1.xpm", &x, &y);
	so_long->win_p = mlx_xpm_file_to_image(so_long->mlx,
			"bonus/pixels/pikachu_up.xpm", &x, &y);
	so_long->win_c = mlx_xpm_file_to_image(so_long->mlx,
			"bonus/pixels/small_red_ball.xpm", &x, &y);
	so_long->win_e = mlx_xpm_file_to_image(so_long->mlx,
			"bonus/pixels/closed_door1.xpm", &x, &y);
	so_long->win_n = mlx_xpm_file_to_image(so_long->mlx,
			"bonus/pixels/enemy/enemy0.xpm", &x, &y);
}

void	ft_print_map(t_list *so_long, int x, int y)
{
	so_long->i = 0;
	so_long->j = 0;
	x = 0;
	while (so_long->map[x])
	{
		y = 0;
		so_long->i = 0;
		while (so_long->map[x][y] && so_long->map[x][y] != '\n')
		{
			ft_print_position(so_long, x, y);
			so_long->i += 64;
			y += 1;
		}
		so_long->j += 64;
		x += 1;
	}
}

void	ft_print_position(t_list *so_long, int x, int y)
{
	if (!so_long->win_0 || !so_long->win_p || !so_long->win_c
		|| !so_long->win_e || !so_long->win_n || !so_long->win_1)
	{
		ft_putstr("Error\nWrong xpm file!!\n");
		exit(0);
	}
	if (so_long->map[x][y] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->win_1, so_long->i, so_long->j);
	else
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->win_0, so_long->i, so_long->j);
	if (so_long->map[x][y] == 'P')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->win_p, so_long->i, so_long->j);
	if (so_long->map[x][y] == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->win_c, so_long->i + 16, so_long->j + 14);
	if (so_long->map[x][y] == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->win_e, so_long->i, so_long->j);
	if (so_long->map[x][y] == 'N')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->win_n, so_long->i, so_long->j);
	ft_print_position2(so_long);
}

void	ft_print_position2(t_list *so_long)
{
	char	*str;

	if (so_long->c == 1)
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->win_e, so_long->ey * 64, so_long->ex * 64);
	str = ft_itoa(so_long->moves);
	mlx_string_put(so_long->mlx, so_long->win, 0, 0, 0xCD5C5C, str);
	free(str);
}
