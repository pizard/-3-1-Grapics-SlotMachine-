#pragma once

#include <math.h>
#include "VERTEX.h"
#include <math.h>


class MATRIX {
public:
	MATRIX Add(MATRIX m);		// 합
	MATRIX Subtract(MATRIX m);	// 차
	MATRIX Multiply(MATRIX m);	// 곱
	MATRIX Transpose(float angle, VERTEX v1, VERTEX v2);			// TAIL: v1, HEAD: v2 기준으로하는 축회전

	VERTEX Trans(MATRIX m1, VERTEX v4);	// 축회전을 실행하는 함수
	float ele[4][4];
	float num_of_rows = 4;
	float num_of_columns = 4;
	MATRIX() {
	}

	MATRIX(float a1, float a2, float a3, float a4, float b1, float b2, float b3, float b4, float c1, float c2, float c3, float c4, float d1, float d2, float d3, float d4)
	{
		ele[0][0] = a1;
		ele[0][1] = a2;
		ele[0][2] = a3;
		ele[0][3] = a4;

		ele[1][0] = b1;
		ele[1][1] = b2;
		ele[1][2] = b3;
		ele[1][3] = b4;

		ele[2][0] = c1;
		ele[2][1] = c2;
		ele[2][2] = c3;
		ele[2][3] = c4;

		ele[3][0] = d1;
		ele[3][1] = d2;
		ele[3][2] = d3;
		ele[3][3] = d4;

	}

};

VERTEX MATRIX::Trans(MATRIX m1, VERTEX v4) {
	VERTEX v5;
	v5.x = m1.ele[0][0] * v4.x + m1.ele[0][1] * v4.y + m1.ele[0][2] * v4.z + m1.ele[0][3] * 1.0f;
	v5.y = m1.ele[1][0] * v4.x + m1.ele[1][1] * v4.y + m1.ele[1][2] * v4.z + m1.ele[1][3] * 1.0f;
	v5.z = m1.ele[2][0] * v4.x + m1.ele[2][1] * v4.y + m1.ele[2][2] * v4.z + m1.ele[2][3] * 1.0f;

	return v5;
};


MATRIX MATRIX::Transpose(float angle, VERTEX v1, VERTEX v2) { // v1,v2: 직선 VECTOR
	MATRIX result;
	
	float a , b, c, d,l, cos_alpha, sin_alpha, cos_beta, sin_beta;
	a = v2.x - v1.x;
	b = v2.y - v1.y;
	c = v2.z - v1.z;
	d = sqrt(b*b + c*c);
	l = sqrt(a*a + b*b + c*c);
	if (d == 0){
		sin_alpha = 0;
		cos_alpha = 1;
	}
	else {
		sin_alpha = b / d;
		cos_alpha = c / d;	
	}
	// printf("cos_alpha = %f \n", cos_alpha);
	// printf("sin_alpha = %f \n", sin_alpha);
	if (l == 0) {
		sin_beta = 0;
		cos_beta = 1;
	}
	else {
		sin_beta = a / l;
		cos_beta = d / l;
	}
	
	const float PI = 3.1415926535f;
	float radians = angle * PI / 180;

	

	// MATRIX BASE = MATRIX(v3.x, 0.0f, 0.0f, 0.0f,
	//					 0.0f, v3.y, 0.0f, 0.0f,
	//				 	 0.0f, 0.0f, v3.z, 0.0f,
	//					 0.0f, 0.0f, 0.0f, 1.0f);
	
	MATRIX M1 = MATRIX( 1.0f, 0.0f, 0.0f, v1.x,
						0.0f, 1.0f, 0.0f, v1.y,
						0.0f, 0.0f, 1.0f, v1.z,
						0.0f, 0.0f, 0.0f, 1.0f);

	MATRIX M2 = MATRIX( 1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, cos_alpha, sin_alpha, 0.0f,
						0.0f, -sin_alpha, cos_alpha, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f);

	MATRIX M3 = MATRIX(cos_beta, 0.0f, sin_beta, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
						-sin_beta, 0.0f, cos_beta, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f);

	MATRIX M4 = MATRIX( cos(radians), -sin(radians), 0.0f, 0.0f,
						sin(radians),  cos(radians), 0.0f, 0.0f,
								0.0f,		0.0f,    1.0f, 0.0f,
								0.0f,		0.0f,    0.0f, 1.0f);
	
	MATRIX M5 = MATRIX(cos_beta, 0.0f, -sin_beta, 0.0f,
						0.0f, 1.0f, 0.0f, 0.0f,
					sin_beta, 0.0f, cos_beta, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f);
	
	MATRIX M6 = MATRIX(1.0f, 0.0f, 0.0f, 0.0f,
						0.0f, cos_alpha, -sin_alpha, 0.0f,
						0.0f, sin_alpha, cos_alpha, 0.0f,
						0.0f, 0.0f, 0.0f, 1.0f);

	MATRIX M7 = MATRIX( 1.0f, 0.0f, 0.0f, -v1.x,
						0.0f, 1.0f, 0.0f, -v1.y,
						0.0f, 0.0f, 1.0f, -v1.z,
						0.0f, 0.0f, 0.0f,  1.0f);

	
	result = M6.Multiply(M7);
	result = M5.Multiply(result);
	result = M4.Multiply(result);
	result = M3.Multiply(result);
	result = M2.Multiply(result);
	result = M1.Multiply(result);
	
	/*
	printf("-----------------result-----------------------------\n");
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf(" %f ", result.ele[i][j]);
		}
		printf(" \n");
	}
	*/

	return result;
}

MATRIX MATRIX::Add(MATRIX m)
{
	MATRIX result;
	for (int i = 0; i < num_of_rows; i++)
		for (int j = 0; j < num_of_columns; j++)
			result.ele[i][j] = ele[i][j] + m.ele[i][j];
	
	return result;
};


MATRIX MATRIX::Subtract(MATRIX m)
{
	MATRIX result;
	for (int i = 0; i < num_of_rows; i++)
		for (int j = 0; j < num_of_columns; j++)
			result.ele[i][j] = ele[i][j] - m.ele[i][j];

	return result;
};

MATRIX MATRIX::Multiply(MATRIX m)
{
	int i, j, k;
	MATRIX result;
	for (i = 0; i < num_of_rows; i++)
		for (j = 0; j < num_of_columns; j++)
			result.ele[i][j] = 0.0;


	if (num_of_columns == m.num_of_rows)
	{
		result.num_of_rows = num_of_rows;
		result.num_of_columns = m.num_of_columns;
		for (i = 0; i < num_of_rows; i++)
			for (j = 0; j < m.num_of_columns; j++)
				for (k = 0; k < num_of_columns; k++)
					result.ele[i][j] += ele[i][k] * m.ele[k][j];
	}

	return result;
};
