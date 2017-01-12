/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 00:16:05 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/01 00:16:06 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>
# define WIDTH 1200
# define HEIGHT 800
# define TRAN_H 0x01
# define TRAN_V  0x02
# define SCL  0x04
# define ROT_X  0x08
# define ROT_Y  0x10
# define ROT_Z  0x20
# define MOUS  0x40
# define SIGN  0x80
# define ROT_X_NEG  0x100
# define ROT_Y_NEG  0x200
# define DRAW_SHAPE 0X400

typedef struct s_vec
{
	double	x;
	double y;
	double	z;
	int color;
}				t_vec;

typedef struct 	s_e
{
	void	*mlx;
	void	*win;
	int		len;
	int 	max_strs;
	unsigned int *keys;
	int	key_len;
	double per;
	int STACK_MAX;
	t_vec *pnts;
	t_vec *c_pnts;
	double c_min;
	double c_max;
	unsigned int flags;
	char *file;
	char **files;
	int max_files;
	int file_num;
}				g_e;

typedef int (*t_maps)(int);

typedef struct  s_line
{
	double dx;
	double dy;
	double p;
	double i;
	double j;
	double j_incr;
	double end;
	double start;
}				t_line;

typedef struct  s_tree
{
	t_vec pos;
	double len;
	double rot;
}				t_tree;

g_e *init_environment(void);
void get_map(g_e *t_e);
void set_copy(g_e *t_e);
void draw_map(g_e *t_e);
void draw_legend(g_e *t_e);
void draw_shape(g_e *t_e);
t_line	*get_line_params_x(g_e *t_e, int index, int inc);
t_line	*get_line_params_y(g_e *t_e, int index, int inc);
void draw_lines_x(g_e *t_e, int index, int inc);
void draw_lines_y(g_e *t_e, int index, int inc);
double mean_x(g_e *t_e);
double mean_y(g_e *t_e);
double mean_z(g_e *t_e);
void rotation_x(g_e *t_e, double dir);
void rotation_y(g_e *t_e, double dir);
void rotation_z(g_e *t_e, double dir);
void perspective(g_e *t_e, double dir);
void scale(g_e *t_e, double factor);
void translation_h(g_e *t_e, double shift);
void translation_v(g_e *t_e, double shift);
void draw_tri(g_e *t_e);
void set_color_map(g_e *t_e, int get_next_map);
void reset_map(g_e *t_e);
void load_next_map(g_e *t_e);
char **extract_map_params(g_e *t_e, char **map);
void parse_map_data(g_e *t_e, char **map, char *num, int p);
void realloc_keys(g_e *t_e);
void my_loop(g_e *t_e);
int expose_hook(g_e *t_e);
int my_loop_hook(g_e *t_e);
void	check_neg_flags(g_e *t_e);
void	check_pos_flags(g_e *t_e);
int	my_mouse_motion(int x, int y, g_e *t_e);
int my_mouse_released(int button, int x, int y, g_e *t_e);
int my_mouse_function(int button, int x, int y, g_e *t_e);
int my_key_pressed(int keycode, g_e *t_e);
int my_key_recall(unsigned int keycode, g_e *t_e);
int my_key_funct(int keycode, g_e *t_e);
void apply_color_map(g_e *t_e, int color_map_index);
int dawn(int i);
int dusk(int i);
int kryptonite(int i);
int	dawn(int i);
int	red_blue(int i);
int	fire(int i);	
int	ice(int i);
int	seashore(int i);
int	kryptonite_center(int i);
int	seashore_center(int i);
int	fire_center(int i);
int	dawn_center(int i);
t_maps get_color_map(int i);

#endif
