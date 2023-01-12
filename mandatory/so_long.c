/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:56:16 by eamghar           #+#    #+#             */
/*   Updated: 2023/01/10 23:13:29 by eamghar          ###   ########.fr       */
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
	mlx_loop(so_long->mlx);
}

int	esc(t_list *so_long)
{
	mlx_clear_window(so_long->mlx, so_long->win);
	exit(0);
}

void	ft_put_nbr(int n)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_put_nbr(nb / 10);
		ft_put_nbr(nb % 10);
	}
}
