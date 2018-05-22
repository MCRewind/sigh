#include <iostream>

template<typename T>
class Vec3
{
public:
	Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
	Vec3(const T &xx) : x(xx), y(xx), z(xx) {}
	Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}

	T length()
	{
		return sqrt(x * x + y * y + z * z);
	} 

	Vec3<T>& normalize()
	{
		T len = length();
		if (len > 0) {
			T invLen = 1 / len;
			x *= invLen, y *= invLen, z *= invLen;
		}

		return *this;
	} 

	T x, y, z;
};

typedef Vec3<float> Vec3f;

int main(int argc, char **argv)
{
	Vec3f v;
	std::cout << v.length() << std::endl;
	return 0;
}