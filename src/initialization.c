/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkrippne <wkrippne@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 09:57:04 by wkrippne          #+#    #+#             */
/*   Updated: 2023/04/08 22:56:43 by wkrippne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* clean_init:
*	Initializes the fractol data structure with default
*	values to be replaced later. Used for error detection.
*/
void	clean_init(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->set = -1;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->kr = 0;
	f->ki = 0;
	f->sx = 0;
	f->rx = 0;
	f->fx = 0;
	f->palette = NULL;
	f->color_pattern = -1;
	f->color = 0;
}

/* get_complex_layout:
*	Maps the complex number axes to the window width and height to
*	create an equivalence between a given pixel and a complex number.
*	Julia needs a bit more space to the right than Mandelbrot,
*	so the mapping must also be shifted slightly.
*	Also, one of the edges is always calculated according to the other edges
*	to avoid fractal distortion if the window proportions change.
*/
void	get_complex_layout(t_fractol *f)
{
	if (f->set == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -1.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->max_i = -1.0;
		f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

/* init_img:
*	Initializes an MLX image and a color palette. The color palette will
*	be used to store every shade of color for every iteration number,
*	and the color of each pixel will be stored in the image, which will
*	then be displayed in the program window.
*/
static void	init_img(t_fractol *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	f->palette = ft_calloc((MAX_ITERATIONS + 1), sizeof(int));
	if (!(f->palette))
		clean_exit(msg("error initializing color scheme.", "", 1), f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
		clean_exit(msg("image creation error.", "", 1), f);
	buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	f->buf = buf;
}

/* reinit_image:
*	Cleanly reinitializes the MLX image if the color palette or 
*	fractal type is modified at runtime.
*/
void	reinit_img(t_fractol *f)
{
	if (f->mlx && f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->palette)
		free(f->palette);
	if (f->buf)
		f->buf = NULL;
	init_img(f);
}

/* init:
*	Creates a new MLX instance, a new window and populates
*	the fractol data structure with default values.
*/
void	init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit(msg("MLX: error connecting to mlx.", "", 1), f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		clean_exit(msg("MLX: error creating window.", "", 1), f);
	f->sx = 1.9;
	f->rx = 0.6;
	f->fx = -1.0;
	get_complex_layout(f);
	color_shift(f);
}
