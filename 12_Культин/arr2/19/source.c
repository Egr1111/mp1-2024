#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//#define RAND_MIN = pow(10, n - 1)
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int n, i;
	scanf_s("%d", &n);
	int** res = (int**)malloc(sizeof(int*) * n); // = { {1, 2, 3, 4},  {4,3, 4, 21} };
	
	for (i = 0; i < n; i++)
		res[i] = (int*)malloc(sizeof(int) * 3);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			int f;
			scanf_s("%d", &f);

			res[i][j] = f;
		}
	}

	hw19(res, n, n);
	
	return 0;

}



int hw19(int **arr, int k1, int k2){
	int n1, n2, n3, n4, n5;
	n1 = n2 = n3 = n4 = n5 = 0;

	for (int i = 0; i < k1; i++)
	{
		for (int j = 0; j < k2; j++) {
			switch (arr[i][j])
			{
			case 2:
				n2++;
				break;
			case 3:
				n3++;
				break;

			case 4:
				n4++;
				break;

			case 5:
				n5++;
				break;

			default:
				n1++;
				break;
			}
		}
	}
	printf("%d %d %d %d %d ", n1, n2, n3, n4, n5);
	return 0;
}







