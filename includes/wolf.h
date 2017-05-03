/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:18:43 by cde-laro          #+#    #+#             */
/*   Updated: 2017/05/03 01:34:17 by cde-laro         ###   ########.fr       */
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
# define JUMP_MAX 50
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
	size_t		maxx;
	size_t		maxy;
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
	t_intp		draw_start;
	t_intp		draw_end;
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
}				t_env;

char			*ft_strjoin_free(char *s1, char *s2);
int				check_char(char *str, char *filename);
t_map			*parse(char *path);
int				key_press(int k, t_env *e);
int				key_release(int k, t_env *e);
t_env			*init(char *name);
void			draw_line(t_env *e, t_intp a, t_intp b, int z);
void			start(t_env *e);
void			init_img(t_env *e);
void			reset_img(t_env *e);
void			draw(t_env *e);
void			rotate(t_env *e, int dir);
void			move(t_env *e, int dir);
void			draw_frame(t_env *e);
void			reset_img(t_env *e);
int				game_loop(t_env *e);
void			jump_dec(t_env *e);
int				red_cross(int key, t_env *e);
void			pix_put_img(t_env *e, int x, int y, int color);
//void			mlx_clr_img(t_env *e);
void 			reprint(t_env *e);
int				set_color(int side, int stepx, int stepy);
void			print_error_code(int code);
void 			print_instruction(void);
void			print_map(t_env *e, int **data, int maxx, int maxy);
t_xpm			*init_xpm(t_env *e, char *path);
void			mlx_paste_img(t_env *e, t_xpm *xpm, t_intp coord);
void			mlx_img_copy(t_env *e, t_intp coord, t_intp dec, t_xpm *src);

#endif
