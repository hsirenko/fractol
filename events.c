/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:09:46 by hsirenko          #+#    #+#             */
/*   Updated: 2023/11/04 19:09:46 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handle(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection,
		fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection,
		fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_press(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handle(fractol);
	else if (keysym == XK_Up)
		fractol->shift_imgry -= (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_imgry += (0.5 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_real -= (0.5 * fractol->zoom);
	else if (keysym == XK_Left)
		fractol->shift_real += (0.5 * fractol->zoom);
	else if (keysym == XK_plus)
		fractol->iterations_def -= 10;
	else if (keysym == XK_minus)
		fractol->iterations_def += 10;
	render_fractol(fractol);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == Button5)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractol->zoom *= 1.05;
	}
	render_fractol(fractol);
	return (0);
}

int	julia_mouse_move(int x, int y, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		fractol->julia_real = scale(x, -2, 2, WIDTH)
			* fractol->zoom + fractol->shift_real;
		fractol->julia_imgry = scale(y, 2, -2, HEIGHT)
			* fractol->zoom + fractol->shift_imgry;
	}
	render_fractol(fractol);
	return (0);
}
