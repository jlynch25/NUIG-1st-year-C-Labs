#include "stdafx.h"
#include "stdio.h"


void main()
{

	int shape = 0;
	int dimension = 0;
	float area = 0.0;
	float VAR1 = 0.0;
	float VAR2 = 0.0;
	float VAR3 = 0.0;



	printf("Wellcome to My Area Calculator \n");

	printf("choose 2D shapes or 3D shapes\n");
	printf("(1) 2D shapes\n");
	printf("(2) 3D shapes\n");
	scanf_s("%d", &dimension);

	switch (dimension)
	{
	case 1:
		printf("choose a shape from the following \n");

		printf("(1) Square \n");
		printf("(2) Circle \n");
		printf("(3) Triangle \n");
		printf("(4) Rectangle \n");


		scanf_s("%d", &shape);
		switch (shape)
		{
		case 1:
			printf("you choose sqaure \n");
			printf("enter length \n");
			scanf_s("%f", &VAR1);
			area = VAR1 * VAR1;
			printf("area = %.2f \n", area);
			break;

		case 2:
			printf("you choose circle \n");
			printf("enter Radius \n");
			scanf_s("%f", &VAR1);
			area = VAR1 * VAR1 * 3.14;
			printf("area = %.2f \n", area);
			break;

		case 3:
			printf("you choose triangle \n");
			printf("enter base length \n");
			scanf_s("%f", &VAR1);
			printf("enter height \n");
			scanf_s("%f", &VAR2);
			area = (VAR1 * VAR2) / 2;
			printf("area = %.2f \n", area);
			break;

		case 4:
			printf("you choose rectangle \n");
			printf("enter base length \n");
			scanf_s("%f", &VAR1);
			printf("enter height \n");
			scanf_s("%f", &VAR2);
			area = VAR1 * VAR2;
			printf("area = %.2f \n", area);
			break;

		default:
			printf("incorrenct choose\n");
		}

	case 2:

		printf("choose a shape from the following \n");

		printf("(1) Cube \n");
		printf("(2) Sphere \n");
		printf("(3) Cone \n");
		printf("(4) Cylinder \n");


		scanf_s("%d", &shape);
		switch (shape)
		{
		case 1:
			printf("you choose cube \n");
			printf("enter length \n");
			scanf_s("%f", &VAR1);
			area = VAR1 * VAR1 * VAR1;
			printf("volume = %.2f \n", area);
			break;

		case 2:
			printf("you choose sphere \n");
			printf("enter Radius \n");
			scanf_s("%f", &VAR1);
			area = (VAR1 * VAR1 * VAR1 * 3.14 * 4) / 3;
			printf("volume = %.2f \n", area);
			break;

		case 3:
			printf("you choose cone \n");
			printf("enter Radius \n");
			scanf_s("%f", &VAR1);
			printf("enter height \n");
			scanf_s("%f", &VAR2);
			area = (VAR1 * VAR1 * VAR2 * 3.14) / 3;
			printf("volume = %.2f \n", area);
			break;

		case 4:
			printf("you choose cylinder \n");
			printf("enter Radius \n");
			scanf_s("%f", &VAR1);
			printf("enter height \n");
			scanf_s("%f", &VAR2);
			area = VAR1 * VAR1 * VAR2 * 3.14;
			printf("volume = %.2f \n", area);
			break;

		default:
			printf("incorrenct choose\n");
		}
	default:
		printf("incorrenct choose\n");
	}
}



