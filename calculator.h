#include <stdio.h>
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
int determinant(Matrix m1);
Matrix transposeMatrix(Matrix m1);
Matrix scanMatrix(void);
Vector scanVector(void);
void printMatrix(Matrix m1);