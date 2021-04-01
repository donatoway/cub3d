#include "../includes/cub3d.h"

t_img		*ft_new_image(t_game *game, int width, int height)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	if (!(img->img_ptr = mlx_new_image(game->mlx_ptr, width, height)))
		return (NULL);
	if (!(img->img_data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
		&img->size_line, &img->endian)))
		return (NULL);
	img->width = width;
	img->height = height;
	return (img);
}

void		pixel_tex(t_tex *tex, t_game *game)
{
	if (tex->width * game->ray.tex_y + game->ray.tex_x < (tex->width *\
				tex->height))
		game->color = tex->tex_data[tex->width * game->ray.tex_y +\
					game->ray.tex_x];
}

char		*get_output_wall(t_game *game)
{
	if (game->ray.stepx < 0 && game->ray.rmapx < (int)game->ray.\
rposx && game->ray.wall == 0)
	{
		pixel_tex(game->tex_e, game);
		return (game->arg.ea);
	}
	if (game->ray.stepx > 0 && game->ray.rmapx > (int)game->ray.rposx\
	&& game->ray.wall == 0)
	{
		pixel_tex(game->tex_w, game);
		return (game->arg.we);
	}
	if (game->ray.stepy < 0 && game->ray.rmapy < (int)game->ray.rposy &&\
	game->ray.wall - 0)
	{
		pixel_tex(game->tex_n, game);
		return (game->arg.no);
	}
	if (game->ray.stepy > 0 && game->ray.rmapy > (int)\
	game->ray.rposy && game->ray.wall == 1)
		pixel_tex(game->tex_s, game);
	return (game->arg.so);
}

char		*pix_color(t_game *game, int sprite)
{
	char	*output;

	output = NULL;

	if (!sprite)
		output = get_output_wall(game);
	if (sprite && game->ray.sprite)
	{
		pixel_tex(game->tex_sprite, game);
		output = game->arg.sprite;
	}
	return (output);
}
