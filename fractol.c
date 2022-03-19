/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebhakaz <ebhakaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:48:10 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/16 22:06:39 by ebhakaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractol *fractol)
{
	int			x;
	int			y;
	t_complex	factor;

	factor = init_complex((fractol->max.re - fractol->min.re)
			/ (WIDTH), (fractol->max.im - fractol->min.im) / (HEIGHT));
	y = 0;
	while (y < HEIGHT)
	{
		fractol->c.im = fractol->max.im - y * factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * factor.re;
			fractol->formula(fractol);
			my_mlx_pixel_put(fractol, x, y, init_color(fractol));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->image->image, 0, 0);
}

void	print_help(void)
{
	ft_putendl_fd("", 1);
	ft_putendl_fd("Usage ./fractol <name>", 1);
	ft_putendl_fd("List of available fractals:", 1);
	ft_putendl_fd("* Mandelbrot", 1);
	ft_putendl_fd("* Julia", 1);
	ft_putendl_fd("* Burning Ship", 1);
}

void	start(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr,
			WIDTH, HEIGHT, "Fract-ol");
	fractol->image = init_image(fractol);
	init_default(fractol);
	mlx_hook(fractol->win_ptr, 2, 0, key_control, fractol);
	mlx_hook(fractol->win_ptr, 4, 0, mouse_control, fractol);
	if (fractol->formula == &julia)
	{
		mlx_hook(fractol->win_ptr, 5, 0, press_julia, fractol);
		mlx_hook(fractol->win_ptr, 6, 0, change_julia, fractol);
	}
	draw_fractal(fractol);
	mlx_loop(fractol->mlx_ptr);
}

void	parse_arg(char *arg)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	if (!(ft_strcmp(arg, "Mandelbrot")))
	{
		fractol->formula = &mandelbrot;
		start(fractol);
	}
	else if (!(ft_strcmp(arg, "Julia")))
	{
		fractol->formula = &julia;
		start(fractol);
	}
	else if (!(ft_strcmp(arg, "Burning Ship")))
	{
		fractol->formula = &burning_ship;
		start(fractol);
	}
	free(fractol);
	print_help();
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		parse_arg(argv[1]);
	else
		print_help();
	return (0);
}
