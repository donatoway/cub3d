#include "../includes/cub3d.h"

int			ft_put_pixel(t_img *img, unsigned int color, int p_x, int p_y)
{
	if (p_y >= img->height || p_x >= img->width || p_x < 0\
	|| p_y < 0 || ((p_y * img->width + p_x) >= (img->width * img->height - 1)))
		return (PIXEL_ERROR);
	img->img_data[p_y * img->width + p_x] = color;
	return (SUCCESS);
}

char		*dispaly_column(t_game *game, int x, char tex, int y)
{
	char	*tex_path;
	int		height;

	if (tex == 'E')
		height = game->tex_e->height;
	if (tex == 'N')
		height = game->tex_n->height;
	if (tex == 'W')
		height = game->tex_w->height;
	if (tex == 'S')
		height = game->tex_s->height;
	while (y < game->ray.wstart)
		ft_put_pixel(game->img, game->ceil, x, y++);
	while (y >= game->ray.wstart && y <= game->ray.wend)
	{
		game->ray.tex_y = (int)game->ray.tex_pos & (height - 1);
		game->ray.tex_pos += game->ray.step_tex;
		tex_path = pix_color(game, 0);
		ft_put_pixel(game->img, game->color, x, y);
		y++;
	}
	while (y < game->height)
		ft_put_pixel(game->img, game->floor, x, y++);
	return (tex_path);
}

int			display_screen(t_game *game, int x)
{
	char tex;

	while (x < game->width)
	{
		start_ray(game, x);
		direction_ray(game);
		tex = hit(game, 0);
		size_ray(game);
		wall_texture(game, tex);
		dispaly_column(game, x++, tex, 0);
		game->ray.zbuffer[x] = game->ray.dist;
	}
	sprite(game);
	if (game->save_flag == 1)
	{
		if (launch_save(game) != SUCCESS)
		{
			ft_putstr("Error : errore durante il salvataggio\n");
			ft_exit(game);
		}
		ft_exit(game);
	}
	return (SUCCESS);
}
