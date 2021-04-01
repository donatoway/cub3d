#include "../includes/cub3d.h"

void		start_ray(t_game *game, int x)
{
	game->ray.camera = 2 * x / (double)(game->width) - 1;
	game->ray.rposx = game->player_x;
	game->ray.rposy = game->player_y;
	game->ray.rdirx = -game->ray.dirx + game->ray.planex * game->ray.camera;
	game->ray.rdiry = -game->ray.diry + game->ray.planey * game->ray.camera;
	game->ray.rmapx = (int)game->ray.rposx;
	game->ray.rmapy = (int)game->ray.rposy;
	game->ray.rdisdx = sqrt(1 + (game->ray.rdiry * game->ray.rdiry) /
		(game->ray.rdirx * game->ray.rdirx));
	game->ray.rdisdy = sqrt(1 + (game->ray.rdirx * game->ray.rdirx) /
		(game->ray.rdiry * game->ray.rdiry));
	game->ray.hit = 0;
	game->ray.sprite = 0;
}

void		direction_ray(t_game *game)
{
	if (game->ray.rdirx > 0)
	{
		game->ray.stepx = -1;
		game->ray.rdistx = (game->ray.rposx - game->ray.rmapx) * game->ray.rdisdx;
	}
	else
	{
		game->ray.stepx = 1;
		game->ray.rdistx = (game->ray.rmapx + 1.0 - game->ray.rposx) *
			game->ray.rdisdx;
	}
	if (game->ray.rdiry > 0)
	{
		game->ray.stepy = -1;
		game->ray.rdisty = (game->ray.rposy - game->ray.rmapy) * game->ray.rdisdy;
	}
	else
	{
		game->ray.stepy = 1;
		game->ray.rdisty = (game->ray.rmapy + 1.0 - game->ray.rposy) *
			game->ray.rdisdy;
	}
}

char		get_wall_tex(t_game *game)
{
	char	wall_tex;

	if (game->ray.wall == 0)
	{
		if (game->ray.stepx > 0 && game->ray.rmapx > \
		(int)game->ray.rposx && game->ray.wall == 0)
			wall_tex = 'W';
		if (game->ray.stepx < 0 && game->ray.rmapx < (int)\
		game->ray.rposx && game->ray.wall == 0)
			wall_tex = 'E';
	}
	if (game->ray.wall == 1)
	{
		if (game->ray.stepy > 0 && game->ray.rmapy > (int)game->ray.\
		rposy && game->ray.wall == 1)
			wall_tex = 'S';
		if (game->ray.stepy < 0 && game->ray.rmapy < (int)game->ray.\
		rposy && game->ray.wall - 0)
			wall_tex = 'N';
	}
	return (wall_tex);
}

char		hit(t_game *game, char wall_tex)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.rdistx < game->ray.rdisty)
		{
			game->ray.rdistx += game->ray.rdisdx;
			game->ray.rmapx += game->ray.stepx;
			game->ray.wall = 0;
		}
		else
		{
			game->ray.rdisty += game->ray.rdisdy;
			game->ray.rmapy += game->ray.stepy;
			game->ray.wall = 1;
		}
		if (!ft_strchr("023ENSW", game->map[game->ray.rmapy]\
					[game->ray.rmapx]))
			game->ray.hit = 1;
		wall_tex = get_wall_tex(game);
	}
	return (wall_tex);
}

void		size_ray(t_game *game)
{
	if (game->ray.wall == 0)
		game->ray.dist = fabs((game->ray.rmapx - game->ray.rposx
					+ (1 - game->ray.stepx) / 2) / game->ray.rdirx);
	if (game->ray.wall == 1)
		game->ray.dist = fabs((game->ray.rmapy - game->ray.rposy
					+ (1 - game->ray.stepy) / 2) / game->ray.rdiry);
	game->ray.rayh = fabs((game->height / game->ray.dist));
	game->ray.rayh -= game->height / 50;
	game->ray.wstart = (-1 * (game->ray.rayh)) / 2 + game->height / 2;
	game->ray.wend = game->ray.rayh / 2 + game->height / 2;
	game->ray.spstart = (-1 * fabs((game->height / game->ray.sprite_dist)))\
					/ 2 + game->height / 2;
	game->ray.spstart = (game->ray.spstart < 0) ? 0 : game->ray.spstart;
	game->ray.spend = (fabs((game->height / game->ray.sprite_dist))) / 2\
					+ game->height / 2;
	game->ray.spend = (game->ray.spend > game->height) ? game->height : \
					game->ray.spend;
	if (game->ray.wstart < 0)
		game->ray.wstart = 0;
	if (game->ray.wend >= game->height)
		game->ray.wend = game->height - 1;
}
