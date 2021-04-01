#include "../includes/cub3d.h"

t_tex	*ft_new_tex(t_game *game, char *file, char *type)
{
	t_tex *tex;

	if (!(tex = malloc(sizeof(t_tex))))
		return (NULL);
	if (!(tex->tex_ptr = mlx_xpm_file_to_image(game->mlx_ptr, file,
		&tex->width, &tex->height)))
	{
		free(tex);
		return (NULL);
	}
	if (!(tex->tex_data = (int *)mlx_get_data_addr(tex->tex_ptr, &tex->bpp,
		&tex->size_line, &tex->endian)))
	{
		free(tex->tex_ptr);
		free(tex);
		return (NULL);
	}
	tex->type = type;
	return (tex);
}

void	te_wall_sprite(t_game *game)
{
	if ((game->tex_n = ft_new_tex(game, game->arg.no, "NO")) == NULL)
		game->error = TEX_ERROR_N;
	if ((game->tex_s = ft_new_tex(game, game->arg.so, "SO")) == NULL)
		game->error = TEX_ERROR_S;
	if ((game->tex_w = ft_new_tex(game, game->arg.we, "WE")) == NULL)
		game->error = TEX_ERROR_W;
	if ((game->tex_e = ft_new_tex(game, game->arg.ea, "EA")) == NULL)
		game->error = TEX_ERROR_E;
	if ((game->tex_sprite = ft_new_tex(game, game->arg.sprite, "sprite")) == NULL)
		game->error = TEX_ERROR_SP;
}

int		start_texture(t_game *game)
{
	game->error = 0;
	te_wall_sprite(game);
	if (game->error)
	{
		game->error = TEX_ERROR;
		ft_error(game->error, game);
	}
	return (SUCCESS);
}

