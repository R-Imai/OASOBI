/*--------------------------------------------------------------------------------------------------------------
*	Name:		slot.c
*	Author:		R.Imai
*	Created:	2014 / ?? / ??
*	Last Date:	2014 / ?? / ??
*	Note:		�X���b�g�Q�[��
*
*--------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
	int a, b, c, d, money, bet;

	money = 10000;

	while (money>0){
		printf("\n�������́�%d�ł��B\n", money);
		printf("������q���܂����H\n��");
		scanf("%d", &bet);
		money = money - bet;
		srand((unsigned)time(NULL));
		a = rand() % 10;
		b = rand() % 10;
		c = rand() % 10;
		d = rand() % 10;
		printf("����������������������������\n");
		printf("����%2d����%2d����%2d����%2d����\n", a, b, c, d);
		printf("����������������������������\n\n");
		if (a == b&&b == c&&c == d){
			printf("���߂łƂ��������܂�!!��%d�l��\n\n\n", bet*(a + 1) * 10);
			money = money + (bet*(a + 1) * 10);
		}
		else if (a == b&&b == c&&c == a){
			printf("�ɂ���!��%d�l��\n\n\n", 3 * (a + 1)*bet);
			money = money + (3 * (a + 1)*bet);
		}
		else if (d == b&&b == c&&c == d){
			printf("�ɂ���!��%d�l��\n\n\n", 3 * (b + 1)*bet);
			money = money + (3 * (b + 1)*bet);
		}
		else if (a == d&&d == c&&c == a){
			printf("�ɂ���!��%d�l��\n\n\n", 3 * (a + 1)*bet);
			money = money + (3 * (a + 1)*bet);
		}
		else if (a == b&&b == d&&d == a){
			printf("�ɂ���!��%d�l��\n\n\n", 3 * (a + 1)*bet);
			money = money + (3 * (a + 1)*bet);
		}
		else if (a == b || b == c || c == d ){
			printf("�������s���Ă܂��B��%d�l��\n\n\n", (int)(1.5 * bet));
			money = money + ((int)(1.5 * bet));
		}
		else{
			printf("���[��˂�w\n\n\n");
		}
	}
	printf("���Ȃ��̕����ł��B");
	if (money < 0){
		printf("�؋��́�%d�ł��B\n", money);
	}
}