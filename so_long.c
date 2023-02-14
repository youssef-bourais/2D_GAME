/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:44:43 by ybourais          #+#    #+#             */
/*   Updated: 2023/02/14 10:57:07 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

char **read_map(int fd ,int *p)
{
	char *line;
	char **tab;
	int i = 0;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		i ++;
	}
	close(fd);
	tab = (char **)malloc(sizeof(char *)*(i));
	fd = open("map/map.ber", O_RDONLY);
	*p = i;
	int j = i;
	i = 0;
	while (i < j)
	{
		tab[i] = get_next_line(fd);
		i ++;
	}
	close(fd);
	return tab;
}

typedef struct  s_vars
{
    void        *mlx;
    void        *win;
}               t_vars;

int key;

int     key_hook(int keycode, t_vars *vars)
{
	key = keycode;
	static int i = 1;
    if (keycode == 123)
        printf("left\t%d\n", i++);
    else if (keycode == 124)
        printf("right\t%d\n", i++);
    else if (keycode == 125)
        printf("down\t%d\n", i++);
    else if (keycode == 126)
        printf("up\t%d\n",i++);
	else if (keycode == 53)
	{
        mlx_destroy_window(vars->mlx, vars->win);
       	exit(1);
	}
    return 0;
}

void move_game(char **map, int p, int key)
{
	int i = 0;
	int j = 0;

		if (map[i][j] != '1')
		{
			if (key == 124)
			{
				map[i][j] = '0';
				map[i][j + 1] = 'P';
			}
			if (key == 123)
			{
				map[i][j] = '0';
				map[i][j - 1] = 'P';
			}
			if (key == 125)
			{
				map[i][j] = '0';
				map[i + 1][j] = 'P';
			}
			if (key == 126)
			{
				map[i][j] = '0';
				map[i - 1][j] = 'P';
			}
		}
		(void)p;
}

void implement_map(char **map, int p)
{
	t_vars start;
	void	*img_p;
	void	*img_w;
	void	*img_e;
	void	*img_g;
	void	*img_c;
	char	*path_w = "image/wall.xpm";
	char	*path_g = "image/ground.xpm";
	char	*path_p = "image/player.xpm";
	char	*path_c = "image/coins.xpm";
	char	*path_e = "image/exit.xpm";
	int		size;
	int i;
	int j;

    start.mlx = mlx_init();
	img_p = mlx_xpm_file_to_image(start.mlx, path_p, &size, &size);
	img_w = mlx_xpm_file_to_image(start.mlx, path_w, &size, &size);
	img_g = mlx_xpm_file_to_image(start.mlx, path_g, &size, &size);
	img_e = mlx_xpm_file_to_image(start.mlx, path_e, &size, &size);
	img_c = mlx_xpm_file_to_image(start.mlx, path_c, &size, &size);

    start.win = mlx_new_window(start.mlx, (ft_len(map[0]) - 1)*size, p*size, "HUNTER_X_HUNTER");
	// if ((ft_len(map[0]) - 1)*size > sizex || p*size > sizey)
	// 	exit(0);
	i = 0;
	while (i < p)
	{
		j = 0;
		while (j < ft_len(map[0]) - 1)
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(start.mlx, start.win, img_w, j*size, i*size);
			else if (map[i][j] != '1')
			{
				if (map[i][j] == '0')
					mlx_put_image_to_window(start.mlx, start.win, img_g, j*size, i*size);
				else if (map[i][j] == 'C')
					mlx_put_image_to_window(start.mlx, start.win, img_c, j*size, i*size);
				else if (map[i][j] == 'E')
					mlx_put_image_to_window(start.mlx, start.win, img_e, j*size, i*size);
				else if (map[i][j] == 'P')
					mlx_put_image_to_window(start.mlx, start.win, img_p, j*size, i*size);
			}
			j ++;
		}
		i ++;
	}
    mlx_key_hook(start.win, &key_hook, &start);
	mlx_loop(start.mlx);
}

int	main(void)
{
	char **temp;
	int fd = open("map/map.ber", O_RDONLY);
	int i = 0;
	int p;
	temp = read_map(fd, &p);

	int p1,p2;
	int e1,e2;
	char **visited;
	visited = (char **)malloc(sizeof(char *)*p);
		i = 0;
		while (i < p)
		{
			int j = 0;
			visited[i] = (char *)malloc(sizeof(char) * ft_len(temp[0])); 
			while (j < ft_len(temp[0]))
			{
				visited[i][j] = temp[i][j];
				j ++;
			}
			visited[i][j] = '\0';
			i ++;
		}
	if (cheak_c(temp, p) == 1 && cheak_rect(temp, p) == 1 && ft_wall(temp, p) == 1 && cheak_other(temp, p, 'E', &e1, &e2) == 1
		&& cheak_other(temp, p, 'P', &p1, &p2) == 1 && valid_path(visited, p, p1, p2) == 1)
	{
		printf("valid map\n");
		implement_map(temp,p);	
		free(temp);
	}
	else
	{
		perror("Error\n");
		printf("the map is not valid\n");
	}
	i = 0;
	while (i < p)
	{
		free(visited[i]);
		i ++;
	}
	free(visited);
}
