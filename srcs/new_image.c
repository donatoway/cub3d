#include "../includes/cub3d.h"

int			from_rgb_to_hex(t_rgb color)
{
	int		output;

	output = 256 * 256 * color.r + 256 * color.g + color.b;
	return (output);
}

void		get_arg_for_game(t_game *game, t_arg arg, int y, int x)
{
	t_map	*tmp;

	tmp = arg.map;
	while (tmp)
	{
		x = 0;
		while (tmp->line[x] != '\0')
		{
			if (ft_strchr("NSWE", tmp->line[x]))
			{
				game->orientation = tmp->line[x];
				game->player_x = x++;
				game->player_y = y++;
			}
			if (ft_strchr("2", tmp->line[x]))
				game->sprite_count++;
			x++;
		}
		game->map_width = x;
		tmp = tmp->next;
		y++;
	}
	game->map_height = y - 1;
}

t_img		*ft_new_img(t_game *game, char *file)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
	{
		return (NULL);
	}
	if (!(img->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, file,
		&img->width, &img->height)))
	{
		free(img);
		return (NULL);
	}
	if (!(img->img_data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,
		&img->size_line, &img->endian)))
	{
		free(img->img_ptr);
		free(img);
		return (NULL);
	}
	return (img);
}
