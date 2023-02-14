/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:07:51 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/13 09:20:16 by ybourais         ###   ########.fr       */
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

int ft_wall(char **map, int p);
int cheak_rect(char **map, int p);
int cheak_c(char **map, int p);
int cheak_other(char **map, int p, int t, int *x, int *y);
char **read_map(int fd ,int *p);
int equal(char **map, int x, int y);
int valid_path(char **map, int p, int p1, int p2);
void implement_map(char **map, int p);

#endif