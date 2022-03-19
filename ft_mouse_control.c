/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:45:17 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/16 22:15:23 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

int	mouse_control(int key, int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	double		zoom;

	if (key == 1)
		fractol->press = 1;
	mouse.re = (fractol->min.re + x
			* ((fractol->max.re - fractol->min.re) / (WIDTH)));
	mouse.im = (fractol->max.im - y
			* ((fractol->max.im - fractol->min.im) / (HEIGHT)));
	if (key == 5)
		zoom = 1.20;
	else if (key == 4)
		zoom = 0.80;
	else
		zoom = 1.0;
	fractol->min.re = interpolate(mouse.re, fractol->min.re, zoom);
	fractol->min.im = interpolate(mouse.im, fractol->min.im, zoom);
	fractol->max.re = interpolate(mouse.re, fractol->max.re, zoom);
	fractol->max.im = interpolate(mouse.im, fractol->max.im, zoom);
	draw_fractal(fractol);
	return (0);
}

int	press_julia(int key, int x, int y, t_fractol *fractol)
{
	(void) x;
	(void) y;
	if (key == 1)
		fractol->press = 0;
	return (0);
}

int	change_julia(int x, int y, t_fractol *fractol)
{
	if (fractol->press == 1)
	{
		fractol->k = init_complex(
				4 * ((double)x / WIDTH - 0.5),
				4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fractal(fractol);
	}
	return (0);
}
