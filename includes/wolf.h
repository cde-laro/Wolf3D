/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:18:43 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/05 07:37:55 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <stdlib.h>
# include "libft.h"
# include "limits.h"
# include "keys.h"
# include "mlx.h"
# include "color.h"
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 1000000
# define PI M_PI
# define RAD(x) (PI * x / 180)
# define WIN_X 1080
# define WIN_Y 720
# define DEF_SPEED 0.3
# define DEF_AMMO 12
# define JUMP_MAX 50
# define TXT_PACK 1
# define SQ(x) (x * x)

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_intp
{
	int			x;
	int			y;
}				t_intp;


typedef struct	s_map
{
	int			maxx;
	int			maxy;
	int			**data;
}				t_map;

typedef struct	s_img
{
	void		*ptr_img;
	char		*bts;
	int			size_line;
	int			bpp;
	int			end;
}				t_img;

typedef struct	s_sky
{
	t_img		*img;
	t_intp		a;
}				t_sky;

typedef struct	s_xpm
{
	t_img		*img;
	t_intp		a;
}				t_xpm;

typedef struct	s_txt
{
	t_xpm		*txt_1;
	t_xpm		*txt_2;
	t_xpm		*txt_3;
	t_xpm		*txt_4;
	t_xpm		*txt_5;
	t_xpm		*txt_6;
	t_xpm		*txt_7;
	t_xpm		*txt_8;
	t_xpm		*txt_9;
}				t_txt;

typedef struct	s_keys
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			sprint;
	int			sneak;
	int			jump;
	int			jump_state;
	t_intp		dec;
	int			rotation;
}				t_keys;

typedef struct	s_player
{
	double		speed;
	double		r_s;
	double		rat;
	t_point		pos;
	t_point		map;
	t_point		dir;
	t_point		plane;
	t_point		rayp;
	t_point		rayd;
	t_point		sided;
	t_point		deltad;
	double		pwd;
	t_intp		step;
	int			line_h;
	t_point		wall;
	t_intp		draw_s;
	t_intp		draw_e;
	int			crossy;
	int			ammo;
	int			ammo_tick;
}				t_player;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		*data;
	int			drawed;
	t_map		*map;
	t_player	*p;
	t_keys		*k;
	t_xpm		*sky;
	t_xpm		*gun;
	t_xpm		*cross;
	int			generator;
	t_txt		*txt;
	int			pack;
	int			colors;
	t_intp		a;
	t_intp		b;
}				t_env;

t_map			*create_empty_map(int x, int y);
int				key_press(int k, t_env *e);
int				key_release(int k, t_env *e);
int				mouse_funct(int button,int x,int y, t_env *e);
t_env			*init(char *name);
void			draw_line(t_env *e, t_intp a, t_intp b, int z);
void			start(t_env *e);
void			init_img(t_env *e);
void			draw(t_env *e);
void			rotate(t_env *e, int dir);
void			move(t_env *e, int dir);
void			draw_frame(t_env *e);
int				game_loop(t_env *e);
void			jump_dec(t_env *e);
int				red_cross(int key, t_env *e);
void			pix_put_img(t_env *e, int x, int y, int color);
void 			reprint(t_env *e);
int				set_color(int side, int stepx, int stepy);
void			print_error_code(int code);
void 			print_instruction(int generator);
void			print_map(t_env *e, int **data, int maxx, int maxy);
t_xpm			*init_xpm(t_env *e, char *path);
void			mlx_paste_img(t_env *e, t_xpm *xpm, t_intp coord, int sky);
void			mlx_img_copy(t_env *e, t_intp coord, t_intp dec, t_xpm *src);
int				**put_in_map(int **map, int fd);
char			*extracting(int fd);
t_map			*map_extract(int fd, char *filename);
int				check_file2(char **str1, int *l, int *a);
int				check_file(int *l, int *a, int fd);
int				ft_isfullnum(char *str);
int				ft_count_s(char *str);
void 			load_txt(t_env *e);
t_xpm			*get_xpm(t_env *e, int id);

#endif
