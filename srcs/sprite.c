#include "../includes/cub3d.h"

void	get_sprite_tex(t_game *game, int x, int y, int i)
{
	game->sprite_tab[i].pos_x = x + 0.5;
	game->sprite_tab[i].pos_y = y + 0.5;
	if (game->map[y][x] == '2')
		game->sprite_tab[i].tex = game->tex_sprite;
/*	if (game->map[y][x] == '3')
		game->sprite_tab[i].tex = game->tex_sprite1;
	if (game->map[y][x] == 'D')
		game->sprite_tab[i].tex = game->tex_door;
	if (game->map[y][x] == 'B')
		game->sprite_tab[i].tex = game->tex_bonus;
	if (game->map[y][x] == 'A')
		game->sprite_tab[i].tex = game->tex_ammo;
	if (game->map[y][x] == 'O')
		get_ennemy_sprite(game, i);
	if (game->map[y][x] == 'T')
		game->sprite_tab[i].tex = game->tex_treasure;
	*/
	game->sprite_tab[i].tex->sprite_x = x;
	game->sprite_tab[i].tex->sprite_y = y;
}

int		sprite2(t_game *game)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x] && i < game->sprite_count)
		{
			if (ft_strchr("2", game->map[y][x]))
			{
				get_sprite_tex(game, x, y, i);
				i++;
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int		sprite(t_game *game)
{
	int	i;

	i = 0;
	if (!(game->sprite_tab = malloc(sizeof(t_sprite) * (game->sprite_count + 1))))
		return (MALLOC_ERROR);
	if (!(game->ray.sprite_order = malloc(sizeof(int) * game->sprite_count)))
		return (MALLOC_ERROR);
	if (!(game->ray.dist_sp = malloc(sizeof(double) * game->sprite_count)))
		return (MALLOC_ERROR);
	sprite2(game);
	reorder_sprite(game);
	if (game->sprite_tab)
		free(game->sprite_tab);
	if (game->ray.sprite_order)
		free(game->ray.sprite_order);
	if (game->ray.sprite_dist)
		free(game->ray.dist_sp);
	return (SUCCESS);
}
