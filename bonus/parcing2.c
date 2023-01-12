/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:58:41 by eamghar           #+#    #+#             */
/*   Updated: 2023/01/10 23:21:33 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_walls(t_list *so_long)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (so_long->map[i][j] == '1')
	j++;
	if (so_long->width != j)
		return (0);
	j--;
	while (so_long->map[i] && so_long->map[i][j] == '1')
	i++;
	if (so_long->map[i])
		return (0);
	i--;
	while (so_long->map[i][j] == '1' && j > 0)
	j--;
	if (j != 0)
		return (0);
	while (so_long->map[i][j] == '1' && i > 0)
	i--;
	if (i != 0 || j != 0)
		return (0);
	return (1);
}

void	ft_check_ber(char *map)
{
	int		result;

	result = ft_strcmp(map + ft_strlen(map) - 4, ".ber");
	if (result == 0)
		return ;
	else
	{
		ft_putstr("Error\nWrong file extension, try '.ber'\n");
		exit(0);
	}
}

void	ft_clear_map(t_list *so_long)
{
	so_long->i = 0;
	while (so_long->map[so_long->i])
		free(so_long->map[so_long->i++]);
	free(so_long->map);
}

void	ft_norminette(void)
{
	ft_putstr("Error\nWrong component\n");
	exit(0);
}
