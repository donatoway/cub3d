#include "../includes/cub3d.h"
int		ft_error_tex_inputs(int error, char *orientation)
{
	error = ft_strlen(orientation);
	free(orientation);
	ft_putstr("Errore : path della texture errato\n");
	return (ERROR);
}

void	ft_error_arg2(int error)
{
	if (error == MAP_ERROR_NOT_CLOSED)
		ft_putstr("ERRORE : mappa non chiusa\n");
	if (error == MAP_ERROR_SAME_SIZE)
		ft_putstr("ERRORE : le linee della mappa non hanno la stessa grandezza\n");
	if (error == UNKNOW_ARG)
		ft_putstr("Errore : argomento non valido\n");
}
int		ft_error_arg(int error)
{
	if (error == NB_ARG_ERROR_TOO_FEW)
		ft_putstr("ERRORE : pochi argomenti\n");
	if (error == NB_ARG_ERROR_TOO_MANY)
		ft_putstr("Errore : troppi argomenti arguments");
	if (error == FILE_EXT_ERROR)
		ft_putstr("Errore : file non valido\n");
	if (error == SAVE_FLAG_ERROR)
		ft_putstr("Errore : flag non valide\n");
	if (error == FILE_READ_ERROR)
		ft_putstr("Errore : problema nella lettura del file\n");
	if (error == SCREEN_ERROR)
		ft_putstr("Errore : dimensioni della finestra errate\n");
	if (error == PATH_ERROR)
		ft_putstr("Errore : path errato \n");
	if (error == RGB_ERROR)
		ft_putstr("Errore : floor o ceil");
	if (error == MAP_ERROR_WRONG_CHAR)
		ft_putstr("Errore : carattere non valido nella mappa");
	if (error == MAP_ERROR_MANY_POS)
		ft_putstr("Errore : trppe posizioni\n");
	if (error == MAP_ERROR_NO_POS)
		ft_putstr("Errore : non ci sono posizioni\n");
	ft_error_arg2(error);
	return (ERROR);
}

int		ft_error(int error, t_game *game)
{
	if (error == BUFF_ERR)
	{
		ft_putstr("ERRORE : allocazione della memoria\n");
	}
	if (error == FROM_LST_ERROR)
	{
		ft_putstr("ERRORE : list error\n");
	}
	if (error == TEX_ERROR)
		ft_putstr("ERRORE : TEXTURE");
	ft_exit(game);
	return (SUCCESS);
}
