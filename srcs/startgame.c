#include "../includes/cub3d.h"

int			buffer_ray(t_game *game)
{
	if (!(game->ray.zbuffer = malloc(sizeof(double) * (game->width + 1))))
		return (BUFF_ERR);
	return (SUCCESS);
}

void		launch_game_orientation(t_game *game)
{
	if (game->orientation == 'N')
	{
		game->ray.diry = -0.99;
		game->ray.planex = -0.80;
	}
	if (game->orientation == 'S')
	{
		game->ray.diry = 0.99;
		game->ray.planex = 0.80;
	}
	if (game->orientation == 'E')
	{
		game->ray.dirx = 0.99;
		game->ray.planey = -0.80;
	}
	if (game->orientation == 'W')
	{
		game->ray.dirx = -0.99;
		game->ray.planey = 0.80;
	}
}

void		launch_game_2(t_game *game, t_arg arg)
{
	game->width = arg.screen_width;
	game->height = arg.screen_height;
	game->floor = from_rgb_to_hex(arg.floor);
	game->ceil = from_rgb_to_hex(arg.ceil);
	game->arg = arg;
	launch_game_orientation(game);
	game->mlx_ptr = mlx_init();
	game->player_x += 0.5;
	game->player_y += 0.5;
}

t_game		start_game(t_arg arg)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	ft_bzero(&game.ray, sizeof(t_ray));
	get_arg_for_game(&game, arg, 0, 0);
	game.ray.speed = 0.1;
	if (!(game.map = from_lst_to_tab(arg.map)))
	{
		game.error = FROM_LST_ERROR;
		ft_error(game.error, &game);
	}
	launch_game_2(&game, arg);
	launch_game_orientation(&game);
	start_texture(&game);
	game.map_height = ft_lstsize_map(game.arg.map);
	if ((game.error = buffer_ray(&game)) != SUCCESS)
		ft_error(game.error, &game);
	sprite(&game);
	return (game);
}
