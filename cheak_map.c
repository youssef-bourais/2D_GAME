/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 08:05:48 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/19 10:21:04 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cheak_rect(char **map, int p)
{
	int	i;
	int	j;
	int	k;
	int	n;

	i = 1;
	k = ft_len(map[p - 1]);
	j = ft_len(map[0]);
	n = ft_chrch(map[p - 1], '\n');
	while (i < p)
	{
		if (j == ft_len(map[i]))
			i++;
		else if ((j == k && n != 0) || (j == k + 1 && n == 0))
			return (1);
		else
			return (0);
	}
	return (1);
}

int	cheak_c(char **map, int p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p)
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	cheak_other_1(char **map, int p, int *x, int *y)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (i < p)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
			{
				*x = i;
				*y = j;
				j++;
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	valid_path(char **map, int p, int p1, int p2)
{
	int	i;

	map[p1][p2] = '-';
	if ((map[p1][p2 + 1] != '1') && map[p1][p2 + 1] != '-')
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
		if (ft_chrch(map[i], 'C') == 1 || ft_chrch(map[i], 'E') == 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_map(char **map, int p, int *p1, int *p2)
{
	if (cheak_c(map, p) == 1 && cheak_rect(map, p) == 1 && ft_wall(map, p) == 1
		&& cheak_other_2(map, p, p1, p2) == 1 && cheak_char(map, p) == 1)
		return (1);
	else
		return (0);
}
