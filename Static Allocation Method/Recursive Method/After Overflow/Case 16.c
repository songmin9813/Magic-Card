#include <stdio.h>
#include <time.h>
#define CARD 19
//카드의 개수를 입력하는 상수입니다. 숫자를 변경하여 개수를 바꿀 수 있습니다.
#define QUAN 524288

//카드에 적힐 숫자의 개수입니다. 숫자를 변경하여 개수를 바꿀 수 있습니다.
/*
20164043 한성민
본 프로그램은 이산수학 시간에 주어진 '매직 카드'를 구현하는 프로그램입니다.
위의 상수에 원하는 적절한 값을 집어넣으면 상황에 맞추어 카드를 출력합니다.
*/
void recur(int arr[][QUAN],int i, int z, int power)
{
	if (z == (1 << CARD)) return;//재귀 제어식입니다.
	if ((z + 1) / power % 2 == 1 && (z + 1) % power != 0 || (z + 1) % (2 * power) == 0)
		//나머지를 이용한 식들로 해당 수가 그 카드에 있는지 판별합니다.
		arr[i][z] = 1;
	//있을 경우 해당 위치에 1을 대입시킵니다.
	else
		arr[i][z] = 0;
	//아닐 경우 해당 위치에 0을 대입시킵니다.
	recur(arr, i, z + 1, power);//재귀 함수 호출
}
int main()
{
	time_t startTime = 0, endTime = 0;
	startTime = clock();
	int card[CARD][QUAN];
	int i, z, power, sum;
	//i와 z변수는 루프문을 제어할 변수입니다.
	//power는 상황에 맞춘 제곱수가 저장될 변수입니다.
	//sum은 마지막으로 출력할 수를 저장합니다.
	char category;
	//Y와 N을 사용자에게 입력받을 변수입니다.
	//카드의 숫자들을 저장할 2차원 배열을 선언합니다.
	sum = 0;
	//sum에서는 덧셈이 이루어지기 때문에 0으로 초기화합니다.
	for (i = 0; i < CARD; i++) {//행에 먼저 루프를 걸어줍니다.
		z = 0;
		power = 1 << i;
		recur(card, i, z, power);//재귀 함수를 호출합니다.
	}
	printf("지금부터 마술카드 놀이를 시작하도록 하겠습니다.\n");
	printf("0부터 %d까지의 정수 중에서 원하는 숫자 한가지를 기억해주세요.\n\n", (1 << CARD) - 1);
	//사용자에게 생각할 수 있는 숫자의 범위를 출력문으로써 언급해야 합니다.
	for (i = 0; i < CARD; i++)//카드의 숫자만큼 루프가 진행됩니다.
	{
		printf("\n\n%d번째 카드!\n", i + 1);
		for (z = 0; z < (1 << CARD); z++)//한 행을 검사합니다.
		{
			if (card[i][z] == 1)
				//1이 저장되어있는 경우에만 화면에 출력합니다.
				printf("%d ", z);
		}
		while (1)
			//사용자에게 제대로 된 입력을 받을 때까지 무한 루프가 진행됩니다.
		{
			printf("\n여기에 생각하는 숫자가 있나요? (Y/N)\n");
			endTime = clock();
			printf("걸린 시간은 %f초입니다.",(float)(endTime-startTime)/(CLOCKS_PER_SEC));
			category = getche();
			//사용자에게 Y나 N을 입력받게 합니다.
			if (category == 'Y' || category == 'y')//있다고 할 경우에
			{
				sum = sum + (1 << i);
				//1부터 시작해서 2의 i 제곱만큼의 값을 더해줍니다.
				break;//제대로된 입력을 받았으므로 정상적인 종료
			}
			else if (category == 'N' || category == 'n')
				//없다고 할 경우에
				break;//제대로된 입력을 받았으므로 정상적인 종료
			else
				printf("\n잘못된 입력입니다. 다시 입력해주세요.\n");
		}
	}
	printf("\n\n흐음...당신이 생각하는 숫자는 %d인 것 같습니다.\n", sum);
	//마지막으로 sum에 누적된 숫자를 출력하고 프로그램이 종료됩니다.
}