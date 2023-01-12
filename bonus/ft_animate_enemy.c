/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_enemy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:57:39 by eamghar           #+#    #+#             */
/*   Updated: 2023/01/10 21:47:37 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_next_frame1(t_list *so_Long, int i, int x, int y)
{
	if (i == 0)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy0.xpm", &x, &y);
	if (i == 5)
	so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy1.xpm", &x, &y);
	if (i == 10)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy2.xpm", &x, &y);
	if (i == 15)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy3.xpm", &x, &y);
	if (i == 20)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy4.xpm", &x, &y);
	if (i == 25)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy5.xpm", &x, &y);
	if (i == 30)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy6.xpm", &x, &y);
	if (i == 35)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy7.xpm", &x, &y);
	return (i);
}

int	ft_next_frame2(t_list *so_Long, int i, int x, int y)
{
	if (i == 40)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy8.xpm", &x, &y);
	if (i == 45)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy9.xpm", &x, &y);
	if (i == 50)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy10.xpm", &x, &y);
	if (i == 55)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy11.xpm", &x, &y);
	if (i == 60)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy12.xpm", &x, &y);
	if (i == 65)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy13.xpm", &x, &y);
	if (i == 70)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy14.xpm", &x, &y);
	if (i == 75)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy15.xpm", &x, &y);
	return (i);
}

int	ft_next_frame3(t_list *so_Long, int i, int x, int y)
{
	if (i == 80)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy16.xpm", &x, &y);
	if (i == 85)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy17.xpm", &x, &y);
	if (i == 90)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy18.xpm", &x, &y);
	if (i == 95)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy19.xpm", &x, &y);
	if (i == 100)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy20.xpm", &x, &y);
	if (i == 105)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy21.xpm", &x, &y);
	if (i == 110)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy22.xpm", &x, &y);
	if (i == 115)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy23.xpm", &x, &y);
	return (i);
}

int	ft_next_frame4(t_list *so_Long, int i, int x, int y)
{
	if (i == 120)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy24.xpm", &x, &y);
	if (i == 125)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy25.xpm", &x, &y);
	if (i == 130)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy26.xpm", &x, &y);
	if (i == 135)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy27.xpm", &x, &y);
	if (i == 140)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy28.xpm", &x, &y);
	if (i == 145)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy29.xpm", &x, &y);
	if (i == 150)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy30.xpm", &x, &y);
	if (i == 155)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy31.xpm", &x, &y);
	return (i);
}

int	ft_next_frame5(t_list *so_Long, int i, int x, int y)
{
	if (i == 160)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy32.xpm", &x, &y);
	if (i == 165)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy33.xpm", &x, &y);
	if (i == 170)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy34.xpm", &x, &y);
	if (i == 175)
		so_Long->win_n = mlx_xpm_file_to_image(so_Long->mlx,
				"bonus/pixels/enemy/enemy35.xpm", &x, &y);
	return (i);
}
