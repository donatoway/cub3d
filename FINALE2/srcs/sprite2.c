/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:41:48 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/04/02 19:41:51 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			sprite_count(t_env *env)
{
	int		x;
	int		y;
	int		result;

	y = 0;
	result = 0;
	while (y < env->map_height)
	{
		x = 0;
		while (env->map[y][x])
		{
			if (ft_strchr("2", env->map[y][x]))
				result++;
			x++;
		}
		y++;
	}
	return (result);
}

void		add_sprite(t_env *env)
{
	int		i;
	int		height;

	i = 0;
	height = 256;
	while (i < env->sprite_count)
	{
		ft_sprite_calc(env, i);
		env->sprite.stripe = env->sprite.drawstart_x;
		while (env->sprite.stripe < env->sprite.drawend_x)
		{
			env->sprite.sp_x = (int)(height * (env->sprite.stripe\
			- (-env->sprite.sprite_width / 2 + env->sprite.spritescreenx)) * \
			env->sprite_tab[i].tex->width / env->sprite.sprite_width / height);
			add_sprite_two(env, i);
			env->sprite.stripe++;
		}
		i++;
	}
}

void		ft_sort(int *order, double *dist, int num, t_env *env)
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
			temp3 = env->sprite_tab[i + 1].tex;
			env->sprite_tab[i + 1].tex = env->sprite_tab[i].tex;
			env->sprite_tab[i].tex = temp3;
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

void		ft_order_sprite(t_env *env)
{
	int		i;

	i = 0;
	env->sprite_count = sprite_count(env);
	while (i < env->sprite_count)
	{
		env->ray.sp_order[i] = i;
		env->ray.sp_distance[i] = ((env->player_x - env->sprite_tab[i].pos_x) *
			(env->player_x - env->sprite_tab[i].pos_x) +
			(env->player_y - env->sprite_tab[i].pos_y) *
			(env->player_y - env->sprite_tab[i].pos_y));
		i++;
	}
	ft_sort(env->ray.sp_order, env->ray.sp_distance, env->sprite_count, env);
	add_sprite(env);
}
