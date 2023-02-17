/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:07:51 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/17 17:51:20 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
#include "get_next_line.h"

typedef struct  s_vars
{
    void        *mlx;
    void        *win;
	int	fd;
	void	*img_p;
	void	*img_w;
	void	*img_e;
	void	*img_g;
	void	*img_c;
	int		size;
	char **map;
	int p;
	int p1;
	int p2;
	int e1;
	int e2;
}             t_vars;

int ft_wall(char **map, int p);
int cheak_rect(char **map, int p);
int cheak_c(char **map, int p);
int cheak_other(char **map, int p, int t, int *x, int *y);
int valid_path(char **map, int p, int p1, int p2);
int check_valid_map(char **map, char **visited, int p, int *e1, int *e2, int *p1, int *p2);
void ft_copie_table(char **copie, char **map, int p);
void ft_free_table(char **map, int p);
char *ft_strdup(char *s1);
int coin_nbr(t_vars *start);
char **read_map(int fd ,int *p);
int ft_close(void);
void ft_exit(t_vars *start);
void ft_error(void);
void implement_map(t_vars *start);
void ft_image(t_vars *start);
void ft_put_image(t_vars *start);
int	key_hook(int code, t_vars *start);

#endif