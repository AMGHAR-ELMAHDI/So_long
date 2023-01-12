/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamghar <eamghar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:42:11 by eamghar           #+#    #+#             */
/*   Updated: 2023/01/10 23:24:49 by eamghar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_list
{
	void	*mlx;
	void	*win;
	void	*win_0;
	void	*win_1;
	void	*win_p;
	void	*win_e;
	void	*win_c;
	int		*win_n;
	char	**map;
	int		width;
	int		height;
	int		moves;
	int		py;
	int		px;
	int		ey;
	int		ex;
	int		cy;
	int		cx;
	int		i;
	int		o;
	int		j;
	int		c;
	int		e;
	int		p;
}				t_list;

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_valid_map(t_list *so_long, char *map);
void	ft_error(void);
int		ft_get_map_lines(char *map);
void	ft_check_width(t_list *so_long);
void	ft_read_map(t_list *so_long, char *map);
void	ft_check_components(t_list *so_long);
int		ft_check_walls(t_list *so_long);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_check_duplicates(t_list *so_long);
void	ft_check_ber(char *map);
void	ft_player_position(t_list *so_long);
void	ft_player_position2(t_list *so_long, int i, int j);
int		ft_backtracking(char **map, int x, int y);
void	ft_print_map(t_list *so_long, int x, int y);
int		esc(t_list *so_long);
int		key_hook(int keycode, t_list *so_long);
void	ft_variables_to_print(t_list *so_long, int x, int y);
void	ft_print(t_list *so_long);
char	*ft_itoa(int n);
int		ft_next_frame(t_list *so_Long);
int		ft_next_frame1(t_list *so_Long, int i, int x, int y);
int		ft_next_frame2(t_list *so_Long, int i, int x, int y);
int		ft_next_frame3(t_list *so_Long, int i, int x, int y);
int		ft_next_frame4(t_list *so_Long, int i, int x, int y);
int		ft_next_frame5(t_list *so_Long, int i, int x, int y);
int		ft_check_exit(t_list *so_long);
char	*ft_strdup(const char *s1);
void	ft_enemy_random(int *x, int *y);
void	ft_move_enemy(t_list *so_long);
void	ft_move_enemy2(t_list *so_long, int i, int j);
void	ft_end_of_game(t_list *so_long);
int		ft_animate_tits(t_list *so_Long);
void	ft_exit(t_list *so_long);
int		ft_move_up(int keycode, t_list *so_long, int x, int y);
int		ft_move_right(int keycode, t_list *so_long, int x, int y);
int		ft_move_down(int keycode, t_list *so_long, int x, int y);
int		ft_move_left(int keycode, t_list *so_long, int x, int y);
void	ft_clear_map(t_list *so_long);
void	ft_print_position(t_list *so_long, int x, int y);
void	ft_print_position2(t_list *so_long);
void	ft_putstr(char *s);
void	ft_putchar(int c);
void	ft_put_nbr(int n);
void	ft_norminette(void);

#endif
