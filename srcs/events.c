#include "../includes/cub3d.h"

int		key1(int key, t_game *game)
{
	if (key == KEY_UP)
		game->move.up = 1;
	if (key == KEY_DOWN)
		game->move.down = 1;
	if (key == ROTATE_LEFT)
		game->move.left = 1;
	if (key == KEY_LEFT)
		game->move.strafl = 1;
	if (key == ROTATE_RIGHT)
		game->move.right = 1;
	if (key == KEY_RIGHT)
		game->move.strafr = 1;
	if (key == KEY_EXIT)
		ft_exit(game);
	return (SUCCESS);
}

int		key2(int key, t_game *game)
{
	if (key == KEY_UP)
		game->move.up = 0;
	if (key == KEY_DOWN)
		game->move.down = 0;
	if (key == ROTATE_LEFT)
		game->move.left = 0;
	if (key == KEY_LEFT)
		game->move.strafl = 0;
	if (key == ROTATE_RIGHT)
		game->move.right = 0;
	if (key == KEY_RIGHT)
		game->move.strafr = 0;
	return (SUCCESS);
}

int		run(t_game *game)
{
	ft_free_img(game, game->img);
	if ((game->img = ft_new_image(game, game->width, game->height)) == NULL)
	{
		game->error = IMG_ERROR;
		ft_error(game->error, game);
		return (IMG_ERROR);
	}
	ft_move(game);
	display_screen(game, 0);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->img_ptr, 0,
		0);
	return (SUCCESS);
}

int		events(t_game game)
{
	while (game.save_flag && game.width % 4)
		game.width++;
	if (game.save_flag)
	{
		if (!(game.win_ptr = mlx_new_window(game.mlx_ptr, 1, 1, "DONNY-Cub3D")))
			return (MLX_ERROR);
	}
	else
	{
		if (!(game.win_ptr = mlx_new_window(game.mlx_ptr, game.width, \
		game.height, "DONNY-Cub3D")))
			return (MLX_ERROR);
	}
	mlx_hook(game.win_ptr, 17, STR_IF_MASK, ft_exit, &game);
	mlx_hook(game.win_ptr, KEYPRESS, KEYPRESSMASK, key1, &game);
	mlx_hook(game.win_ptr, KEYRELEASE, KEYRELEASEMASK, key2, &game);
	mlx_loop_hook(game.mlx_ptr, run, &game);
	mlx_loop(game.mlx_ptr);
	return (SUCCESS);
}
