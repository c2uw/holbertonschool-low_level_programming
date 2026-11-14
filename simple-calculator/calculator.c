#include <stdio.h>

/**
 * main - entry point of the simple calculator
 *
 * Return: Always 0
 */
int main(void)
{
	int choice;
	int a;
	int b;
	int c;

	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");

	while (1)
	{
		printf("Choice: ");

		if (scanf("%d", &choice) != 1)
		{
			c = getchar();
			if (c == EOF)
				break;
			while (c != '\n' && c != EOF)
				c = getchar();
			printf("Invalid choice\n");
			continue;
		}

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}

		if (choice == 1 || choice == 2)
		{
			printf("A: ");
			if (scanf("%d", &a) != 1)
				break;
			printf("B: ");
			if (scanf("%d", &b) != 1)
				break;
			if (choice == 1)
				printf("Result: %d\n", a + b);
			else
				printf("Result: %d\n", a - b);
		}
		else if (choice < 1 || choice > 4)
			printf("Invalid choice\n");
	}

	return (0);
}
