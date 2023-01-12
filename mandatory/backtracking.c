/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:54:45 by eamghar           #+#    #+#             */
/*   Updated: 2023/01/10 22:58:17 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_exit(t_list *so_long)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = (char **)ft_calloc(sizeof(char *), (so_long->height + 1));
	if (!arr)
		exit(0);
	while (so_long->map[i])
	{
		arr[i] = ft_strdup(so_long->map[i]);
		i++;
	}
	if (ft_backtracking(arr, so_long->px, so_long->py) == 0)
	{
		ft_putstr("Error\nThere is no Path to the Exit\n");
		exit(0);
	}
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (1);
}

int	ft_backtracking(char **map, int x, int y)
{
	if (map[x][y] == 'E')
		return (1);
	if (map[x][y] == '1' )
		return (0);
	map[x][y] = '1';
	if (ft_backtracking(map, x, y + 1))
		return (1);
	if (ft_backtracking(map, x, y - 1))
		return (1);
	if (ft_backtracking(map, x + 1, y))
		return (1);
	if (ft_backtracking(map, x - 1, y))
		return (1);
	return (0);
}

void	ft_check_duplicates(t_list *so_long)
{
	if (so_long->e != 1 || so_long->p != 1 || so_long->c < 1)
	{
		ft_putstr("Error\nCheck the amount of components that you have placed\n");
		exit(0);
	}
}

void	ft_putstr(char *s)
{
	if (s == NULL)
		ft_putstr("(null)");
	while (s && *s)
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}
