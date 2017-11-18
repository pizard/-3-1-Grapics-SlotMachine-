#pragma once
#include "VECTOR.h"
#include "VERTEX.h"
#include <math.h>
#include <iostream>

class Mesh
{
	
public:
	void AngleCheck(VERTEX v1, VERTEX v2, VERTEX v3, VERTEX v4);
	void Pos_Neg_Check(FACE f, float a, float b, float c);	
	
};



void Mesh::AngleCheck(VERTEX v1, VERTEX v2, VERTEX v3, VERTEX v4)
{	
	VECTOR n1, n2;
	float n1_M, n2_M; // n1, n2�� ũ��
	printf("VECTOR n1�� TAIL VERTEX index: %d��, VECTOR n1�� HEAD VERTEX index: %d�� \n", v1.index, v2.index);
	printf("VECTOR n2�� TAIL VERTEX index: %d��, VECTOR n2�� HEAD VERTEX index: %d�� \n", v3.index, v4.index);

	n1.x = v2.x - v1.x;
	n1.y = v2.y - v1.y;
	n1.z = v2.z - v1.z;

	n2.x = v4.x - v3.x;
	n2.y = v4.y - v3.y;
	n2.z = v4.z - v3.z;
	
	n1_M = n1.Magnitude();
	n2_M = n2.Magnitude();
	
	float check = n1.InnerProduct(n2);
	
	if (check == n1_M * n2_M)
		printf("�� VECTOR���� ����� '���� ����'�Դϴ�.\n");
	else if (check == -n1_M * n2_M)
		printf("�� VECTOR���� ����� '�ݴ� ����'�Դϴ�.\n");
	else if (check > 0)
		printf("�� VECTOR���� ����� '����'�Դϴ�.\n");
	else if (check == 0)
		printf("�� VECTOR���� ����� '����'�Դϴ�.\n");
	else
		printf("�� VECTOR���� ����� '�а�'�Դϴ�.\n");
};

void Mesh::Pos_Neg_Check(FACE f, float a, float b, float c) 
{
	VECTOR n1, n2, n3;
	float check; // n1, n2�� ũ��
	
	n1.x = f.v1.x - f.v2.x;
	n1.y = f.v1.y - f.v2.y;
	n1.z = f.v1.z - f.v2.z;

	n2.x = f.v2.x - f.v3.x;
	n2.y = f.v2.y - f.v3.y;
	n2.z = f.v2.z - f.v3.z;

	n3 = n1.CrossProduct(n2);
	
	check = n3.x * (a - f.pos.x) + n3.y * (b - f.pos.y) + n3.z *(c - f.pos.z);
	printf("position�� (%f, %f, %f)�� Face���� ���� \n", f.pos.x, f.pos.y, f.pos.z);
	if (check == 0)
		cout << "���� ��� ���� ���Դϴ�.\n";
	else if (check > 0)
		cout << " Positive�� ���Դϴ�.\n";
	else if (check < 0)
		cout << " Negative�� ���Դϴ�.\n";

}