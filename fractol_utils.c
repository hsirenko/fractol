/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:09:46 by hsirenko          #+#    #+#             */
/*   Updated: 2023/11/04 19:09:46 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || s == NULL)
		return ;
	if (*s)
	{
		write(fd, s, 1);
		ft_putstr_fd(s + 1, fd);
	}
}

double	atodouble(char *s)
{
	long	integer;
	double	decimal;
	double	pow;
	int		sign;

	integer = 0;
	sign = +1;
	decimal = 0;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s && *s != '.')
		integer = integer * 10 + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		decimal = decimal + (*s++ - '0') * pow;
	}
	return ((integer + decimal) * sign);
}
