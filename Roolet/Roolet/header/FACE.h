#pragma once

#include "VECTOR.h"
#include "VERTEX.h"
class FACE
{
	public:
		VECTOR vertexID;    // 면을 이루고있는 3개의 vertex에 대한 ID를 저장하고 vertexID.x에 첫번째 점의 정보... 
		VECTOR normal;		// Face의 법선벡터:면의 두 벡터의 외적을 구하면 됩니다.
		VERTEX pos;			// Face의 Position으로 편의 중앙값을 나타냅니다.
		VERTEX H_pos;
		void position();	// Face의 Position을 구하는 함수입니다.
		
		void FACE::H_position();
		void normalization(VERTEX a1, VERTEX a2, VERTEX a3);	// normal을 구하는 함수입니다.
		VERTEX v1;	// FACE를 이루는 3개의 VERTEX입니다.
		VERTEX v2;
		VERTEX v3;
		VERTEX v4;
		VERTEX v5;
		VERTEX v6;
		
		FACE(VERTEX a, VERTEX b, VERTEX c, VERTEX d, VERTEX e, VERTEX f) {
			v1 = a;
			v2 = b;
			v3 = c;
			v4 = d;
			v5 = e;
			v6 = f;
		}
		FACE() {
		}

		FACE(VERTEX a, VERTEX b, VERTEX c) {
			v1 = a;
			v2 = b;
			v3 = c;
		}		

		
};


void FACE::H_position() {
	VERTEX a;
	a.x = (v1.x + v2.x + v3.x + v4.x + v5.x + v6.x) / 6;
	a.y = (v1.y + v2.y + v3.y + v4.y + v5.y + v6.y) / 6;
	a.z = (v1.z + v2.z + v3.z + v4.z + v5.z + v6.z) / 6;
	H_pos.x = a.x;
	H_pos.y = a.y;
	H_pos.z = a.z;
}
void FACE::position() {
	VERTEX a1;
	a1.x = (v1.x + v2.x + v3.x) / 3;
	a1.y = (v1.y + v2.y + v3.y) / 3;
	a1.z = (v1.z + v2.z + v3.z) / 3;
	pos.x = a1.x;
	pos.y = a1.y;
	pos.z = a1.z;
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





