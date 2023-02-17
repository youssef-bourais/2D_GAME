/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:16:26 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/17 17:52:15 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

void ft_image(t_vars *start)
{
	start->img_p = mlx_xpm_file_to_image(start->mlx, "textures/player.xpm", &start->size, &start->size);
	start->img_w = mlx_xpm_file_to_image(start->mlx, "textures/wall.xpm", &start->size, &start->size);
	start->img_g = mlx_xpm_file_to_image(start->mlx, "textures/ground.xpm", &start->size, &start->size);
	start->img_e = mlx_xpm_file_to_image(start->mlx, "textures/exit.xpm", &start->size, &start->size);
	start->img_c = mlx_xpm_file_to_image(start->mlx, "textures/coins.xpm", &start->size, &start->size);
}

void ft_put_image(t_vars *start)
{
	int i;
	int j;
	i = 0;
	while (i < start->p)
	{
		j = 0;
		while (j < ft_len(start->map[0]) - 1)
		{
			if (start->map[i][j] == '1')
				mlx_put_image_to_window(start->mlx, start->win, start->img_w, j*(start->size), i*(start->size)); // (y, x) == (j, i)
			else if (start->map[i][j] == '0')
				mlx_put_image_to_window(start->mlx, start->win, start->img_g, j*(start->size), i*(start->size));
			else if (start->map[i][j] == 'C')
				mlx_put_image_to_window(start->mlx, start->win, start->img_c, j*(start->size), i*(start->size));
			else if (start->map[i][j] == 'E')
				mlx_put_image_to_window(start->mlx, start->win, start->img_e, j*(start->size), i*(start->size));
			else if (start->map[i][j] == 'P')
				mlx_put_image_to_window(start->mlx, start->win, start->img_p, j*(start->size), i*(start->size));
			j ++;
		}
		i ++;
	}	
}

void ft_exit(t_vars *start)
{
	if (coin_nbr(start) == 0 && start->map[start->p1][(start->p2) - 1] == 'E')
	{
		start->map[start->p1][(start->p2)-- - 1] = 'P';
		exit(0);
	}
	if (coin_nbr(start) == 0 && start->map[start->p1][(start->p2) + 1] == 'E')
	{
		start->map[start->p1][(start->p2)++ + 1] = 'P';
		exit(0);
	}	
	if (coin_nbr(start) == 0 && start->map[(start->p1) + 1][start->p2] == 'E')
	{
		start->map[(start->p1) + 1][start->p2] = 'P';
		exit(0);
	}
	if (coin_nbr(start) == 0 && start->map[(start->p1) - 1][start->p2] == 'E')
	{
		start->map[(start->p1) - 1][start->p2] = 'P';
		exit(0);
	}
}

int	key_hook(int code, t_vars *start)
{
	static int c = 1;
	if (code == 123 || code == 124 || code == 125 || code == 126)
		start->map[start->p1][start->p2] = '0';
	if (code == 123 && ((start->map[start->p1][(start->p2) - 1] == 'C' || start->map[start->p1][(start->p2) - 1] == '0') || (coin_nbr(start) == 0 && start->map[start->p1][(start->p2) - 1] == 'E'))) // left
	{
		ft_exit(start);
		start->map[start->p1][(start->p2)-- - 1] = 'P';
		printf("mouvement number %d\n", c++);
		implement_map(start);
	}
	if (code == 124 && ((start->map[start->p1][(start->p2) + 1] == 'C' || start->map[start->p1][(start->p2) + 1] == '0') || (coin_nbr(start) == 0 && start->map[start->p1][(start->p2) + 1] == 'E'))) // right
	{
		ft_exit(start);
		start->map[start->p1][(start->p2)++ + 1] = 'P';
		printf("mouvement number %d\n", c++);
		implement_map(start);
	}
    if (code == 125 && ((start->map[(start->p1) + 1][start->p2] == 'C' || start->map[(start->p1) + 1][start->p2] == '0') || (coin_nbr(start) == 0 && start->map[(start->p1) + 1][start->p2] == 'E'))) // down
	{
		ft_exit(start);
		start->map[(start->p1)++ + 1][start->p2] = 'P';
		printf("mouvement number %d\n", c++);
		implement_map(start);
	}
    if (code == 126 && ((start->map[(start->p1) - 1][start->p2] == 'C' || start->map[(start->p1) - 1][start->p2] == '0')|| (coin_nbr(start) == 0 && start->map[(start->p1) - 1][start->p2] == 'E'))) // up
	{
		ft_exit(start);	
		start->map[(start->p1)-- - 1][start->p2] = 'P';
		printf("mouvement number %d\n", c++);
		implement_map(start);
	}
	if (code == 53)
       	exit(0);
    return 0;
}

int ft_close(void)
{
	exit(0);
}
