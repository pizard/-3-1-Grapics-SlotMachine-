#pragma once

#include <iostream>
#include "VECTOR.h"
class VERTEX
{
public:
	// VECTOR pos; //��ġ�� �ǹ��ϰ� x,y,z�� ��Ÿ���� --> �׳� x,y,z�� ��Ÿ��
	VECTOR normal; // vertex�� �������� �� �̹��������� ������� ����
	int index; // ID�� ��� vertex����!!
	int neighborFace; // �̿��� ���� ����
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
