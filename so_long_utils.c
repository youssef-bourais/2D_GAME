/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:36:20 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/18 21:17:56 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_len(s1) + 1);
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	ft_copie_table(char **copie, char **map, int p)
{
	int	i;

	i = 0;
	while (i < p)
	{
		copie[i] = ft_strdup(map[i]);
		i++;
	}
}

void	ft_free_table(char **map, int p)
{
	int	i;

	i = 0;
	i = 0;
	while (i < p)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	coin_nbr(t_vars *start)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < start->p)
	{
		j = 0;
		while (j < ft_len(start->map[i]))
		{
			if (start->map[i][j] == 'C')
			{
				count++;
				j++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_error(t_vars *start)
{
	ft_free_table(start->map, start->p);
	write(1, "Error\n", 6);
	exit(1);
}
