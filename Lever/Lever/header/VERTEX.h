#pragma once

#include <iostream>
#include "VECTOR.h"
class VERTEX
{
public:
	// VECTOR pos; //위치를 의미하고 x,y,z로 나타내짐 --> 그냥 x,y,z로 나타냄
	VECTOR normal; // vertex의 법선벡터 는 이번과제에서 사용하지 않음
	int index; // ID와 몇번 vertex인지!!
	int neighborFace; // 이웃한 면의 개수
	float x;
	float y;
	float z;

	
	VERTEX() {
	}
	VERTEX(float a, float b, float c) {
		x = a;
		y = b;
		z = c;
	}
	
};



/*
	
	
	
	VECTOR VERTEX::pos()
	{
		VECTOR result;
		return result;
	}
*/
