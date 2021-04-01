#include "../includes/cub3d.h"


int		ft_exit(t_game *game)
{
	if (!game->error)
	{
		ft_free_img(game, game->img);
		ft_free_tex(game, game->tex_s);
		ft_free_tex(game, game->tex_n);
		ft_free_tex(game, game->tex_w);
		ft_free_tex(game, game->tex_e);
		ft_free_tex(game, game->tex_sprite);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	exit(0);
	return (SUCCESS);
}
