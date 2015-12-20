#include "vector.h"

vec3D::vec3D()
{
	x = 0;
	y = 0;
	z = 0;
}

vec3D::vec3D(float a, float b)
{
	x = a;
	y = b;
	z = 0;
}

vec3D::vec3D(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}

float vec3D::dotProduct(const vec3D& vec)
{
	return (x*vec.x + y*vec.y + z*vec.z);
}

vec3D vec3D::crossProduct(const vec3D& vec)
{
	return vec3D();
}

float vec3D::Length()
{
	return sqrt(x*x + y*y + z*z);
}

void vec3D::Normalize()
{
	float len = Length();

	if(len!=0)
	{
		x /= len;
		y /= len;
		z /= len;
	}
}

void vec3D::Change(float a, float b, float c)
{
	x = a; 
	y = b;
	z = c;
}

void vec3D::Change(vec3D& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

void vec3D::Change(vec3D vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

	//setting operators

vec3D vec3D::operator+(const vec3D& vec)
{
	return vec3D(x+vec.x, y+vec.y, z+vec.z);
}

vec3D vec3D::operator-(const vec3D& vec)
{
	return vec3D(x-vec.x, y-vec.y, z-vec.z);
}

vec3D vec3D::operator*(float num)
{
	return vec3D(x*num, y*num, z*num);
}

vec3D vec3D::operator/(float num)
{
	if(num!=0)
	{
		return vec3D(x/num, y/num, z/num);
	}
	else
	{
		return vec3D();
	}
}

vec3D& vec3D::operator+=(const vec3D& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;

	return *this;
}

vec3D& vec3D::operator-=(const vec3D& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;

	return *this;
}

vec3D& vec3D::operator*=(float num)
{
	x *= num;
	y *= num;
	z *= num;

	return *this;
}

vec3D& vec3D::operator/=(float num)
{
	if(num!=0)
	{
		x /= num;
		y /= num;
		z /= num;
	}
	else
	{
		return *this;
	}
}

bool vec3D::operator==(const vec3D vec)
{
	return (x==vec.x && y==vec.y && z==vec.z);
}

bool vec3D::operator!=(const vec3D vec)
{
	!(*this==vec);
}

std::ostream& operator<<(std::ostream& out, vec3D& vec)
{
	return out << vec.x << " " << vec.y << " " << vec.z << std::endl;
}