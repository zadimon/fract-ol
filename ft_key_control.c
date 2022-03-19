/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:23:55 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/10 17:16:36 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	moving(int key, t_fractol *fractol)
{
	t_complex	delta;

	delta = init_complex((fractol->max.re - fractol->min.re) * 0.05,
			(fractol->max.im - fractol->min.im) * 0.05);
	if (key == 123)
	{
		fractol->min.re = fractol->min.re - delta.re;
		fractol->max.re = fractol->max.re - delta.re;
	}
	else if (key == 124)
	{
		fractol->min.re = fractol->min.re + delta.re;
		fractol->max.re = fractol->max.re + delta.re;
	}
	else if (key == 125)
	{
		fractol->min.im = fractol->min.im - delta.im;
		fractol->max.im = fractol->max.im - delta.im;
	}
	else if (key == 126)
	{
		fractol->min.im = fractol->min.im + delta.im;
		fractol->max.im = fractol->max.im + delta.im;
	}
}

void	color_shift(t_fractol *fractol)
{
	fractol->shift++;
	if (fractol->shift > 3)
		fractol->shift = 1;
}

int	key_control(int key, t_fractol *fractol)
{
	if (key == 69 || key == 24)
	{
		if (fractol->max_iter < 50)
			fractol->max_iter += 1;
		else if (fractol->max_iter < 1000000000)
			fractol->max_iter *= 1.05;
	}
	if (key == 78 || key == 27)
	{
		if (fractol->max_iter > 50)
			fractol->max_iter *= 0.95;
		else if (fractol->max_iter > 1)
			fractol->max_iter -= 1;
	}
	if (key == 15)
		init_default(fractol);
	if (key == 53)
		exit(0);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		moving(key, fractol);
	if (key == 8)
		color_shift(fractol);
	draw_fractal(fractol);
	return (0);
}
