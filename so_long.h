/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:07:51 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/19 10:18:37 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZEX 2560
# define SIZEY 1440

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_vars
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*img_p;
	void	*img_w;
	void	*img_e;
	void	*img_g;
	void	*img_c;
	void	*img_d;
	int		fd;
	int		size;
	int		p;
	int		p1;
	int		p2;
	int		e1;
	int		e2;
}	t_vars;

void	ft_copie_table(char **copie, char **map, int p);
void	ft_free_table(char **map, int p);
void	ft_exit(int code, t_vars *start);
void	ft_error(t_vars *start);
void	implement_map(t_vars *start);
void	ft_image(t_vars *start);
void	ft_put_image(t_vars *start);
void	ft_close_s(t_vars *start);
void	ft_image_condition(t_vars *start, int i, int j);
void	ft_exit_0(int code, t_vars *start);
void	ft_plot(int code, t_vars *start);
void	number_mvt(int code, t_vars *start);
void	putnbr(int nb);
void	modified_walk(int code, t_vars *start);
void	ft_devide_fct(int code, t_vars *start);
int		ft_wall(char **map, int p);
int		cheak_rect(char **map, int p);
int		cheak_c(char **map, int p);
int		cheak_other_1(char **map, int p, int *x, int *y);
int		cheak_other_2(char **map, int p, int *x, int *y);
int		valid_path(char **map, int p, int p1, int p2);
int		check_valid_map(char **map, int p, int *p1, int *p2);
int		cheak_char(char **map, int p);
int		ft_curfull(t_vars *start);
int		coin_nbr(t_vars *start);
int		key_hook(int code, t_vars *start);
int		ft_close(t_vars *start);
int		ft_w(char **map, int p);
char	*ft_strdup(char *s1);
char	**read_map(int fd, int *p);

#endif
