/*--------------------------------------------------------------------------------------------------------------
*	Name:		slot.c
*	Author:		R.Imai
*	Created:	2014 / ?? / ??
*	Last Date:	2016 / 05 / 12
*	Note:		ÉXÉçÉbÉgÉQÅ[ÉÄ
*
*--------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void main(void){
	int a, b, c, d, money, bet;

	money = 10000;

	while (money>0){
		printf("\nèäéùã‡ÇÕÅè%dÇ≈Ç∑ÅB\n", money);
		printf("Ç¢Ç≠ÇÁìqÇØÇ‹Ç∑Ç©ÅH\nÅè");
		scanf("%d", &bet);
		money = money - bet;
		if (bet >= 0){
			srand((unsigned)time(NULL));
			a = rand() % 10;
			b = rand() % 10;
			c = rand() % 10;
			d = rand() % 10;
		}
		else{
			a = 9;
			b = 9;
			c = 9;
			d = 9;
		}
		printf("Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°\n");
		printf("Å°Å°%2dÅ°Å°%2dÅ°Å°%2dÅ°Å°%2dÅ°Å°\n", a, b, c, d);
		printf("Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°Å°\n\n");
		if (a == b&&b == c&&c == d){
			printf("Ç®ÇﬂÇ≈Ç∆Ç§Ç≤Ç¥Ç¢Ç‹Ç∑!!Åè%dälìæ\n\n\n", bet*(a + 1) * 10);
			money = money + (bet*(a + 1) * 10);
		}
		else if (a == b&&b == c&&c == a){
			printf("ê…ÇµÇ¢!Åè%dälìæ\n\n\n", 3 * (a + 1)*bet);
			money = money + (3 * (a + 1)*bet);
		}
		else if (d == b&&b == c&&c == d){
			printf("ê…ÇµÇ¢!Åè%dälìæ\n\n\n", 3 * (b + 1)*bet);
			money = money + (3 * (b + 1)*bet);
		}
		else if (a == d&&d == c&&c == a){
			printf("ê…ÇµÇ¢!Åè%dälìæ\n\n\n", 3 * (a + 1)*bet);
			money = money + (3 * (a + 1)*bet);
		}
		else if (a == b&&b == d&&d == a){
			printf("ê…ÇµÇ¢!Åè%dälìæ\n\n\n", 3 * (a + 1)*bet);
			money = money + (3 * (a + 1)*bet);
		}
		else if (a == b || b == c || c == d ){
			printf("Ç¢Ç¢ê¸çsÇ¡ÇƒÇ‹Ç∑ÅBÅè%dälìæ\n\n\n", (int)(1.5 * bet));
			money = money + ((int)(1.5 * bet));
		}
		else{
			printf("Ç¥Å[ÇÒÇÀÇÒw\n\n\n");
		}
	}
	printf("Ç†Ç»ÇΩÇÃïâÇØÇ≈Ç∑ÅB");
	if (money < 0){
		printf("éÿã‡ÇÕÅè%dÇ≈Ç∑ÅB\n", money);
	}
}
