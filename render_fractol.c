/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:09:46 by hsirenko          #+#    #+#             */
/*   Updated: 2023/11/04 19:09:46 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pxl_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pxl_ptr + offset) = color;
}

static void	mandelbrot_vs_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->real = fractol->julia_real;
		c->imgry = fractol->julia_imgry;
	}
	else
	{
		c->real = z->real;
		c->imgry = z->imgry;
	}
}

static void	handle_pxl(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = (scale(x, -2, 2, WIDTH) * fractol->zoom) + fractol->shift_real;
	z.imgry = (scale(y, 2, -2, HEIGHT) * fractol->zoom) + fractol->shift_imgry;
	mandelbrot_vs_julia(&z, &c, fractol);
	while (i < fractol->iterations_def)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imgry * z.imgry) > fractol->escape_val)
		{
			color = scale(i, BLACK, WHITE, fractol->iterations_def);
			my_pxl_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	my_pxl_put(x, y, &fractol->img, PSYCHEDELIC_CYAN);
}

void	render_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pxl(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connection,
		fractol->mlx_window, fractol->img.img_ptr, 0, 0);
}
