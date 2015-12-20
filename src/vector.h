#include <iostream>
#include <cmath>

#ifndef __VECTOR_H__
#define __VECTOR_H__

class vec3D
{
public:
	float x, y, z;
	vec3D();
	vec3D(float a, float b);
	vec3D(float a, float b, float c);

	float dotProduct(const vec3D& vec);
	vec3D crossProduct(const vec3D& vec);
	float Length();
	void Normalize();

	void Change(float a, float b, float c);
	void Change(vec3D& vec);
	void Change(vec3D vec);

	//setting operators
	vec3D operator+(const vec3D& vec);
	vec3D operator-(const vec3D& vec);
	vec3D operator*(float num);
	vec3D operator/(float num);

	vec3D& operator+=(const vec3D& vec);
	vec3D& operator-=(const vec3D& vec);
	vec3D& operator*=(float num);
	vec3D& operator/=(float num);

	bool operator==(const vec3D vec);
	bool operator!=(const vec3D vec);

	friend std::ostream& operator<<(std::ostream& out, vec3D& vec);
};

#endif