/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:33:29 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/16 21:58:51 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_image	*init_image(t_fractol *fractol)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	image->image = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	image->data_addr = mlx_get_data_addr(image->image,
			&(image->pixel_bits), &(image->line_bytes),
			&(image->endian));
	return (image);
}

void	init_default(t_fractol *fractol)
{
	fractol->max_iter = 50;
	fractol->min.re = -2.0;
	fractol->max.re = 2.0;
	fractol->min.im = -2.0;
	fractol->max.im = fractol->min.im + (fractol->max.re
			- fractol->min.re) * HEIGHT / WIDTH;
	fractol->k = init_complex(-0.4, 0.6);
	fractol->press = 0;
	fractol->shift = 1;
}
