#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int lines = 10, columns = 10;

	int i = 0, j = 0, z = 0;

	int array[lines][columns];

	for (i = 0; i < lines; i++)
	{
		for (j = 0; j < columns; j++)
		{
			array[i][j] = rand() % 100;
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}

	printf("--------------\n");

	for (z = 0; z < lines; z++)
	{
		for (i = 0; i < lines - 1; i++)
		{
			for (j = 0; j < columns; j++)
			{
				if (array[i][j] > array[i + 1][j])
				{
					int temp;
					temp = array[i][j];
					array[i][j] = array[i + 1][j];
					array[i + 1][j] = temp;
				}
			}
		}
	}

	for (i = 0; i < lines; i++)
	{
		for (j = 0; j < columns; j++)
		{
			printf("%4d ", array[i][j]);
		}
		printf("\n");
	}
}
