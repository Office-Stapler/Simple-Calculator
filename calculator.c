#include "calculator.h"
void crossProduct(void) {
	Vector v1,v2;
	printf("Enter vector 1:\n");		
	v1 = scanVector();
	printf("Enter vector 2:\n");
	v2 = scanVector();
	Vector v3;
	v3.x = v1.y * v2.z - v2.y * v1.z;
	v3.y = v1.z * v2.x - v2.z * v1.x;
	v3.z = v1.x * v2.y - v2.x * v1.y;
	printf("The cross product of v1 and v2 is (%d %d %d)\n", v3.x, v3.y, v3.z);
}

double magnitude(Vector v1) {
	double magnitude;
	magnitude = sqrt((double)(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z));
	return magnitude;
}

int dotProduct(Vector v1, Vector v2) {
	int product;
	product = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return product;
}

Vector addVectors(Vector v1, Vector v2) {
	Vector v3;
	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;
	return v3;
}

void scaleVector(void) {
	Vector v1,v2;
	int scale;
	printf("Enter vector 1:\n");		
	v1 = scanVector();
	printf("Enter a scaler: \n");
	scanf("%d",&scale);
	v2.x = v1.x * scale;
	v2.y = v1.y * scale;
	v2.z = v1.z * scale;
	printf("v1 scaled by %d is (%d %d %d)\n", scale,  v2.x , v2.y, v2.z);
}

void projection(Vector v1, Vector v2) {
	int magnitude1;
	int product;
	magnitude1 = (int) pow(magnitude(v2),2);
	product = dotProduct(v1,v2);
	for(int i = 2; i <= (magnitude1 / 2) || i <= (product / 2); i++) {
		if (product % i == 0 && magnitude1 % i == 0) {
			product /= i;
			magnitude1 /= i;
			i = 2;
			continue;
		}
	}
	printf("The projection of v1 on v2 is %d / %d * (%d %d %d)\n", product, magnitude1, v2.x , v2.y, v2.z);
}

Matrix matrixAddition(Matrix m1, Matrix m2) {
	Matrix m3;
	m3.v1 = addVectors(m1.v1, m2.v1);
	m3.v2 = addVectors(m1.v2, m2.v2);
	m3.v3 = addVectors(m1.v3, m2.v3);
	return m3;
}

Matrix matrixMultiplication(Matrix m1, Matrix m2) {
	Matrix m3;
	Vector v1,v2,v3;
	// Vector the combination of 3 integers x,y,z
	// Matrix is the combination of 3 Vectors
	v1.x = m1.v1.x;
	v1.y = m1.v2.x;
	v1.z = m1.v3.x;

	v2.x = m1.v1.y;
	v2.y = m1.v2.y;
	v2.z = m1.v3.y;

	v3.x = m1.v1.z;
	v3.y = m1.v2.z;
	v3.z = m1.v3.z;

	m3.v1.x = dotProduct(v1,m2.v1);
	m3.v1.y = dotProduct(v2,m2.v1);
	m3.v1.z = dotProduct(v3,m2.v1);

	m3.v2.x = dotProduct(v1,m2.v2);
	m3.v2.y = dotProduct(v2,m2.v2);
	m3.v2.z = dotProduct(v3,m2.v2);

	m3.v3.x = dotProduct(v1,m2.v3);
	m3.v3.y = dotProduct(v2,m2.v3);
	m3.v3.z = dotProduct(v3,m2.v3);
	
	return m3;
}

int determinant(Matrix m1) {
	int det1,det2,det3,detfinal;
	det1 = m1.v1.x * (m1.v2.y * m1.v3.z - m1.v2.z * m1.v3.y);
	det2 = 0 - (m1.v2.x * (m1.v1.y * m1.v3.z - m1.v1.z * m1.v3.y));
	det3 = m1.v3.x * (m1.v1.y * m1.v2.z - m1.v1.z * m1.v2.y);
	detfinal = det1 + det2 + det3;
	return detfinal;
}

Matrix transposeMatrix(Matrix m1) {
	Matrix m2;
	m2.v1.x = m1.v1.x;
	m2.v1.y = m1.v2.x;
	m2.v1.z = m1.v3.x;

	m2.v2.x = m1.v1.y;
	m2.v2.y = m1.v2.y;
	m2.v2.z = m1.v3.y;

	m2.v3.x = m1.v1.z;
	m2.v3.y = m1.v2.z;
	m2.v3.z = m1.v3.z;

	return m2;
}

void printInstructions(void) {
	printf("Welcome to a basic calculator\n");
	printf("Enter 1 to cross product two 3D vectors\n");
	printf("Enter 2 to find the magnitude of a 3D vector\n");
	printf("Enter 3 to find the dot product of two 3D vectors\n");
	printf("Enter 4 to add two 3D vectors\n");
	printf("Enter 5 to scale a vector by a number\n");
	printf("Enter 6 to find the projection of vector v1 on v2\n");
	printf("Enter 7 to add two 3x3 matricies\n");
	printf("Enter 8 to multiply two 3x3 matricies\n");
	printf("Enter 9 to find the determinant of a 3x3 vector\n");
	printf("Enter a to transpose a matrix\n");
	printf("Enter h for all instructions\n");
}


Matrix scanMatrix(void) {
	Matrix m1;
	printf("Enter the values of column 1: ");
	m1.v1 = scanVector();
	printf("Enter the values of column 2: ");
	m1.v2 = scanVector();
	printf("Enter the values of column 3: ");
	m1.v3 = scanVector();
	return m1;
}
Vector scanVector(void) {
	Vector v1;
	scanf("%d %d %d",&(v1.x), &(v1.y), &(v1.z));
	return v1;
}

void printMatrix(Matrix m1) {
	printf("(%3d %3d %3d)\n", m1.v1.x, m1.v2.x, m1.v3.x);
	printf("(%3d %3d %3d)\n", m1.v1.y, m1.v2.y, m1.v3.y);
	printf("(%3d %3d %3d)\n", m1.v1.z, m1.v2.z, m1.v3.z);
}