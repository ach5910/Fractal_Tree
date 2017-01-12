/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:09:17 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/04 15:09:26 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H
# include "mlx.h"
// # include "mlx_int.h"
# include "libft.h"
# include <math.h>
# define WIDTH 1500
# define HEIGHT 1000
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

typedef struct 	s_vec2
{
	double	x;
	double	y;
}				t_vec2;

typedef struct  s_tree
{
	t_vec2 	*v;
	double len;
	double rot;
	int branch;
	int size;
	double theta;
	double phi;
	double scl;
}				t_tree;

typedef struct 	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	t_tree 	*t;
	t_list	*stack;
	int b;
	char *code;
	unsigned int flags;
}				t_env;



typedef struct  s_img
{
	void	*i_ptr;
	int bpp;
	int size_line;
	int endian;
	char *data;
	int w;
	int h;
}				t_img;

typedef struct  s_line
{
	double dx;
	double dy;
	double p;
	double i;
	double j;
	double j_incr;
	t_vec2 *end;
	t_vec2 *start;
}				t_line;



int main(void);
// int mlx_hook(void *win, int num, int mast, my_mouse_motion, e);
void ft_tree(t_env *e, int branches);
// int mlx_mouse_hook(e->win, my_mouse_function, e);
void my_loop(t_env *e);
t_env *init_environment(void);
t_img *init_image(t_env *e);
t_tree *draw_branch(t_env *e, t_tree *t);
t_line	*get_line_params_x(t_env *e,t_vec2 *p1, t_vec2 *p2);
t_line	*get_line_params_y(t_env *e, t_vec2 *p1, t_vec2 *p2);
void draw_lines_x(t_env *e, t_vec2 *p1, t_vec2 *p2);
void draw_lines_y(t_env *e, t_vec2 *p1, t_vec2 *p2);
// int expose_hook(g_e *t_e);
// int my_loop_hook(g_e *t_e);
// void	check_neg_flags(g_e *t_e);
// void	check_pos_flags(g_e *t_e);
// int	my_mouse_motion(int x, int y, g_e *t_e);
// int my_mouse_released(int button, int x, int y, g_e *t_e);
// int my_mouse_function(int button, int x, int y, g_e *t_e);
// int my_key_pressed(int keycode, g_e *t_e);
// int my_key_recall(unsigned int keycode, g_e *t_e);
// int my_key_funct(int keycode, g_e *t_e);
int draw_tree(t_env *e);
#endif
