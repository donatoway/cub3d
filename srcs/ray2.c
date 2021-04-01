#include "../includes/cub3d.h"

int			ft_get_tex_height(t_game *game, char tex)
{
	int		height;

	height = 64;
	if (tex == 'E')
		height = game->tex_e->height;
	if (tex == 'N')
		height = game->tex_n->height;
	if (tex == 'W')
		height = game->tex_w->height;
	if (tex == 'S')
		height = game->tex_s->height;
	return (height);
}

int			ft_get_tex_width(t_game *game, char tex)
{
	int		width;

	width = 64;
	if (tex == 'E')
		width = game->tex_e->width;
	if (tex == 'N')
		width = game->tex_n->width;
	if (tex == 'W')
		width = game->tex_w->width;
	if (tex == 'S')
		width = game->tex_s->width;
	return (width);
}

void		wall_texture(t_game *game, char tex)
{
	double	wallx;
	int		height;
	int		width;

	width = ft_get_tex_width(game, tex);
	height = ft_get_tex_height(game, tex);
	if (game->ray.wall == 0)
		wallx = game->ray.rposy - game->ray.dist * game->ray.rdiry;
	else
		wallx = game->ray.rposx - game->ray.dist * game->ray.rdirx;
	wallx -= (int)wallx;
	game->ray.tex_x = (int)(wallx * width);
	if (game->ray.wall == 0)
		game->ray.tex_x = width + game->ray.tex_x;
	else if (game->ray.wall == 1)
		game->ray.tex_x = width + game->ray.tex_x - 1;
	game->ray.step_tex = 1 * width / game->ray.rayh;
	game->ray.tex_pos = (game->ray.wstart - game->height / 2\
	+ game->ray.rayh / 2) * game->ray.step_tex - 1;
}
