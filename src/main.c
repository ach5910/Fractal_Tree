/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:06:39 by ahunt             #+#    #+#             */
/*   Updated: 2016/12/04 15:06:41 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tree.h"

int iter = 8;


t_tree *ft_pop_tree(t_list **list)
{
	t_tree *data;
	t_list *temp;
	if (!*list)
		return (NULL);
	data = (*list)->content;
	if ((*list)->next)
	{
		(*list) = (*list)->next;
	}
	return (data);
}
//basic X : 'X' "F[+X][-X]" branches = 1.0, init len 2, len * 0.7, and 35, iter 8 
//blackjack 'X' X : "F[+X][-X]FX" F: "FF" branches = 0.7 init len 35, ang 27.5, iter 8
//sway 'F' F:FF+[+F-F-F]-[-F+F+F], ang 27.5, iter 4, init len 100, branch 0.5
t_img	*init_image(t_env *e)
{
	t_img *img;

	img = (t_img*)malloc(sizeof(t_img));
	img->i_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	img->w = WIDTH / 2;
	img->h = HEIGHT / 2;
	img->data = mlx_get_data_addr(img->i_ptr, &img->bpp, &img->size_line, &img->endian);
	
	return (img);
}

// t_tree *init_tree()
// {
// 	t_tree *t;
// 	t_vec2 *v;
		
// 		t = (t_tree*)malloc(sizeof(t_tree));
// 		t->len = 300;
// 		t->v = (t_vec2*)malloc(sizeof(t_vec2));
// 		t->v->x = WIDTH / 2;
// 		t->v->y = HEIGHT;
// 		t->rot = (M_PI / 2);
// 		t->scl = 1.0;
// 		t->theta = (35 * M_PI / 180);
// 		// branch *= t->scl;
// 		t->branch = 8;
// 		t->iter = 8;
// 		return (t);
// }

t_env	*init_environment(void)
{
	t_env *e;

	e = (t_env*)malloc(sizeof(t_env));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fractal Tree");
	e->img = init_image(e);
	e->flags = 0;
	return (e);
}

int ft_draw_tree(t_env *e, t_tree *t, char *code, int i, int len)
{
	t_tree *temp1;
	e->t->branch = len;
	t_tree *temp2;

	t_list *stack;
	while (code[i])
	{
		// printf("\nWhile");
		if (code[i] == 'F')
			t = draw_branch(e, t);
		else if (code[i] == '+')
			t->rot += t->theta;
		else if (code[i] == '-')
			t->rot -=  t->phi;
		else if (code[i] == '[')
		{
			temp1 = (t_tree*)malloc(sizeof(t_tree));
			temp1->v = (t_vec2*)malloc(sizeof(t_vec2));
			temp1->v->x = t->v->x;
			temp1->v->y = t->v->y;
			temp1->len = t->len;
			temp1->rot = t->rot;
			temp1->theta = t->theta;
			temp1->phi = t->phi;
			ft_lstadd(&stack, ft_lstnew(temp1, sizeof(t_tree)));
			t->branch -= 1;
			t->len *= t->scl;
			//i = ft_draw_tree(e, temp1, code, ++i, len - 1);
		}
		else if (code[i] == ']')
		{
			// return (i);
			temp2 = (t_tree*)malloc(sizeof(t_tree));
			temp2 = ft_pop_tree(&stack);
			t->v = temp2->v;
			t->len = temp2->len;
			t->rot = temp2->rot;
			t->branch += 1;
		}
		i++;
	}
	return (i);
}
char *apply_axioms(char *src)
{
	// t_list *stack;
	// t_node *funct;
	char *dest;
	int i = 0;

	dest = ft_strnew(1);
	while (src[i])
	{
		if (src[i] == 'F')
			dest = ft_strapp(dest, "F");//FF+[+F-F-F]-[-F+F+F]   //"F[-F][+F]F"
		else if (src[i] == '+')
			dest = ft_strapp(dest, "+");
		else if (src[i] == '-')
			dest = ft_strapp(dest, "-");
		else if (src[i] == '[')
			dest = ft_strapp(dest, "[");
		else if (src[i] == ']')
			dest = ft_strapp(dest, "]");
		else if (src[i] == 'X')
			dest = ft_strapp(dest, "F[-X][+X]");//FF
		i++;	
	}

	return (dest);
	// funct = src_stack->content;
	// while (funct)
	// {
	// 	if (funct->chr = 'F')
	// 	{
	// 		ft_push(&dest_stack, rule_stack);
	// 	}
	// 	else
	// 	{
	// 		ft_push(&dest_stack, ft_pop(&src_stack));
	// 	}
	// 	funct = src_stack->content;
	// }
	// ft_memdel((void **)&src_stack);
	// ft_memdel((void **)&funct);
	// return (dest_stack);
}
char	*generate_code(t_env *e, char *code, int len)
{
	int i = 0;
	// t_tree *t;
	// t_vec2 *v;
	// int i;
	// int branch = 250;
	// i = 0;
	// t = (t_tree*)malloc(sizeof(t_tree));
	// t->len = branch;
	// t->v = (t_vec2*)malloc(sizeof(t_vec2));
	// t->v->x = WIDTH / 2;
	// t->v->y = HEIGHT;
	// t->size = len;
	// t->theta = (4 * M_PI / 16);
	// t->rot = (M_PI / 2);
	// t->scl = 0.7;//Shroom = 0.745
	// t->iter = 8;
	// e->t = t;
	while (i < len)
	{
		code = apply_axioms(code);
		// t->branch = i + 1;
		// t->len *= 0.5;
		
		// if (i == len)
		// 	ft_draw_tree(e, e->t, code, 0, i);
		i++;
	}
	// ft_draw_tree(e, e->t, code, 0, i);
	return (code);
}

// int my_mouse_motion(int i , int j , t_env *e)
// {
// 	// t_tree *t;
// 	// t_vec2 *v;
// 	ft_printf("X = %d Y = %d\n", i , j);
// 	if (i > 0 && i < WIDTH && i % 50 == 0)
// 	{
// 		// e->theta = (i / WIDTH * 90 * M_PI / 180);
// 		// t = (t_tree*)malloc(sizeof(t_tree));
// 		// t->len = 300;
// 		// t->v = (t_vec2*)malloc(sizeof(t_vec2));
// 		// t->v->x = WIDTH / 2;
// 		// t->v->y = HEIGHT;
// 		// t->rot = (M_PI / 2);
// 		// t->scl = 1.0;
// 		// // branch *= t->scl;
// 		// t->branch = 8;
// 		// t->iter = 8;
// 		mlx_clear_window(e->mlx, e->win);
// 		ft_draw_tree(e, t, e->code, 0, 8);
// 	}
// 	return (0);
// }
int my_mouse_function(int button, int i, int j, t_env *e)
{
	// ft_printf("Button = %d  X = %d  Y  = %d\n", button, i, j);
	if (button == 5)
		e->t->theta += (M_PI / 32);
	else if (button == 4)
		e->t->theta -= (M_PI / 32);
	if (button == 6)
		e->t->phi += (M_PI / 32);
	else if (button == 7)
		e->t->phi -= (M_PI / 32);

	// else if (button == 1)
	// 	e->t->iter++;
	// else if (button == 2)
	// 	e->t->iter--;
	// if (button >= 1 && button <= 5 && button != 3)
	// 	ft_tree(e, e->t->iter);
	// return (0);
	 // = init_environment();e
	// ft_tree(e, 13);
	e->t->len = 300;
	e->t->v->x = WIDTH / 2;
	e->t->v->y = HEIGHT * 7 / 8;
	mlx_clear_window(e->mlx, e->win);
	ft_draw_tree(e, e->t, e->code, 0, e->t->size);
	return (0);
}

void ft_tree(t_env *e, int branches)
{
	t_tree *t;
	t_vec2 *v;
	int branch = 300;
	t = (t_tree*)malloc(sizeof(t_tree));
	t->len = branch;
	t->v = (t_vec2*)malloc(sizeof(t_vec2));
	t->v->x = WIDTH / 2;
	t->v->y = HEIGHT * 7 / 8;
	t->size = branches;
	t->theta = (4 * M_PI / 16);
	t->phi = (4 * M_PI / 16);
	t->rot = (M_PI / 2);
	t->scl = 0.7;//Shroom = 0.745
	// t->iter = 8;
	e->t = t;
	// t_list *code;
	// t_tree *t;
	// t_vec2 *v;
	char *code = "X";
	code = generate_code(e, code, branches);
	e->code = ft_strdup(code);
	ft_draw_tree(e, e->t, code, 0, branches);
	
}
int main(void)
{
	t_env *e;
	e = init_environment();
	ft_tree(e, 13);
	// draw_tree(e);
	// mlx_hook(e->win, 6, 0, my_mouse_motion, e);
	mlx_mouse_hook(e->win, my_mouse_function, e);
	mlx_loop(e);
	return (0);
}
