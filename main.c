#include "libftg.h"
#include <stdio.h>

int				main(void)
{
	t_vec		a;
	t_quat		b;

	a = ftg_vecdef(1, 1, 1);
	b = ftg_quatrotdef(1, 0, 0, 180);
	a = ftg_vecrotquat(a, b);
	printf("A = x = %f, y = %f, z = %f\n", a.x, a.y, a.z);
	return (0);
}
