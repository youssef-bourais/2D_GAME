/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:05:48 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/17 17:46:06 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int ft_wall(char **map, int p)
{
	int i = 0;
	int j;
	while (i < ft_len(map[0]) - 1)
	{
		if (map[0][i] != '1')
			return 0;
		i ++;
	}
	i = 0;
	while (i < ft_len(map[p - 1]) - 1)
	{
		if (map[p - 1][i] != '1')
			return 0;
		i ++;
	}
	i = 0;
	while (i < p)
	{
		if (map[i][0] != '1')
			return 0;
		i ++;
	}
	i = ft_len(map[0]) - 2;
	j = 0;
	while (j < p)
	{
		if (map[j][i] != '1')
			return 0;
		j ++;
	}
	return 1;
}

int cheak_rect(char **map, int p)
{
	int i = 1;
	int j;
	int k;
	int n;
	k = ft_len(map[p - 1]);
	j = ft_len(map[0]);
	n = ft_chrch(map[p - 1], '\n'); // 1 or 0
	while (i < p)
	{
		if (j == ft_len(map[i]))
			i ++;
		else if ((j == k && n != 0) || (j == k + 1 && n == 0))
			return 1;
		else
			return 0;
	}
	return 1;
}

int cheak_c(char **map, int p)
{
	int i;
	int j;

	i = 0;
	while (i < p)
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
				return 1;
			else
				j++;
		}
		i ++;
	}
	return 0;
}

int cheak_other(char **map, int p, int t, int *x, int *y)
{
	int i = 0;
	int count = 0;
	int j = 0;

	while (i < p)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == t)
			{
				j ++;
				*x = i;
				*y = j - 1;
				count ++;
			}
			else
				j ++;
		}
		i ++;
	}
	if (count == 1)
			return 1;
	return 0;
}

int valid_path(char **map, int p, int p1, int p2)
{
	int i;
	map[p1][p2] = '-';
	if (map[p1][p2 + 1] != '1' && map[p1][p2 + 1] != '-')
		valid_path(map, p, p1, p2 + 1);
	if (map[p1 + 1][p2] != '1' && map[p1 + 1][p2] != '-')
		valid_path(map, p, p1 + 1, p2);
	if (map[p1][p2 - 1] != '1' && map[p1][p2 - 1] != '-')
		valid_path(map, p, p1, p2 - 1);
	if (map[p1 - 1][p2] != '1' && map[p1 - 1][p2] != '-')
		valid_path(map, p, p1 - 1, p2);
	i = 0;
	while (i < p)
	{
		if(ft_chrch(map[i], 'C') == 1 || ft_chrch(map[i], 'E') == 1)
			return 0;
		i ++;
	}
	return 1;
}
int check_valid_map(char **map, char **visited, int p, int *e1, int *e2, int *p1, int *p2)
{
    if (cheak_c(map, p) == 1 && cheak_rect(map, p) == 1 && ft_wall(map, p) == 1 && cheak_other(map, p, 'E', e1, e2) == 1
        && cheak_other(map, p, 'P', p1, p2) == 1 && valid_path(visited, p, *p1, *p2) == 1)
        return 1;
    else
        return 0;
}
