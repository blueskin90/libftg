/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 00:24:18 by toliver           #+#    #+#             */
/*   Updated: 2018/01/30 00:30:14 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTG_H
# define LIBFTG_H

# include <stdlib.h>
# include <math.h>

typedef struct	s_vec
{
	float		x;
	float		y;
	float		z;
}				t_vec;

typedef struct	s_quat
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_quat;

#endif
