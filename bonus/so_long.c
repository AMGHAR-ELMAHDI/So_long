/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:56:16 by eamghar           #+#    #+#             */
/*   Updated: 2023/01/10 21:26:22 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_list	so_long;

	if (ac != 2)
		ft_error();
	ft_valid_map(&so_long, av[1]);
	ft_print(&so_long);
	return (0);
}

void	ft_print(t_list *so_long)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_variables_to_print(so_long, x, y);
	ft_print_map(so_long, x, y);
	so_long->moves = 0;
	mlx_hook(so_long->win, 2, 1L << 0, key_hook, so_long);
	mlx_hook(so_long->win, 17, 1L << 0, esc, so_long);
	mlx_loop_hook(so_long->mlx, ft_next_frame, so_long);
	mlx_loop(so_long->mlx);
}

int	esc(t_list *so_long)
{
	mlx_clear_window(so_long->mlx, so_long->win);
	exit(0);
}
