#include "../includes/cub3d.h"

int			sprite_count(t_game *game)
{
	int		x;
	int		y;
	int		result;

	y = 0;
	result = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (ft_strchr("2", game->map[y][x]))
				result++;
			x++;
		}
		y++;
	}
	return (result);
}

void		add_sprite(t_game *game)
{
	int		i;
	int		height;

	i = 0;
	height = 256;
	while (i < game->sprite_count)
	{
		ft_sprite_calc(game, i);
		game->sprite.stripe = game->sprite.drawstart_x;
		while (game->sprite.stripe < game->sprite.drawend_x)
		{
			game->sprite.sp_x = (int)(height * (game->sprite.stripe\
			- (-game->sprite.sprite_width / 2 + game->sprite.spritescreenx)) * \
			game->sprite_tab[i].tex->width / game->sprite.sprite_width / height);
			add_sprite_two(game, i);
			game->sprite.stripe++;
		}
		i++;
	}
}

void		ft_sort(int *order, double *dist, int num, t_game *game)
{
	int		i;
	int		temp;
	double	temp2;
	t_tex	*temp3;

	i = 0;
	while (i < num - 1)
	{
		if (dist[i] < dist[i + 1])
		{
			temp3 = game->sprite_tab[i + 1].tex;
			game->sprite_tab[i + 1].tex = game->sprite_tab[i].tex;
			game->sprite_tab[i].tex = temp3;
			temp2 = dist[i + 1];
			dist[i + 1] = dist[i];
			dist[i] = temp2;
			temp = order[i + 1];
			order[i + 1] = order[i];
			order[i] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void		reorder_sprite(t_game *game)
{
	int		i;

	i = 0;
	game->sprite_count = sprite_count(game);
	while (i < game->sprite_count)
	{
		game->ray.sprite_order[i] = i;
		game->ray.dist_sp[i] = ((game->player_x - game->sprite_tab[i].pos_x) *
			(game->player_x - game->sprite_tab[i].pos_x) +
			(game->player_y - game->sprite_tab[i].pos_y) *
			(game->player_y - game->sprite_tab[i].pos_y));
		i++;
	}
	ft_sort(game->ray.sprite_order, game->ray.dist_sp, game->sprite_count, game);
	add_sprite(game);
}
