#include "../includes/cub3d.h"

void	ft_rotate(t_game *game, int advance)
{
	double	dir;
	double	plane;

	dir = game->ray.dirx;
	plane = game->ray.planex;
	game->ray.dirx = game->ray.dirx * cos(advance * 0.1)
		- game->ray.diry * sin(advance * 0.1);
	game->ray.diry = dir * sin(advance * 0.1)
		+ game->ray.diry * cos(advance * 0.1);
	game->ray.planex = game->ray.planex * cos(advance * 0.1)
		- game->ray.planey * sin(advance * 0.1);
	game->ray.planey = plane * sin(advance * 0.1)
		+ game->ray.planey * cos(advance * 0.1);
}

void	move_up(t_game *game)
{
	if (ft_strchr("0SWEN", game->map[(int)(game->player_y)]\
	[(int)(game->player_x + game->ray.dirx * game->ray.speed)]))
		game->player_x += game->ray.dirx * game->ray.speed;
	if (ft_strchr("0SWEN", game->map[(int)(game->player_y + \
		game->ray.diry * game->ray.speed)][(int)(game->player_x)]))
		game->player_y += game->ray.diry * game->ray.speed;
}

void	up_down(t_game *game)
{
	if (game->move.up == 1)
	{
		move_up(game);
	}
	if (game->move.down == 1)
	{
		if (ft_strchr("0SWEN", game->map[(int)(game->player_y)][(int)\
			(game->player_x - game->ray.dirx * game->ray.speed)]))
			game->player_x -= game->ray.dirx * game->ray.speed;
		if (ft_strchr("0SWEN", game->map[(int)(game->player_y - \
			game->ray.diry * game->ray.speed)][(int)(game->player_x)]))
			game->player_y -= game->ray.diry * game->ray.speed;
	}
}

void	straf(t_game *game)
{
	if (game->move.strafl == 1)
	{
		if (ft_strchr("0SWEN", game->map[(int)(game->player_y - game->\
		ray.dirx * game->ray.speed)][(int)(game->player_x)]))
			game->player_y += -game->ray.dirx * game->ray.speed;
		if (ft_strchr("0SWEN", game->map[(int)(game->player_y)][(int)\
		(game->player_x
			+ game->ray.diry * game->ray.speed)]))
			game->player_x += game->ray.diry * game->ray.speed;
	}
	if (game->move.strafr == 1)
	{
		if (ft_strchr("0SWEN", game->map[(int)(game->player_y + game->\
		ray.dirx * game->ray.speed)][(int)(game->player_x)]))
			game->player_y -= -game->ray.dirx * game->ray.speed;
		if (ft_strchr("0SWEN", game->map[(int)(game->player_y)][(int)\
		(game->player_x - game->ray.diry * game->ray.speed)]))
			game->player_x -= game->ray.diry * game->ray.speed;
	}
}

void	ft_move(t_game *game)
{
	//int pos;

	if (game->move.up == 1 || game->move.down == 1)
		up_down(game);
	if (game->move.strafr == 1 || game->move.strafl == 1)
		straf(game);
	if (game->move.left == 1)
		ft_rotate(game, -1);
	if (game->move.right == 1)
		ft_rotate(game, 1);
/*	pos = game->map[(int)(game->player_y)][(int)(game->player_x)];
	if (pos == 'B')
		ft_bonus(game);
	if (pos == 'A')
		ft_reload_ammo(game);
	if (pos == 'O')
		ft_ennemy(game);
	if (pos == 'T')
		game->treasure_caught = 1;
	if (pos == 'T')
		game->sprite_count--;
	if (ft_strchr("BAT", pos))
		game->map[(int)(game->player_y)][(int)(game->player_x)] = '0';
	if (pos == 'T')
		ft_next_level(game);
	*/
}
