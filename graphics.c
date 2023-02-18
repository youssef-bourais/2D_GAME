/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:16:26 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/18 22:09:38 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image(t_vars *start)
{
	start->img_p = mlx_xpm_file_to_image(start->mlx, "textures/player.xpm",
			&start->size, &start->size);
	start->img_w = mlx_xpm_file_to_image(start->mlx, "textures/wall.xpm",
			&start->size, &start->size);
	start->img_g = mlx_xpm_file_to_image(start->mlx, "textures/ground.xpm",
			&start->size, &start->size);
	start->img_e = mlx_xpm_file_to_image(start->mlx, "textures/exit.xpm",
			&start->size, &start->size);
	start->img_c = mlx_xpm_file_to_image(start->mlx, "textures/coins.xpm",
			&start->size, &start->size);
	start->img_d = mlx_xpm_file_to_image(start->mlx, "textures/exit_d.xpm",
			&start->size, &start->size);
}

void	ft_close_s(t_vars *start)
{
	mlx_destroy_image(start->mlx, start->img_p);
	mlx_destroy_image(start->mlx, start->img_w);
	mlx_destroy_image(start->mlx, start->img_g);
	mlx_destroy_image(start->mlx, start->img_e);
	mlx_destroy_image(start->mlx, start->img_d);
	mlx_destroy_window(start->mlx, start->win);
	ft_free_table(start->map, start->p);
	exit(1);
}

void	modified_walk(int code, t_vars *start)
{
	if (code == 123 && start->map[start->p1][(start->p2) - 1] != '1')
	{
		if (start->map[start->p1][(start->p2) - 1] != 'E')
			start->map[start->p1][(start->p2) - 1] = 'P';
	}
	else if (code == 124 && start->map[start->p1][(start->p2) + 1] != '1')
	{
		if (start->map[start->p1][(start->p2) + 1] != 'E')
			start->map[start->p1][(start->p2) + 1] = 'P';
	}
	else if (code == 125 && start->map[(start->p1) + 1][start->p2] != '1')
	{
		if (start->map[(start->p1) + 1][start->p2] != 'E')
			start->map[(start->p1) + 1][start->p2] = 'P';
	}
	else if (code == 126 && start->map[(start->p1) - 1][start->p2] != '1')
	{
		if (start->map[(start->p1) - 1][start->p2] != 'E')
			start->map[(start->p1) - 1][start->p2] = 'P';
	}
}

void	ft_devide_fct(int code, t_vars *start)
{
	if (code == 123 && start->map[start->p1][(start->p2) - 1] != '1')
	{
		modified_walk(code, start);
		ft_exit_0(code, start);
		start->p2 = start->p2 - 1;
		implement_map(start);
	}
	else if (code == 124 && start->map[start->p1][(start->p2) + 1] != '1')
	{
		modified_walk(code, start);
		ft_exit_0(code, start);
		start->p2 = start->p2 + 1;
		implement_map(start);
	}
}

int	key_hook(int code, t_vars *start)
{
	ft_plot(code, start);
	ft_exit(code, start);
	number_mvt(code, start);
	ft_devide_fct(code, start);
	if (code == 125 && start->map[(start->p1) + 1][start->p2] != '1')
	{
		modified_walk(code, start);
		ft_exit_0(code, start);
		start->p1 = start->p1 + 1;
		implement_map(start);
	}
	else if (code == 126 && start->map[(start->p1) - 1][start->p2] != '1')
	{
		modified_walk(code, start);
		ft_exit_0(code, start);
		start->p1 = start->p1 - 1;
		implement_map(start);
	}
	else if (code == 53)
		ft_close_s(start);
	return (0);
}
