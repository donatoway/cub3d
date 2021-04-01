#include "../includes/cub3d.h"

int			check_arg(int ac, char **av)
{
	int		error;

	error = 0;
	if (ac > 3)
		error = NB_ARG_ERROR_TOO_MANY;
	if (ac < 2)
		error = NB_ARG_ERROR_TOO_FEW;
	if (ac == 2)
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
			error = FILE_EXT_ERROR;
	if (ac == 3)
		if (ft_strncmp(av[2], "--save", 6) != 0)
			error = SAVE_FLAG_ERROR;
	if (error)
	{
		ft_error_arg(error);
		return (ARGUMENT_ERROR);
	}
	return (SUCCESS);
}

int			launch_game_1(t_arg arg, int ac)
{
	t_game	game;

	if (check_map(arg.map, 0, 0) != SUCCESS)
		return (MAP_ERROR);
	game = start_game(arg);
	if (ac == 3)
		game.save_flag = 1;
	events(game);
	return (SUCCESS);
}

int			main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*buff;
	t_arg	arg;

	ft_bzero(&arg, sizeof(arg));
	ret = 0;
	buff = NULL;
	if (check_arg(ac, av) != SUCCESS)
		return (0);
	fd = open(av[1], O_RDWR);
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		if (get_arguments(&arg, buff) != SUCCESS)
			return (ARGUMENT_ERROR);
		free(buff);
	}
	if (buff)
		free(buff);
	if (ret == -1)
		return (ft_error_arg(FILE_READ_ERROR));
	if (launch_game_1(arg, ac) != SUCCESS)
		return (MAP_ERROR);
	return (0);
}
