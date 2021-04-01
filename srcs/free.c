#include "../includes/cub3d.h"

void	ft_free_tex(t_game *game, t_tex *tex)
{
	if (tex)
	{
		mlx_destroy_image(game->mlx_ptr, tex->tex_ptr);
		free(tex);
		tex = NULL;
	}
}

void	ft_free_img(t_game *game, t_img *img)
{
	if (img)
	{
		mlx_destroy_image(game->mlx_ptr, img->img_ptr);
		free(img);
		img = NULL;
	}
}
