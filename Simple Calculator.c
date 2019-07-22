#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct vector {
	int x;
	int y;
	int z;
} Vector;

void cross_product(void);
int dot_product(Vector v1, Vector v2);
double magnitude(Vector v1);
void add_vectors(void);
void scale_vector(void);
// void projection(void);
Vector scanVector(void);

int main(void) {
	printf("Welcome to a basic calculator\n");
	printf("Enter 1 to cross product two 3D vectors\n");
	printf("Enter 2 to find the magnitude of a 3D vector\n");
	printf("Enter 3 to find the dot product of two 3D vectors\n");
	printf("Enter 4 to add two 3D vectors\n");
	printf("Enter 5 to scale a vector by a number\n");
	// printf("Enter 6 to find the projection of vector v1 on v2\n");
	printf("Enter a command: ");
	char c = getchar();
	int i = 0;
	for (; c != '0'; c = getchar() ) {
		if (c == '1') {
			cross_product();
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
			int product = dot_product(v1,v2);
			printf("The dot product of v1 and v2 is %d\n", product);
		} else if (c == '4') {
			add_vectors();
		} else if (c == '5') {
			scale_vector();
		} 
		#if 0 
		else if (c == '6') {
			projection();
		} 
		#endif	
		if (c != '\n') {
			printf("Enter a command: ");
		}
	}
	printf("Goodbye!\n");
}

void cross_product(void) {
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

int dot_product(Vector v1, Vector v2) {
	int product;
	product = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return product;
	
}

void add_vectors(void) {
	Vector v1,v2,v3;
	printf("Enter vector 1:\n");		
	v1 = scanVector();
	printf("Enter vector 2:\n");
	v2 = scanVector();
	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;
	printf("The sum of v1 and v2 is (%d %d %d)\n", v3.x , v3.y, v3.z);
}

void scale_vector(void) {
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

void projection(void) {
	Vector v1,v2;
	printf("Enter vector 1:\n");		
	v1 = scanVector();
	printf("Enter vector 2:\n");
	v2 = scanVector();
	double magnitude1;
	int product;
	double divide;
	magnitude1 = magnitude(v2);
	product = dot_product(v1,v2);
	divide = (double) product / magnitude1;
	printf("The projection of v1 on v2 is (%.10f...)\n",divide);
}

Vector scanVector(void) {
	Vector v1;
	scanf("%d %d %d",&(v1.x), &(v1.y), &(v1.z));
	return v1;
}