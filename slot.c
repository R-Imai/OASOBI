/*--------------------------------------------------------------------------------------------------------------
*	Name:		slot.c
*	Author:		R.Imai
*	Created:	2014 / ?? / ??
*	Last Date:	2014 / ?? / ??
*	Note:		スロットゲーム
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
		printf("\n所持金は￥%dです。\n", money);
		printf("いくら賭けますか？\n￥");
		scanf("%d", &bet);
		money = money - bet;
		srand((unsigned)time(NULL));
		a = rand() % 10;
		b = rand() % 10;
		c = rand() % 10;
		d = rand() % 10;
		printf("■■■■■■■■■■■■■■\n");
		printf("■■%2d■■%2d■■%2d■■%2d■■\n", a, b, c, d);
		printf("■■■■■■■■■■■■■■\n\n");
		if (a == b&&b == c&&c == d){
			printf("おめでとうございます!!￥%d獲得\n\n\n", bet*(a + 1) * 10);
			money = money + (bet*(a + 1) * 10);
		}
		else if (a == b&&b == c&&c == a){
			printf("惜しい!￥%d獲得\n\n\n", 3 * (a + 1)*bet);
			money = money + (3 * (a + 1)*bet);
		}
		else if (d == b&&b == c&&c == d){
			printf("惜しい!￥%d獲得\n\n\n", 3 * (b + 1)*bet);
			money = money + (3 * (b + 1)*bet);
		}
		else if (a == d&&d == c&&c == a){
			printf("惜しい!￥%d獲得\n\n\n", 3 * (a + 1)*bet);
			money = money + (3 * (a + 1)*bet);
		}
		else if (a == b&&b == d&&d == a){
			printf("惜しい!￥%d獲得\n\n\n", 3 * (a + 1)*bet);
			money = money + (3 * (a + 1)*bet);
		}
		else if (a == b || b == c || c == d ){
			printf("いい線行ってます。￥%d獲得\n\n\n", (int)(1.5 * bet));
			money = money + ((int)(1.5 * bet));
		}
		else{
			printf("ざーんねんw\n\n\n");
		}
	}
	printf("あなたの負けです。");
	if (money < 0){
		printf("借金は￥%dです。\n", money);
	}
}