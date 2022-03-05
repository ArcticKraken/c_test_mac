//
//  fish_game.c
//  220121test
//
//  Created by huikwon on 2022/02/02.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int level;
int arrayFish[6];
int * cursor;

void initData(void);
void printFishes(void);
void decreaseWater(long elapsedTime);
int checkFishAlive(void);

int main(void)
{
    long startTime; // 게임시작시간
    long currentTime;
    long totalElapsedTime; // 총 경과 시간
    long prevElapedTime = 0; // 직전 경과 시간(최근에 물을 준 시간 간격)
    
    int num; // 몇 번 어항에 물을 준 것인지, 사용자 입력
    initData();
    
    cursor = arrayFish; // cursor[0]...[5]
    
    startTime = clock() / CLOCKS_PER_SEC; // 현재시간(millisecond 단위)
    
    while(1)
    {
        printFishes();
        printf("몇 번 어항에 물을 주시겠어요? ");
        scanf("%d", &num);
        printf("\n");
        
        if (num < 1 || num > 6) // 입력값 체크
        {
            printf("\n입력값이 잘못되었습니다\n");
            continue;
        }
        
        // 총 경과시간
        currentTime = clock() / CLOCKS_PER_SEC;
        totalElapsedTime = currentTime - startTime;
        printf("총 경과시간 : %ld 초\n", totalElapsedTime);
        
        // 마지막으로 물 준 시간 이후로 흐른 시간
        prevElapedTime = totalElapsedTime - prevElapedTime;
        printf("최근 경과시간 : %ld 초\n", prevElapedTime);
        
        // 어항의 물을 감소
        decreaseWater(prevElapedTime);
        
        // 사용자가 입력한 어항에 물을 준다
        // 1. 어항의 물이 0이면? 물을 주지 않는다.
        if (cursor[num - 1] <= 0)
        {
            printf("%d 번 물고기는 이미 죽었습니다. 물을 주지 않습니다\n", num);
        }
        
        // 어항의 물이 0이 아닌 경우? 물을 주고 100이 넘지 않는지 체크
        else if (cursor[num -1] +1 <= 100)
        {
            printf("%d 번 어항에 물을 줍니다\n\n", num);
            cursor[num - 1] += 1;
        }
        
        // 레벨업을 할 건지 확인(20초마다 레벌업 수행)
        if (totalElapsedTime / 20 > level -1)
        {
            level++;
            printf("*** 축 레벨업 ! 기존 %d 레벨에서 %d 레벨로 업그레이드 ***\n\n", level -1, level);
            
            // 최종레벨 5일때
            if (level == 5)
            {
                printf("\n\n축하합니다. 최고레벨을 달성하였습니다. 게임을 종료합니다\n");
                exit(0);
            }
        }
        
        //물고기가 죽었는지 확인
        if (checkFishAlive() == 0)
        {
            printf("모든 물고기가... ㅠㅠ ");
            exit(0);
        }
        else
        {
            printf("물고기가 아직 살아 있어요!\n");
        }
        prevElapedTime = totalElapsedTime;
    }
    return 0;
}

void initData()
{
    level = 1; // 1~5
    for (int i = 0; i < 6; i++)
    {
        arrayFish[i] = 100; // 어항의 물 높이(0~100)
    }
}

void printFishes()
{
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 6; i++)
    {
        printf(" %4d ", arrayFish[i]);
    }
    printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
    for (int i = 0; i <6; i++)
    {
        arrayFish[i] -= (level * 3 * (int)elapsedTime);
        if (arrayFish[i] < 0)
        {
            arrayFish[i] = 0;
        }
    }
}

int checkFishAlive()
{
    for (int i = 0; i < 6; i++)
    {
        if (arrayFish[i] > 0)
        {
            return 1;
        }
    }
    return 0;
}
