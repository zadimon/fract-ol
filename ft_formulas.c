/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formulas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:08:09 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/10 18:59:22 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *fractol)
{
	t_complex	z;

	z = init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0)
		<= 4 && fractol->iter < fractol->max_iter)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ fractol->c.re, 2.0 * z.re * z.im + fractol->c.im);
		fractol->iter++;
	}
}

void	julia(t_fractol *fractol)
{
	t_complex	z;

	z = init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0)
		<= 4 && fractol->iter < fractol->max_iter)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ fractol->k.re, 2.0 * z.re * z.im + fractol->k.im);
		fractol->iter++;
	}
}

void	burning_ship(t_fractol *fractol)
{
	t_complex	z;

	z = init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0)
		<= 4 && fractol->iter < fractol->max_iter)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ fractol->c.re, -2.0 * fabs(z.re * z.im) + fractol->c.im);
		fractol->iter++;
	}
}
