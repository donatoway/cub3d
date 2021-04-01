#include "../includes/cub3d.h"

int				ft_save(t_game *game)
{
	t_save save;

	save.height = game->height - 1;
	save.width = game->width;
	save.pad = (4 - ((int)save.width * 3) % 4) % 4;
	save.file_header = create_file_header(game, save.pad);
	save.img_header = create_img_header(save.height, save.width);
	if ((save.fd = open(SCREEN_PATH, O_WRONLY | O_CREAT, RIGHTS)) < 0)
		return (OPEN_ERROR);
	if (write_headers(&save) != SUCCESS)
	{
		close(save.fd);
		return (COLOR_ERROR);
	}
	if (write_colors(game, save.fd, save.height, save.width) != SUCCESS)
	{
		close(save.fd);
		return (COLOR_ERROR);
	}
	close(save.fd);
	return (SUCCESS);
}

int				launch_save(t_game *game)
{
	ft_save(game);
	game->save_flag = 0;
	return (SUCCESS);
}
