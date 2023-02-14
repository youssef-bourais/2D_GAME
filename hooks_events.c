#include "get_next_line.h"
#include "so_long.h"

typedef struct  s_vars
{
    void        *mlx;
    void        *win;
}               t_vars;

int     key_hook(int keycode, t_vars *vars)
{
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

int main(void)
{
    t_vars vars;
	
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 75, 75, "test");
    mlx_key_hook(vars.win, &key_hook, &vars);

    mlx_loop(vars.mlx);
}
