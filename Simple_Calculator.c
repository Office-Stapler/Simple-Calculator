#include "calculator.h"

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
			printMatrix(m3);
		} else if (c == '8') {
			Matrix m1,m2,m3;
			printf("Matrix 1\n");
			m1 = scanMatrix();
			printf("Matrix 2\n");
			m2 = scanMatrix();
			m3 = matrixMultiplication(m1,m2);
			printf("The product of the two matricies is:\n");
			printMatrix(m3);
		} else if (c == '9') {
			printf("Matrix 1\n");
			Matrix m1 = scanMatrix();
			printf("The determinant of the matrix is %d\n", determinant(m1));
		} else if (c == 'a') {
			Matrix m1 = scanMatrix();
			Matrix m2 = transposeMatrix(m1);
			printf("The transposed matrix is:\n");
			printMatrix(m2);
		} else if (c == 'h') {
			printInstructions();
		}
		if (c != '\n') {
			printf("Enter a command: ");
		}
	}
	printf("Goodbye!\n");
}


