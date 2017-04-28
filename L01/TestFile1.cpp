//========================================================================
// SER 332 Project # - Name
//========================================================================
#include <Imath\ImathVec.h>

using namespace Imath;

typedef Vec3<float> Vec3f;

//========================================================================
// ***** DECLARATIONS *****
template<class T> T triangle_area(const Vec3<T> &v1, const Vec3<T> &v2, const Vec3<T> &v3);

//========================================================================
// ***** GLOBALS *****
Vec3f v0;
Vec3f v1;
Vec3f v2;

//========================================================================
// ***** MAIN *****
void main(int argc, char ** argv) {
	v0.setValue(-1, 0, 0);
	v1.setValue(1.0, 0.0, 0.0);
	v2.setValue(0, 1, 0);

	printf("V0 = (%f, %f, %f)\n", v0.x, v0.y, v0.z);
	printf("v1 = (%f, %f, %f)\n", v1.x, v1.y, v1.z);
	printf("v2 = (%f, %f, %f)\n", v2.x, v2.y, v2.z);

	float dotproduct = v1.dot(v2);
	printf("v1 * v2 = %f\n", dotproduct);

	Vec3f v3 = v1.cross(v2);
	printf("v0 x v1 = (%.2f,%.2f,%.2f)\n", v3.x, v3.y, v3.z);

	v1.setValue(100.0, 100.0, 100.0);
	v2 = v1;
	v2 += Vec3f(1, 0, 0);
	printf("v1 = (%.2f,%.2f,%.2f)\n", v1.x, v1.y, v1.z);
	printf("v2 = (%.2f,%.2f,%.2f)\n", v2.x, v2.y, v2.z);
	printf("v1 ==  v2 is (%i)\n", (v1 == v2));

	float area = triangle_area(v0, v1, v2);
	printf("the area of the triangle is %.4f\n", area);
}

//========================================================================
// ***** AREA CALC *****
template<class T> T triangle_area(const Vec3<T> &v1, const Vec3<T> &v2, const Vec3<T> &v3) {
	Vec3<T> AB = v2 - v1;
	Vec3<T> AC = v3 - v1;

	return (AB.cross(AC)).length() / 2;
}
