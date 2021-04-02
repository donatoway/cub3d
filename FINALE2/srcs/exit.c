/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:26:33 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/04/02 19:26:41 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_exit(t_env *env)
{
	if (!env->error)
	{
		ft_free_img(env, env->img);
		ft_free_tex(env, env->tex_s);
		ft_free_tex(env, env->tex_n);
		ft_free_tex(env, env->tex_w);
		ft_free_tex(env, env->tex_e);
		ft_free_tex(env, env->tex_sprite);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	}
	exit(0);
	return (SUCCESS);
}

