/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:09:46 by hsirenko          #+#    #+#             */
/*   Updated: 2023/11/04 19:09:46 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double unscaledNum,
		double minAllowed, double maxAllowed, double max)
{
	double	min;

	min = 0;
	return ((maxAllowed - minAllowed)
		* (unscaledNum - min) / (max - min) + minAllowed);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real = z1.real + z2.real;
	result.imgry = z1.imgry + z2.imgry;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = (z.real * z.real) - (z.imgry * z.imgry);
	result.imgry = 2 * z.real * z.imgry;
	return (result);
}

/*int main()
{
	int i = 0;

	while (i < 13)
	{
		double scaledNum = scale(i, 0, 5, 12);
		printf("%d -> %f\n", i, scaledNum);
		i++;
	}
}*/