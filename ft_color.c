/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:51:42 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/06 19:14:50 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->image->data_addr + (y * fractol->image->line_bytes
			+ x * (fractol->image->pixel_bits / 8));
	*(unsigned int *)dst = color;
}

int	init_color(t_fractol *fractol)
{
	double	t;
	int		color[4];

	t = (double)fractol->iter / (double)fractol->max_iter;
	color[0] = 0;
	if (fractol->shift == 1)
	{
		color[1] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[2] = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[3] = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	if (fractol->shift == 2)
	{
		color[2] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[1] = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[3] = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	if (fractol->shift == 3)
	{
		color[3] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[2] = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[1] = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	return (create_trgb(color[0], color[1], color[2], color[3]));
}
