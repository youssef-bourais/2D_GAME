/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:40:59 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/18 22:26:04 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_w(char **map, int p)
{
	int	i;

	i = 0;
	while (i < ft_len(map[0]) - 1)
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < ft_len(map[p - 1]) - 1)
	{
		if (map[p - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_wall(char **map, int p)
{
	int	i;
	int	j;

	i = 0;
	if (ft_w(map, p) == 0)
		return (0);
	i = 0;
	while (i < p)
	{
		if (map[i][0] != '1')
			return (0);
		i++;
	}
	i = ft_len(map[0]) - 2;
	j = 0;
	while (j < p)
	{
		if (map[j][i] != '1')
			return (0);
		j++;
	}
	return (1);
}

void	ft_exit(int code, t_vars *start)
{
	int	i;
	int	j;

	i = start->p1;
	j = start->p2;
	if (code == 123 && coin_nbr(start) == 0 && start->map[i][j - 1] == 'E')
		ft_close_s(start);
	if (code == 124 && coin_nbr(start) == 0 && start->map[i][j + 1] == 'E')
		ft_close_s(start);
	if (code == 125 && coin_nbr(start) == 0 && start->map[i + 1][j] == 'E')
		ft_close_s(start);
	if (code == 126 && coin_nbr(start) == 0 && start->map[i - 1][j] == 'E')
		ft_close_s(start);
}

void	ft_exit_0(int code, t_vars *start)
{
	if (code == 123 && coin_nbr(start) != 0 && start->map[start->p1][(start->p2)
		- 1] == 'E')
		start->map[start->p1][(start->p2) - 1] = 'X';
	if (code == 124 && coin_nbr(start) != 0 && start->map[start->p1][(start->p2)
		+ 1] == 'E')
		start->map[start->p1][(start->p2) + 1] = 'X';
	if (code == 125 && coin_nbr(start) != 0 && start->map[(start->p1)
			+ 1][start->p2] == 'E')
		start->map[(start->p1) + 1][start->p2] = 'X';
	if (code == 126 && coin_nbr(start) != 0 && start->map[(start->p1)
			- 1][start->p2] == 'E')
		start->map[(start->p1) - 1][start->p2] = 'X';
}

int	ft_curfull(t_vars *start)
{
	int	i;

	i = 0;
	while (i < start->p)
	{
		if (ft_chrch(start->map[i], 'E') == 1)
			return (0);
		i++;
	}
	return (1);
}
