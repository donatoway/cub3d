/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:23:20 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/04/02 19:23:29 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_tex(int error, t_env *env)
{
	env->error = error;
	if (env->tex_n)
		ft_free_tex(env, env->tex_n);
	if (env->tex_s)
		ft_free_tex(env, env->tex_s);
	if (env->tex_w)
		ft_free_tex(env, env->tex_w);
	if (env->tex_e)
		ft_free_tex(env, env->tex_e);
	if (env->tex_sprite)
		ft_free_tex(env, env->tex_sprite);
	ft_putstr("Error\nProblem with textures loading");
}

int		ft_error(int error, t_env *env)
{
	if (error == ZBUFFER_ERROR)
	{
		ft_putstr("Error\nProblem with memory allocation");
	}
	if (error == FROM_LST_ERROR)
	{
		ft_putstr("Error\nProblem with map creation");
	}
	
	if (error == TEX_ERROR)
		ft_error_tex(error, env);
	ft_exit(env);
	return (SUCCESS);
}

