/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 00:39:39 by toliver           #+#    #+#             */
/*   Updated: 2018/01/30 07:02:59 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_vec			ftg_vecdef(float x, float y, float z)
{
	t_vec		v;
	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec			ftg_vecadd(t_vec a, t_vec b)
{
	t_vec		v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_vec			ftg_vecsub(t_vec a, t_vec b)
{
	t_vec		v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

float			ftg_vecnorm(t_vec a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vec			ftg_vecnormalize(t_vec a)
{
	t_vec		v;
	float		norm;

	if ((norm = ftg_vecnorm(a)) != 1 && norm != 0)
	{
		v.x = a.x / norm;
		v.y = a.y / norm;
		v.z = a.z / norm;
		return (v);
	}
	else
		return (a);
}

float			ftg_vecdot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec			ftg_veccross(t_vec a, t_vec b)
{
	t_vec		v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return (v);
}

t_vec			ftg_vecscale(t_vec a, float s)
{
	t_vec		v;
	v.x = a.x * s;
	v.y = a.y * s;
	v.z = a.z * s;
	return (v);
}

t_vec			ftg_vecdiv(t_vec a, float s)
{
	t_vec		v;
	v.x = a.x / s;
	v.y = a.y / s;
	v.z = a.z / s;
	return (v);
}

t_vec			ftg_vecrotquat(t_vec a, t_quat b)
{
	t_quat		q;

	q = ftg_quatvecdef(a, 0);
	q = ftg_quatcross(b, q);
	q = ftg_quatcross(ftg_quatconj(b), q);
	return (ftg_vecdef(q.x, q.y, q.z));
}
