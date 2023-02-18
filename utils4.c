/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:34:14 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/18 22:40:27 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int cheak_other_2(char **map, int p, int *x, int *y)
{
	int i;
	int count;
	int j;

	i = 0;
	count = 0;
	while (i < p)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				j ++;
				count ++;
			}
			j ++;
		}
		i ++;
	}
	return count;
}