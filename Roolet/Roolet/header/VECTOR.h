#pragma once

#include <math.h>

using namespace std;


class VECTOR
{
	public:	
		float Magnitude();			// 멤버 함수들, 멤버함수 안에서는 객체의 이름을 명시하지 않고 접근 가능!
		float InnerProduct(VECTOR v);	// 내적
		VECTOR CrossProduct(VECTOR v);	// 외적
		// void Normalize(VECTOR a);   --> 이번 과제에는 안쓰이네!!!
		float x;				// 멤버 변수들
		float y;
		float z;
};



float VECTOR::Magnitude()			// VECTOR 클래스의 멤버 함수인 Magnitude를 의미하고 float형을 return함
{
	return sqrt(x*x + y*y + z*z);
}


float VECTOR::InnerProduct(VECTOR v)
{
	return (x * v.x + y * v.y + z * v.z);
}


VECTOR VECTOR::CrossProduct(VECTOR v)
{
	VECTOR result;
	result.x = y*v.z - z*v.y;
	result.y = z*v.x - x*v.z;
	result.z = x*v.y - y*v.x;

	return result;
}

/*
friend void VECTOR::Normalize(FACE a) 
{ // Face에 대한 Normalize
	
	for (i < faceArray.size) {
		Face *f = faceArray[i]
			Vector n1 = f.vertexID.y - f.vertexID.x
			Vector n2 = f.vertexID.z - f.vertexID.x
			f.normal = n1.cross(n2);
	}
}
{
	int i = 0;
		for(i< vertexArray.size())
	{
		for (j < faceArray.size())
		{
			if (faceArray[j].vertexID.xyz == i)
				vertexArray[i].neighbor.Put(faceArray[j]
		}
	} // neighbor 구하는 공식!!	
	Vertex *v = vertexArray[i]
		for (j < vertexArray[i].neighbor.size)
		{
			v.normal += vertexArray[i].neighbor[j].normal
		}
	v.normal /= vertexArray[i].neighbor.size
	
}
*/
