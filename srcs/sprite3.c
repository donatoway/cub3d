#include "../includes/cub3d.h"

void		calc_end_start(t_game *game)
{
	int		tmp;

	if (game->sprite.drawstart_y < 0)
		game->sprite.drawstart_y = 0;
	game->sprite.drawend_y = game->sprite.sprite_height / 2 + game->height / 2;
	if (game->sprite.drawend_y >= game->height)
		game->sprite.drawend_y = game->height - 1;
	game->sprite.sprite_width = abs((int)(game->height / (game->sprite.transy)))\
							* 0.85;
	game->sprite.drawstart_x = -game->sprite.sprite_width / 2 +\
	game->sprite.spritescreenx;
	if (game->sprite.drawstart_x < 0)
		game->sprite.drawstart_x = 0;
	game->sprite.drawend_x = game->sprite.sprite_width / 2 + \
	game->sprite.spritescreenx;
	if (game->sprite.drawend_x >= game->width)
		game->sprite.drawend_x = game->width - 1;
	tmp = game->sprite.drawend_x;
}

void		ft_sprite_calc(t_game *game, int i)
{
	double	inv;

	game->sprite.spcamx = 1 * (game->sprite_tab[game->ray.sprite_order[i]].\
	pos_x - game->player_x);
	game->sprite.spcamy = game->sprite_tab[game->ray.sprite_order[i]].pos_y\
	- game->player_y;
	inv = -1.0 / (game->ray.planex * game->ray.diry - game->ray.dirx *
		game->ray.planey);
	game->sprite.transx = inv * (game->ray.diry * game->sprite.spcamx - \
	game->ray.dirx * game->sprite.spcamy);
	game->sprite.transy = inv * (game->ray.planey * game->sprite.spcamx\
	- game->ray.planex * game->sprite.spcamy);
	game->sprite.spritescreenx = (int)((game->width / 2) * (1 +  \
	game->sprite.transx / game->sprite.transy));
	game->sprite.sprite_height = abs((int)(game->height / game->sprite.transy));
	game->sprite.drawstart_y = -game->sprite.sprite_height / 2 + game->height / 2;
	calc_end_start(game);
}

int			sprite_put_pixel(t_game *game, int i, int y)
{
	game->color = game->sprite_tab[i].tex->tex_data[game->sprite_tab[i].\
	tex->width * game->sprite.sp_y + game->sprite.sp_x];
	if (game->color != 0x0000ff && game->color != 0x0003ff)
	{
		if (!game->img)
			if ((game->img = ft_new_image(game, game->width, game->height)) == NULL)
			{
				game->error = IMG_ERROR;
				ft_exit(game);
				return (IMG_ERROR);
			}
		game->img->width = game->width;
		game->img->height = game->height;
		if (ft_put_pixel(game->img, game->color, game->sprite.stripe, y) != \
				SUCCESS)
			return (PIXEL_ERROR);
	}
	return (SUCCESS);
}
/*
void		check_if_sprite_shot(t_game *game, int i)
{
	if ((game->sprite.stripe >= game->shot_box_x && game->\
	sprite.stripe <= game->shot_box_x + game->shot_box_size)\
	&& (game->sprite.sp_y >= game->shot_box_y && game->sprite.sp_y\
	<= game->shot_box_y + game->shot_box_size))
	{
		game->ennemy_can_be_shot = 1;
		game->ennemy_be_shot_x = (int)game->sprite_tab[i].tex->sprite_x;
		game->ennemy_be_shot_y = (int)game->sprite_tab[i].tex->sprite_y;
	}
	else
		game->ennemy_can_be_shot = 0;
}
*/
int			add_sprite_two(t_game *game, int i)
{
	int		d;
	int		y;
	int		height;
	int		width;

	width = 2;
	height = 1;
	y = game->sprite.drawstart_y;
	if (game->sprite.transy > 0 && game->sprite.stripe > 0
	&& game->sprite.stripe < game->width && game->sprite.transy
	< game->ray.zbuffer[game->sprite.stripe])
	{
		while (y < game->sprite.drawend_y)
		{
			d = y * width - game->height * height + game->sprite.sprite_height\
				* height;
			game->sprite.sp_y = ((d * game->sprite_tab[i].tex->height) /\
			game->sprite.sprite_height) / width;
			if (sprite_put_pixel(game, i, y) != SUCCESS)
				return (sprite_put_pixel(game, i, y));
			y++;
		}
	}
	return (SUCCESS);
}

