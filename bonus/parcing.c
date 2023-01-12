/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:31:45 by eamghar           #+#    #+#             */
/*   Updated: 2023/01/11 13:02:48 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_get_map_lines(char *map)
{
	int		fd1;
	int		lines;
	char	s;

	fd1 = open(map, O_RDONLY);
	if (fd1 < 3)
	{
		ft_putstr("Error\nFd error\n");
		exit(0);
	}
	lines = 0;
	while (read(fd1, &s, 1))
	{
		if (s == '\n')
		lines++;
	}
	if (lines == 0)
	{
		ft_putstr("Error\nempty map\n");
		exit(0);
	}
	close(fd1);
	lines++;
	return (lines);
}

void	ft_read_map(t_list *so_long, char *map)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 3)
	{
		ft_putstr("Error\nFd error\n");
		exit(0);
	}
	so_long->height = ft_get_map_lines(map);
	so_long->map = (char **)ft_calloc(so_long->height + 1, sizeof(char *));
	if (!so_long->map)
		return (ft_error());
	while (i < so_long->height)
		so_long->map[i++] = get_next_line(fd);
	so_long->map[i] = 0;
	i = 0;
	while (so_long->map[0][i] != '\n' && so_long->map[0][i])
		i++;
	so_long->width = i;
	if (so_long->width * 64 > 5120 || so_long->height * 64 > 2880)
		ft_error();
}

void	ft_check_width(t_list *so_long)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j] != '\n' && so_long->map[i][j])
			j++;
		if (j != so_long->width)
		{
			ft_putstr("Error\nThe map width is wrong\n");
			exit(0);
		}
	i++;
	}
}

void	ft_check_components(t_list *so_long)
{
	int		i;
	int		j;

	i = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] != '1' && so_long->map[i][j] != '0'
			&& so_long->map[i][j] != 'C' && so_long->map[i][j] != 'P'
			&& so_long->map[i][j] != 'E' && so_long->map[i][j] != 'N')
				ft_norminette();
			if (so_long->map[i][j] == 'C')
				so_long->c++;
			else if (so_long->map[i][j] == 'E')
				so_long->e++;
			else if (so_long->map[i][j] == 'P')
				so_long->p++;
			j++;
		}
	i++;
	}
}

void	ft_valid_map(t_list *so_long, char *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_check_ber(map);
	ft_read_map(so_long, map);
	ft_check_width(so_long);
	if (so_long->width == so_long->height)
	{
		ft_putstr("Error\nMap should always be rectangular!!\n");
		exit(0);
	}
	ft_check_components(so_long);
	ft_check_duplicates(so_long);
	if (ft_check_walls(so_long) == 0)
	{
		ft_putstr("Error\nMap sould be surrounded by walls !!\n");
		exit(0);
	}
	ft_player_position(so_long);
	ft_check_exit(so_long);
}
