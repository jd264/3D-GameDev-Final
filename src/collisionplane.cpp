#include "collisionplane.h"

collisionPlane::collisionPlane(float n1, float n2, float n3, float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l)
{
	normal.Change(n1, n2, n3);
	p[0].Change(a, b, c);
	p[1].Change(d, e, f);
	p[2].Change(g, h, i);
	p[3].Change(j, k, l);
}