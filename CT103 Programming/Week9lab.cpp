#include "stdafx.h"
#include "stdio.h"


double getAreaSquare(double VAR1);double getAreaCircle(double VAR1);double getAreaTriangle(double VAR1, double VAR2);double getAreaRectangle(double VAR1, double VAR2);double getAreaCube(double VAR1);double getAreaSphere(double VAR1);double getAreaCone(double VAR1, double VAR2);double getAreaCylinder(double VAR1, double VAR2);
int main()
{
	double VAR1;
	double VAR2;
	double area;

	area = getAreaSquare(2.5);
	printf("area of a square of lentgh 2.5 = %.2f\n", area);

	area = getAreaCircle(6);
	printf("area of a circle of raduis 6 = %.2f\n", area);

	area = getAreaTriangle(1.4,1.6);
	printf("area of a triangle of base 1.4 and hieght 1.6  = %.2f\n", area);

	area = getAreaRectangle(2, 3);
	printf("area of a rectange of base 2 and hieght 3  = %.2f\n", area);

	area = getAreaCube(2);
	printf("surface area of a cube of length 2  = %.2f\n", area);

	area = getAreaSphere(5);
	printf("surface area of a sphere of radius 5  = %.2f\n", area);

	area = getAreaCone(6,9);
	printf("surface area of a cone of radius 6 height 9  = %.2f\n", area);

	area = getAreaCylinder(8, 3);
	printf("surface area of a cylinder of radius 8 height 3  = %.2f\n", area);

}

double getAreaSquare(double VAR1){
	double area;
	area = VAR1 * VAR1;
	return area;}double getAreaCircle(double VAR1){
	double area;
	area = VAR1 * VAR1 * 3.14;
	return area;}double getAreaTriangle(double VAR1, double VAR2){
	double area;
	area = (VAR1 * VAR2) / 2;
	return area;}double getAreaRectangle(double VAR1, double VAR2){
	double area;
	area = VAR1 * VAR2;
	return area;}double getAreaCube(double VAR1){	double area;	area = VAR1 * VAR1 * VAR1;
	return area;
}
double getAreaSphere(double VAR1){
	double area;
	area = (VAR1 * VAR1 * VAR1 * 3.14 * 4) / 3;
	return area;
}
double getAreaCone(double VAR1, double VAR2){
	double area;
	area = (VAR1 * VAR1 * VAR2 * 3.14) / 3;
	return area;}double getAreaCylinder(double VAR1, double VAR2){
	double area;
	area = VAR1 * VAR1 * VAR2 * 3.14;
	return area;
}