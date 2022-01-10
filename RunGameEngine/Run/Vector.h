#pragma once

struct Vector2
{
	double x, y;
	Vector2(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	Vector2()
	{
		this->x = 0;
		this->y = 0;
	}
};
struct Vector3
{
	double x, y, z;

	Vector3(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
};