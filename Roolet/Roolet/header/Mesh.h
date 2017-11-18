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
	float n1_M, n2_M; // n1, n2의 크기
	printf("VECTOR n1의 TAIL VERTEX index: %d번, VECTOR n1의 HEAD VERTEX index: %d번 \n", v1.index, v2.index);
	printf("VECTOR n2의 TAIL VERTEX index: %d번, VECTOR n2의 HEAD VERTEX index: %d번 \n", v3.index, v4.index);

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
		printf("두 VECTOR간의 관계는 '같은 방향'입니다.\n");
	else if (check == -n1_M * n2_M)
		printf("두 VECTOR간의 관계는 '반대 방향'입니다.\n");
	else if (check > 0)
		printf("두 VECTOR간의 관계는 '예각'입니다.\n");
	else if (check == 0)
		printf("두 VECTOR간의 관계는 '직각'입니다.\n");
	else
		printf("두 VECTOR간의 관계는 '둔각'입니다.\n");
};

void Mesh::Pos_Neg_Check(FACE f, float a, float b, float c) 
{
	VECTOR n1, n2, n3;
	float check; // n1, n2의 크기
	
	n1.x = f.v1.x - f.v2.x;
	n1.y = f.v1.y - f.v2.y;
	n1.z = f.v1.z - f.v2.z;

	n2.x = f.v2.x - f.v3.x;
	n2.y = f.v2.y - f.v3.y;
	n2.z = f.v2.z - f.v3.z;

	n3 = n1.CrossProduct(n2);
	
	check = n3.x * (a - f.pos.x) + n3.y * (b - f.pos.y) + n3.z *(c - f.pos.z);
	printf("position이 (%f, %f, %f)인 Face와의 관계 \n", f.pos.x, f.pos.y, f.pos.z);
	if (check == 0)
		cout << "같은 평면 안의 점입니다.\n";
	else if (check > 0)
		cout << " Positive한 점입니다.\n";
	else if (check < 0)
		cout << " Negative한 점입니다.\n";

}