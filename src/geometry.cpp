#include <iostream>

template<typename T>
class Vec3
{
public:
	Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
	Vec3(const T &xx) : x(xx), y(xx), z(xx) {}
	Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}

	Vec3 operator + (const Vec3 &v) const
	{ 
		return Vec3(x + v.x, y + v.y, z + v.z);
	}

	Vec3 operator - (const Vec3 &v) const
	{
		return Vec3(x - v.x, y - v.y, z - v.z);
	}

	Vec3 operator * (const T &r) const
	{
		return Vec3(x * r, y * r, z * r);
	} 

	T norm() const
	{
		return x * x + y * y + z * z;
	}

	T length() const
	{
		return sqrt(norm());
	} 

	T dot(const Vec3<T> &v) const
	{
		 return x * v.x + y * v.y + z * v.z;
	}

	Vec3<T> cross(const Vec3<T> &v) const
	{
		return Vec3<T>
		(
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x
		); 
	}

	 Vec3& normalize()
	{
		T n = norm();
		if (n > 0) 
		{
			T factor = 1 / sqrt(n);
			x *= factor, y *= factor, z *= factor;
		}

		return *this;
	} 

	friend std::ostream& operator << (std::ostream &s, const Vec3<T> &v)
	{
		return s << '(' << v.x << ' ' << v.y << ' ' << v.z << ')';
	} 

	T x, y, z;
};

typedef Vec3<float> Vec3f;

int main(int argc, char **argv)
{
	Vec3f v(1, 2, 3);
	std::cout << v.length() << std::endl;
	return 0;
}