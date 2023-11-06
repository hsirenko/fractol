/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:09:46 by hsirenko          #+#    #+#             */
/*   Updated: 2023/11/04 19:09:46 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR_MESSAGE "Please enter mandelbrot or julia, realnumb, imnum"

# define WIDTH	800
# define HEIGHT	800

/*COLORS*/
# define BLACK   0x000000
# define WHITE   0xFFFFFF
# define RED     0xFF0000
# define GREEN   0x00FF00
# define BLUE    0x0000FF
# define YELLOW  0xFFFF00
# define ORANGE  0xFFA500
# define PURPLE  0x800080
# define CYAN    0x00FFFF
# define MAGENTA 0xFF00FF

# define PSYCHEDELIC_PINK    0xFF1493
# define PSYCHEDELIC_LIME    0x32CD32
# define PSYCHEDELIC_CYAN    0x00FFFF
# define PSYCHEDELIC_YELLOW  0xFFFF00
# define PSYCHEDELIC_PURPLE  0x9400D3

typedef struct s_complex
{
	double	real;
	double	imgry;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractol
{
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	char	*name;

	double	escape_val;
	int		iterations_def;
	double	shift_real;
	double	shift_imgry;
	double	zoom;
	double	julia_real;
	double	julia_imgry;
}	t_fractol;

//fractol_utils
int			ft_strncmp(char *s1, char *s2, unsigned int n);
void		ft_putstr_fd(char *s, int fd);
double		atodouble(char *s);
//fractol_init
void		fractol_init(t_fractol *fractol);
//redner fractol
void		render_fractol(t_fractol *fractol);
//math utils
double		scale(double unscaledNum,
				double minAllowed, double maxAllowed, double max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
//events
int			key_press(int keysym, t_fractol *fractol);
int			close_handle(t_fractol *fractol);
int			mouse_handle(int button, int x, int y, t_fractol *fractol);
int			julia_mouse_move(int x, int y, t_fractol *fractol);

#endif