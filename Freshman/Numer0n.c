/*--------------------------------------------------------------------------------------------------------------
*	Name:		Numer0n.c
*	Author:		R.Imai
*	Created:	2014 / ?? / ??
*	Last Date:	2014 / ?? / ??
*	Note:		�����ăQ�[��
*
*--------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void){
	int I, X, V, M, one, ten, hand, thou, n, eat, bite;
	printf("\n�l���̐�����7��ȓ��œ��ĂĂ��������B\n\n\n\n\n");

	srand((unsigned)time(NULL));//�����̌���

	M = rand() % 10;
	V = rand() % 10;
	while (V == M){
		V = rand() % 10;
	}
	X = rand() % 10;
	while (X == M || X == V){
		X = rand() % 10;
	}
	I = rand() % 10;
	while (I == M || I == V || I == X){
		I = rand() % 10;
	}
	n = 1;
	eat = 0;
	bite = 0;
	//printf("%d%d%d%d\n",M,V,X,I);//����
	while (n <= 7){
		printf("%d��ځB�������Ǝv���܂���\n", n);
		scanf("%1d %1d %1d %1d", &thou, &hand, &ten, &one);

		if (thou == M){
			eat = eat + 1;
		}
		else if (thou == X || thou == I || thou == V){
			bite++;
		}

		if (hand == V){
			eat = eat + 1;
		}
		else if (hand == X || hand == I || hand == M){
			bite++;
		}

		if (ten == X){
			eat = eat + 1;
		}
		else if (ten == M || ten == I || ten == V){
			bite++;
		}

		if (one == I){
			eat = eat + 1;
		}
		else if (one == X || one == M || one == V){
			bite++;
		}

		if (eat != 4 && n != 7){
			printf("%deat%dbite�ł��B\n\n", eat, bite);
			eat = 0;
			bite = 0;
		}
		else if (eat == 4){
			break;
		}
		n = n + 1;
	}
	if (eat == 4){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n���߂łƂ��������܂�!!\n������%d%d%d%d�ł���\n\n\n\n\n\n\n\n\n\n\n", M, V, X, I);
	}
	else{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�c�O!!\n������%d%d%d%d�ł���\n\n\n\n\n\n\n\n\n\n\n", M, V, X, I);
	}
}