/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:19:50 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/18 22:27:12 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_plot(int code, t_vars *start)
{
	if ((code == 123 || code == 124 || code == 125 || code == 126)
		&& ft_curfull(start) == 0)
		start->map[start->p1][start->p2] = '0';
	else if ((code == 123 || code == 124 || code == 125 || code == 126)
		&& ft_curfull(start) == 1)
		start->map[start->p1][start->p2] = 'E';
}

void	putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = (-1) * nb;
	}
	if (nb >= 10)
		putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	number_mvt(int code, t_vars *start)
{
	static int	c = 1;

	if (code == 123 && start->map[start->p1][(start->p2) - 1] != '1')
	{
		write(1, "\nmouvement number ", 18);
		putnbr(c++);
	}
	if (code == 124 && start->map[start->p1][(start->p2) + 1] != '1')
	{
		write(1, "\nmouvement number ", 18);
		putnbr(c++);
	}
	if (code == 125 && start->map[(start->p1) + 1][start->p2] != '1')
	{
		write(1, "\nmouvement number ", 18);
		putnbr(c++);
	}
	if (code == 126 && start->map[(start->p1) - 1][start->p2] != '1')
	{
		write(1, "\nmouvement number ", 18);
		putnbr(c++);
	}
}

int	ft_close(t_vars *start)
{
	ft_close_s(start);
	return (0);
}

int	cheak_char(char **map, int p)
{
	int	i;
	int	j;

	i = 1;
	while (i < p - 1)
	{
		j = 0;
		while (j < ft_len(map[0]) - 2)
		{
			if (ft_chrch(map[i], map[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
