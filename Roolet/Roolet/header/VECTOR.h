#pragma once

#include <math.h>

using namespace std;


class VECTOR
{
	public:	
		float Magnitude();			// ��� �Լ���, ����Լ� �ȿ����� ��ü�� �̸��� ������� �ʰ� ���� ����!
		float InnerProduct(VECTOR v);	// ����
		VECTOR CrossProduct(VECTOR v);	// ����
		// void Normalize(VECTOR a);   --> �̹� �������� �Ⱦ��̳�!!!
		float x;				// ��� ������
		float y;
		float z;
};



float VECTOR::Magnitude()			// VECTOR Ŭ������ ��� �Լ��� Magnitude�� �ǹ��ϰ� float���� return��
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
{ // Face�� ���� Normalize
	
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
	} // neighbor ���ϴ� ����!!	
	Vertex *v = vertexArray[i]
		for (j < vertexArray[i].neighbor.size)
		{
			v.normal += vertexArray[i].neighbor[j].normal
		}
	v.normal /= vertexArray[i].neighbor.size
	
}
*/
