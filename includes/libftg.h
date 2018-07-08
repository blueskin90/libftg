/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 00:24:18 by toliver           #+#    #+#             */
/*   Updated: 2018/02/26 02:37:44 by toliver          ###   ########.fr       */
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

//typedef float t_vec __attribute__ ((ext_vector_type(3)));

typedef struct	s_quat
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_quat;

typedef struct	s_quatv
{
	t_vec		v;
	float		w;
}				t_quatv;


//#define ftg_vecadd(x, y) x+y
//#define ftg_vecsub(x, y) x-y

t_vec			ftg_vecdef(float x, float y, float z);
t_vec			ftg_vecadd(t_vec a, t_vec b);
t_vec			ftg_vecsub(t_vec a, t_vec b);
t_vec			ftg_vecnormalize(t_vec a);
t_vec			ftg_vecscale(t_vec a, float s);
t_vec			ftg_vecdiv(t_vec a, float s);
t_vec			ftg_veccross(t_vec a, t_vec b);
float			ftg_vecdot(t_vec a, t_vec b);
float			ftg_vecnorm(t_vec a);
t_vec			ftg_vecrotquat(t_vec a, t_quat b);

t_quat			ftg_quatdef(float x, float y, float z, float w);
t_quat			ftg_quatvecdef(t_vec a, float w);
t_quat			ftg_quatvecrotdef(t_vec a, float angle);
t_quat			ftg_quatrotdef(float x, float y, float z, float angle);
t_quat			ftg_quatadd(t_quat a, t_quat b);
t_quat			ftg_quatsub(t_quat a, t_quat b);
float			ftg_quatnorm(t_quat a);
t_quat			ftg_quatnormalize(t_quat a);
t_quat			ftg_quatconj(t_quat a);
t_quat			ftg_quatcross(t_quat a, t_quat b);
t_quat			ftg_quatrotadd(t_quat a, t_quat b);

float			ftg_degtorad(float angle);
float			ftg_radtodeg(float angle);
#endif
