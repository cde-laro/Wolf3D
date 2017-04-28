/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-laro <cde-laro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:18:43 by cde-laro          #+#    #+#             */
/*   Updated: 2017/04/28 19:14:27 by cde-laro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <stdlib.h>
# include "libft.h"
# include "limits.h"
# include "keys.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 424242
# define PI M_PI
# define RAD(x) (PI * x / 180)
# define WIN_X 720
# define WIN_Y 480
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
/*
typedef struct	s_player
{
	t_point		pos;
	double		speed;
	double		r_s;
	double		angle;
	t_point		dir;
	t_point		delta;
	t_point		step;
	t_point		side;
	t_point		map;
}				t_player;
*/
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

typedef struct	s_player
{
	double		speed;
	double		r_s;
	double		angle;
	double		rat;
	t_point		pos;
	t_point		map;
	t_point		dir;
	t_point		plane;
	t_point		rayp;
	t_point		rayd;
	t_intp		boxp;
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
}				t_env;

char			*ft_strjoin_free(char *s1, char *s2);
int				check_char(char *str, char *filename);
t_map			*parse(char *path);
int				key_funct(int k, t_env *e);
void			init(t_env *e);
void			draw_line(t_env *e, t_intp a, t_intp b, int z);
void			start(t_env *e);
void			init_img(t_env *e);
void			reset_img(t_env *e);
void			draw(t_env *e);
void			rotate(t_env *e, int dir);
void			move(t_env *e, int dir);
void			draw_frame(t_env *e);
void			reset_img(t_env *e);

#endif
