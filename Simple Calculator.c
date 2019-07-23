#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct vector {
	int x;
	int y;
	int z;
} Vector;

typedef struct matrix{
	Vector v1;
	Vector v2;
	Vector v3;
} Matrix;

void crossProduct(void);
int dotProduct(Vector v1, Vector v2);
double magnitude(Vector v1);
Vector addVectors(Vector v1, Vector v2);
void scaleVector(void);
void projection(Vector v1, Vector v2);
void printInstructions(void);
Matrix matrixAddition(Matrix m1, Matrix m2);
Matrix matrixMultiplication(Matrix m1, Matrix m2);
Matrix scanMatrix(void);
Vector scanVector(void);

int main(void) {
	printInstructions();
	printf("Enter a command: ");
	char c = getchar();
	int i = 0;
	for (; c != '0'; c = getchar() ) {
		if (c == '1') {
			crossProduct();
		} else if (c == '2') {
			Vector v1;
			double magnitude1;
			printf("Enter a 3D vector\n");
			v1 = scanVector();
			magnitude1 = magnitude(v1);
			printf("The magnitude of (%d %d %d) is %2.2f\n", v1.x, v1.y, v1.z, magnitude1);
		} else if (c == '3') {
			Vector v1,v2;
			printf("Enter vector 1:\n");		
			v1 = scanVector();
			printf("Enter vector 2:\n");
			v2 = scanVector();
			int product = dotProduct(v1,v2);
			printf("The dot product of v1 and v2 is %d\n", product);
		} else if (c == '4') {
			Vector v1,v2,v3;
			printf("Enter vector 1:\n");		
			v1 = scanVector();
			printf("Enter vector 2:\n");
			v2 = scanVector();
			v3 = addVectors(v1,v2);
			printf("The sum of v1 and v2 is (%d %d %d)\n", v3.x , v3.y, v3.z);
		} else if (c == '5') {
			scaleVector();
		} else if (c == '6') {
			Vector v1,v2;
			printf("Enter vector 1:\n");		
			v1 = scanVector();
			printf("Enter vector 2:\n");
			v2 = scanVector();
			projection(v1,v2);
		} else if (c == '7') {
			Matrix m1, m2,m3;
			printf("Matrix 1\n");
			m1 = scanMatrix();
			printf("Matrix 2\n");
			m2 = scanMatrix();
			m3 = matrixAddition(m1, m2);
			printf("The sum of the two matricies is:\n");
			printf("%d %d %d\n", m3.v1.x, m3.v2.x, m3.v3.x);
			printf("%d %d %d\n", m3.v1.y, m3.v2.y, m3.v3.y);
			printf("%d %d %d\n", m3.v1.z, m3.v2.z, m3.v3.z);
		} else if (c == '8') {
			Matrix m1,m2,m3;
			printf("Matrix 1\n");
			m1 = scanMatrix();
			printf("Matrix 2\n");
			m2 = scanMatrix();
			m3 = matrixMultiplication(m1,m2);
			printf("The product of the two matricies is:\n");
			printf("%d %d %d\n", m3.v1.x, m3.v2.x, m3.v3.x);
			printf("%d %d %d\n", m3.v1.y, m3.v2.y, m3.v3.y);
			printf("%d %d %d\n", m3.v1.z, m3.v2.z, m3.v3.z);
		} else if (c == 'h') {
			printInstructions();
		}
		if (c != '\n') {
			printf("Enter a command: ");
		}
	}
	printf("Goodbye!\n");
}

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

void printInstructions(void) {
	printf("Welcome to a basic calculator\n");
	printf("Enter 1 to cross product two 3D vectors\n");
	printf("Enter 2 to find the magnitude of a 3D vector\n");
	printf("Enter 3 to find the dot product of two 3D vectors\n");
	printf("Enter 4 to add two 3D vectors\n");
	printf("Enter 5 to scale a vector by a number\n");
	printf("Enter 6 to find the projection of vector v1 on v2\n");
	printf("Enter 7 to add two 3x3 matricies\n");
	printf("Enter 8 to multiply two 3x3 vectors\n");
	printf("Enter h for all instructions\n");
}


Matrix scanMatrix(void) {
	Matrix m1;
	printf("Enter the values of row 1: ");
	scanf("%d %d %d",&m1.v1.x, &m1.v2.x, &m1.v3.x);
	printf("Enter the values of row 2: ");
	scanf("%d %d %d",&m1.v1.y, &m1.v2.y, &m1.v3.y);
	printf("Enter the values of row 3: ");
	scanf("%d %d %d",&m1.v1.z, &m1.v2.z, &m1.v3.z);
	return m1;
}
Vector scanVector(void) {
	Vector v1;
	scanf("%d %d %d",&(v1.x), &(v1.y), &(v1.z));
	return v1;
}
