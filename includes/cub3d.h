#	ifndef __CUB3D_H
#	define __CUB3D_H
#	include <math.h>
#	include <stdio.h>
#	include "../GNL/get_next_line.h"
#	include "../libft/libft.h"
#	include "../minilibx/mlx.h"
#	include <fcntl.h>
typedef	enum				e_error
{
	ERROR,
	BUFF_ERR,
	NB_ARG_ERROR,
	NB_ARG_ERROR_TOO_FEW,
	NB_ARG_ERROR_TOO_MANY,
	FILE_EXT_ERROR,
	SAVE_FLAG_ERROR,
	FILE_READ_ERROR,
	SCREEN_ERROR,
	ARGUMENT_ERROR,
	PATH_ERROR,
	UNKNOW_ARG,
	RGB_ERROR,
	OPEN_ERROR,
	WRITE_ERROR,
	FROM_LST_ERROR,
	MAP_ERROR,
	MAP_ERROR_WRONG_CHAR,
	MAP_ERROR_MANY_POS,
	MAP_ERROR_NO_POS,
	MAP_ERROR_NOT_CLOSED,
	MAP_ERROR_SAME_SIZE,
	MALLOC_ERROR,
	IMG_ERROR,
	TEX_ERROR_N,
	TEX_ERROR_S,
	TEX_ERROR_W,
	TEX_ERROR_E,
	TEX_ERROR_SP,
	MLX_ERROR,
	TEX_ERROR,
	PIXEL_ERROR,
	COLOR_ERROR,
	SUCCESS
}							t_error;

typedef struct				s_rgb
{
	int						r;
	int						g;
	int						b;
}							t_rgb;

typedef struct				s_map
{
	char					*line;
	struct s_map			*next;
}							t_map;

typedef struct				s_save
{
	int						height;
	int						width;
	int						pad;
	unsigned char			*file_header;
	unsigned char			*img_header;
	int						fd;
}							t_save;

typedef struct				s_arg
{
	int						screen_width;
	int						screen_height;
	char					*no;
	char					*so;
	char					*we;
	char					*ea;
	char					*sprite;
	t_rgb					floor;
	t_rgb					ceil;
	t_map					*map;
}							t_arg;

typedef	struct				s_tex
{
	void					*tex_ptr;
	int						*tex_data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
	char					*type;
	int						sprite_x;
	int						sprite_y;
}							t_tex;

typedef	struct				s_img
{
	void					*img_ptr;
	int						*img_data;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
}							t_img;

typedef struct				s_sprite_data
{
	double					sp_dist;
	double					spcamx;
	double					spcamy;
	double					transx;
	double					transy;
	int						spritescreenx;
	int						sprite_height;
	int						drawstart_y;
	int						drawend_y;
	int						sprite_width;
	int						drawstart_x;
	int						drawend_x;
	int						stripe;
	int						sp_x;
	int						sp_y;
}							t_sprite_data;

typedef struct				s_move
{
	int						up;
	int						down;
	int						left;
	int						right;
	int						strafl;
	int						strafr;
}							t_move;

typedef struct				s_ray
{
	double					planex;
	double					planey;
	double					stepx;
	double					stepy;
	double					dirx;
	double					diry;
	int						tex_x;
	int						tex_y;
	double					rposx;
	double					rposy;
	double					rdirx;
	double					rdiry;
	double					rdisdx;
	double					rdisdy;
	double					rdistx;
	double					rdisty;
	int						rmapx;
	int						rmapy;
	int						wall;
	int						wstart;
	int						wend;
	double					camera;
	int						hit;
	double					rayh;
	double					step_tex;
	double					tex_pos;
	double					dist;
	double					speed;
	double					*zbuffer;
	int						*sprite_order;
	double					*dist_sp;
	int						sprite;
	int						sprite_x;
	int						sprite_y;
	double					sprite_dist;
	double					spstart;
	double					spend;
}							t_ray;

typedef	struct				s_sprite
{
	double					pos_x;
	double					pos_y;
	t_tex					*tex;
}							t_sprite;

typedef struct				s_pos
{
	int						x;
	int						y;
}							t_pos;

typedef	struct				s_game
{
	void					*mlx_ptr;
	void					*win_ptr;
	t_arg					arg;
	char					**map;
	int						map_height;
	int						map_width;
	double					player_x;
	double					player_y;
	char					orientation;
	int						height;
	int						width;
	unsigned int			floor;
	unsigned int			ceil;
	int						error;
	t_move					move;
	t_ray					ray;
	t_img					*img;
	t_tex					*tex_s;
	t_tex					*tex_n;
	t_tex					*tex_w;
	t_tex					*tex_e;
	t_tex					*tex_sprite;
	t_tex					*tex_floor;
	int						save_flag;
	int						sprite_width;
	unsigned int			color;
	t_sprite				*sprite_tex;
	int						sprite_count;
	t_sprite				*sprite_tab;
	t_sprite_data			sprite;
}							t_game;


int							get_arguments(t_arg *arg, char *buff);
int							check_path(t_arg *arg, char *buff);
int							check_path1(char *orientation, char \
		*buff, int i, t_arg *arg);
int							check_path2(char *orientation, char \
		*buff, int i, t_arg *arg);
int							check_path3(char *orientation, char \
		*buff, int i, t_arg *arg);
int							check_map(t_map *map, int count_pos, int i);
t_tex						*ft_new_tex(t_game *game, char *file, char *type);
t_game						start_game(t_arg arg);
t_img						*ft_new_img(t_game *game, char *file);
int							from_rgb_to_hex(t_rgb color);
void						get_arg_for_game(t_game *game, t_arg a, int y, int x);
t_img						*ft_new_img(t_game *game, char *file);
int							ft_exit(t_game *game);
int							events(t_game game);
void						ft_move(t_game *game);
int							display_screen(t_game *game, int x);
int							ft_put_pixel(t_img *img, unsigned int\
		color, int p_x, int p_y);
void						start_ray(t_game *game, int x);
void						direction_ray(t_game *game);
char						hit(t_game *game, char wall_tex);
void						size_ray(t_game *game);
void						wall_texture(t_game *game, char tex);
void						sprite_texture(t_game *game);
int							count_char(char *str, char c);
t_map						*ft_lstlast_map(t_map *lst);
t_map						*ft_lstnew_map(void *content);
char						*withdraw_char(char *str, char c);
void						ft_lstadd_back_map(t_map **alst, t_map *new);
int							ft_lstsize_map(t_map *lst);
void						ft_lstclear_map(t_map **lst);
char						**from_lst_to_tab(t_map *lst);
t_img						*ft_new_image(t_game *game, int width, int height);
void						pixel_tex(t_tex *tex, t_game *game);
char						*pix_color(t_game *game, int sprite);
double						ft_abs(double x);
unsigned char				*create_file_header(t_game *game, int pad);
unsigned char				*create_img_header(int height, int width);
int							write_headers(t_save *save);
int							write_colors(t_game *game, int fd, int height,\
		int width);
int							launch_save(t_game *game);
int							sprite_count(t_game *game);
int							sprite2(t_game *game);
int							sprite(t_game *game);
void						reorder_sprite(t_game *game);
void						add_sprite(t_game *game);
int							add_sprite_two(t_game *game, int i);
int							sprite_count(t_game *game);
void						ft_sprite_calc(t_game *game, int i);
void						calc_end_start(t_game *game);
void						ft_free_tex(t_game *game, t_tex *tex);
void						ft_free_img(t_game *game, t_img *img);
int							start_texture(t_game *game);
int							ft_error(int error, t_game *game);
int							ft_error_arg(int error);
int							ft_error_tex_inputs(int error, char *orientation);

#	define invisible "\t\v\r\f "
#	define KEY_UP 13
#	define KEY_RIGHT 2
#	define KEY_LEFT 0
#	define KEY_DOWN 1
#	define ROTATE_LEFT 123
#	define ROTATE_RIGHT 124
#	define KEYPRESS 2
#	define KEYRELEASE 3
#	define KEYPRESSMASK 1
#	define KEYRELEASEMASK 10
#	define KEY_EXIT 53
#	define STR_IF_MASK 10001
#	define MAX_HEIGHT 1440
#	define MAX_WIDTH 2560
#	define BYTES_PER_PIX 3
#	define FILE_HEADER_SIZE 14
#	define IMG_HEADER_SIZE 40
#	define COMPRESSION 24
#	define SCREEN_PATH "screen.bmp"
#	define RIGHTS 0644
#	endif
