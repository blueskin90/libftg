/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 02:57:13 by toliver           #+#    #+#             */
/*   Updated: 2018/01/30 02:59:44 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

float			ftg_degtorad(float angle)
{
	return (angle / 180.0 * M_PI);
}

float			ftg_radtodeg(float angle)
{
	return (angle * 180 / M_PI);
}
