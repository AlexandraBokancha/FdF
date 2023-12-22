/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:50:17 by albokanc          #+#    #+#             */
/*   Updated: 2023/12/20 16:28:19 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/fdf.h"

int create_trgb(t_trgb *t_trgb)
{
	return (t_trgb->t << 24 | t_trgb->r << 16 | t_trgb->g << 8 | t_trgb->b);
}

int add_shade(t_trgb *t_trgb, double shade_factor)
{	
	t_trgb->r = t_trgb->r * (1 - shade_factor);
	t_trgb->g = t_trgb->g * (1 - shade_factor);
	t_trgb->b = t_trgb->b * (1 - shade_factor);
	return (create_trgb(t_trgb));
}

int get_opposite(t_trgb *t_trgb)
{
	t_trgb->r = 255 - t_trgb->r;
	t_trgb->g = 255 - t_trgb->g;
	t_trgb->b = 255 - t_trgb->b;
	return (create_trgb(t_trgb));
}
