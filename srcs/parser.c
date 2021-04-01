#include "../includes/cub3d.h"

int			get_map(t_arg *arg, char *buff)
{
	t_map	*tmp;

	if (!(tmp = ft_lstnew_map(withdraw_char(buff, ' '))))
		return (ERROR);
	ft_lstadd_back_map(&(arg->map), tmp);
	return (SUCCESS);
}

int			check_floor_ceil_b(t_arg *arg, char *buff, int i)
{
	while (ft_isdigit(buff[i]))
		i++;
	while (!ft_isdigit(buff[i]) && buff[i] != '-')
		i++;
	if (ft_atoi(buff + i) > 255 || ft_atoi(buff + i) < 0)
		return (RGB_ERROR);
	if (buff[0] == 'F')
		arg->floor.b = ft_atoi(buff + i);
	else
		arg->ceil.b = ft_atoi(buff + i);
	return (SUCCESS);
}

int			check_floor_ceil(t_arg *arg, char *buff)
{
	int i;

	i = 0;
	while (!ft_isdigit(buff[i]) && buff[i] != '-')
		i++;
	if (ft_atoi(buff + i) > 255 || ft_atoi(buff + i) < 0)
		return (RGB_ERROR);
	if (buff[0] == 'F')
		arg->floor.r = ft_atoi(buff + i);
	else
		arg->ceil.r = ft_atoi(buff + i);
	while (ft_isdigit(buff[i]))
		i++;
	while (!ft_isdigit(buff[i]) && buff[i] != '-')
		i++;
	if (ft_atoi(buff + i) > 255 || ft_atoi(buff + i) < 0)
		return (RGB_ERROR);
	if (buff[0] == 'F')
		arg->floor.g = ft_atoi(buff + i);
	else
		arg->ceil.g = ft_atoi(buff + i);
	if (check_floor_ceil_b(arg, buff, i) != SUCCESS)
		return (RGB_ERROR);
	return (SUCCESS);
}

int			check_screen(t_arg *arg, char *buff, int i)
{
	while (!ft_isdigit(buff[i]) && !ft_strchr("+-", buff[i]))
		i++;
	arg->screen_width = ft_atoi(buff + i);
	while (ft_isdigit(buff[i]) || ft_strchr("+-", buff[i]))
		i++;
	arg->screen_height = ft_atoi(buff + i);
	while ((ft_strchr(invisible, buff[i]) || ft_isdigit(buff[i]))\
			&& buff[i] != '\0')
		i++;
	while (buff[i] != '\0')
	{
		if (ft_strchr(invisible, buff[i]) == 0)
			return (SCREEN_ERROR);
		i++;
	}
	if (arg->screen_height <= 0 || arg->screen_width <= 0)
		return (SCREEN_ERROR);
	if (arg->screen_height >= MAX_HEIGHT)
		arg->screen_height = MAX_HEIGHT;
	if (arg->screen_width >= MAX_WIDTH)
		arg->screen_width = MAX_WIDTH;
	return (SUCCESS);
}

int			get_arguments(t_arg *arg, char *buff)
{
	if (buff[0] == '\n' || buff[0] == '\0')
		return (SUCCESS);
	if (buff[0] == 'R')
		if (check_screen(arg, buff, 0) != SUCCESS)
			return (ft_error_arg(SCREEN_ERROR));
	if (ft_strchr("NSWES", buff[0]))
		if (check_path(arg, buff) != SUCCESS)
			return (ft_error_arg(PATH_ERROR));
	if (ft_strchr("FC", buff[0]))
		if (check_floor_ceil(arg, buff) != SUCCESS)
			return (ft_error_arg(RGB_ERROR));
	if (ft_isdigit(buff[0]))
		if (get_map(arg, buff) != SUCCESS)
		{
			ft_putstr("ERRORE : controllo della mappa non riuscito");
			return (MAP_ERROR);
		}
	if (!ft_isdigit(buff[0]) && !ft_strchr("RNSEWSFC", buff[0]))
		return (ft_error_arg(UNKNOW_ARG));
	return (SUCCESS);
}
