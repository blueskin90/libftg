/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 03:00:10 by toliver           #+#    #+#             */
/*   Updated: 2018/01/30 07:03:01 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_quat			ftg_quatdef(float x, float y, float z, float w)
{
	t_quat		v;
	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}

t_quat			ftg_quatvecdef(t_vec a, float w)
{
	return (ftg_quatdef(a.x, a.y, a.z, w));	
}

t_quat			ftg_quatvecrotdef(t_vec a, float angle)
{
	return (ftg_quatvecdef(ftg_vecscale(ftg_vecnormalize(a), sin(ftg_degtorad(angle) / 2.0))
				, cos(ftg_degtorad(angle) / 2.0)));
}

t_quat			ftg_quatrotdef(float x, float y, float z, float angle)
{
	t_vec		v;

	v = ftg_vecdef(x, y, z);
	return (ftg_quatvecdef(ftg_vecscale(ftg_vecnormalize(v), sin(ftg_degtorad(angle) / 2.0))
				, cos(ftg_degtorad(angle) / 2.0)));
}

t_quat			ftg_quatadd(t_quat a, t_quat b)
{
	t_quat		v;
	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	v.w = a.w + b.w;
	return (v);
}

t_quat			ftg_quatsub(t_quat a, t_quat b)
{
	t_quat		v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	v.w = a.w - b.w;
	return (v);
}

float			ftg_quatnorm(t_quat a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w));
}

t_quat			ftg_quatnormalize(t_quat a)
{
	t_quat		v;
	float		norm;

	if ((norm = ftg_quatnorm(a)) != 1)
	{
		v.x = a.x / norm;
		v.y = a.y / norm;
		v.z = a.z / norm;
		v.w = a.w / norm;
		return (v);
	}
	else
		return (a);
}

t_quat			ftg_quatconj(t_quat a)
{
	t_quat		v;

	v.x = -a.x;
	v.y = -a.y;
	v.z = -a.z;
	v.w = a.w;
	return (a);
}

t_quat			ftg_quatrotadd(t_quat a, t_quat b)
{
	t_vec		av;
	t_vec		bv;
	t_vec		qv;
	t_quat		q;

	av = ftg_vecdef(a.x, a.y, a.z);
	bv = ftg_vecdef(b.x, b.y, b.z);
	q.w = ftg_vecdot(av, bv);
	qv = ftg_veccross(av, bv);
	qv = ftg_vecadd(qv, ftg_vecscale(av, b.w));
	qv = ftg_vecadd(qv, ftg_vecscale(bv, a.w));
	q = ftg_quatvecdef(qv, q.w);
	q = ftg_quatnormalize(q);
	return (q);
}

t_quat			ftg_quatcross(t_quat a, t_quat b)
{
	t_vec		av;
	t_vec		bv;
	t_vec		qv;
	t_quat		q;

	av = ftg_vecdef(a.x, a.y, a.z);
	bv = ftg_vecdef(b.x, b.y, b.z);
	q.w = ftg_vecdot(av, bv);
	qv = ftg_veccross(av, bv);
	qv = ftg_vecadd(qv, ftg_vecscale(av, b.w));
	qv = ftg_vecadd(qv, ftg_vecscale(bv, a.w));
	q = ftg_quatvecdef(qv, q.w);
	return (q);
}

