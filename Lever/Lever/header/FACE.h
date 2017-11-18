#pragma once

#include "VECTOR.h"
#include "VERTEX.h"
class FACE
{
	public:
		VECTOR vertexID;    // 면을 이루고있는 3개의 vertex에 대한 ID를 저장하고 vertexID.x에 첫번째 점의 정보... 
		VECTOR normal;		// Face의 법선벡터:면의 두 벡터의 외적을 구하면 됩니다.
		VERTEX pos;			// Face의 Position으로 편의 중앙값을 나타냅니다.
		VERTEX R_pos;
		VERTEX R_pos2;
		VERTEX P_pos;
		VERTEX P_pos2;
		void position();	// Face의 Position을 구하는 함수입니다.
		void R_position();
		void P_position();
		void FACE::R_position2();
		void normalization(VERTEX a1, VERTEX a2, VERTEX a3);	// normal을 구하는 함수입니다.
		VERTEX v1;	// FACE를 이루는 3개의 VERTEX입니다.
		VERTEX v2;
		VERTEX v3;
		VERTEX v4;
		
		FACE(VERTEX a, VERTEX b, VERTEX c, VERTEX d) {
			v1 = a;
			v2 = b;
			v3 = c;
			v4 = d;
		}
		FACE() {
		}

		FACE(VERTEX a, VERTEX b, VERTEX c) {
			v1 = a;
			v2 = b;
			v3 = c;
		}		

		
};
void FACE::position() {
	VERTEX a1;
	a1.x = (v1.x + v2.x + v3.x) / 3;
	a1.y = (v1.y + v2.y + v3.y) / 3;
	a1.z = (v1.z + v2.z + v3.z) / 3;
	pos.x = a1.x;
	pos.y = a1.y;
	pos.z = a1.z;
}

void FACE::R_position() {
	VERTEX a1;
	a1.x = (v1.x + v2.x + v3.x + v4.x) / 4;
	a1.y = (v1.y + v2.y + v3.y + v4.y) / 4;
	a1.z = (v1.z + v2.z + v3.z + v4.z) / 4;
	
	R_pos.x = a1.x;
	R_pos.y = a1.y;
	R_pos.z = a1.z;
}

void FACE::R_position2() {
	VECTOR k1;
	k1.x = v1.x - v2.x;
	k1.y = v1.y - v2.y;
	k1.z = v1.z - v2.z;

	R_pos2.x = R_pos.x + k1.x;
	R_pos2.y = R_pos.y + k1.y;
	R_pos2.z = R_pos.z + k1.z;
}



void FACE::P_position() {
	VERTEX a1; // Face의 중앙 VERTEX
	VERTEX p1; // 육면체 중앙 VERTEX
	VECTOR s1; // v1, v2 방향 벡터( 기준점이 될 것임)
	int l;
	l = sqrt((v1.x - v2.x) * (v1.x - v2.x)) / 2;
	
	a1.x = (v1.x + v2.x + v3.x + v4.x) / 4;
	a1.y = (v1.y + v2.y + v3.y + v4.y) / 4;
	a1.z = (v1.z + v2.z + v3.z + v4.z) / 4;
	
	p1.x = a1.x + normal.x*l;
	p1.y = a1.y + normal.y*l;
	p1.z = a1.z + normal.z*l;

	P_pos.x = p1.x;
	P_pos.y = p1.y;
	P_pos.z = p1.z;
}

void FACE::normalization(VERTEX a1, VERTEX a2, VERTEX a3) {
	VECTOR n1;
	VECTOR n2;
	VECTOR n3;
	int l;
	n1.x = a1.x - a2.x;
	n1.y = a1.y - a2.y;
	n1.z = a1.z - a2.z;
	
	n2.x = a2.x - a3.x;
	n2.y = a2.y - a3.y;
	n2.z = a2.z - a3.z;


	n3 = n1.CrossProduct(n2);
	l = sqrt(n3.x * n3.x + n3.y * n3.y + n3.z * n3.z);
	n3.x = n3.x / l;
	n3.y = n3.y / l;
	n3.z = n3.z / l;
	

	normal.x = n3.x;
	normal.y = n3.y;
	normal.z = n3.z;
}





