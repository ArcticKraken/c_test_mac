//
//  time.c
//  220121test
//
//  Created by huikwon on 2022/02/02.
//

#include <time.h>
#include <stdio.h>

int main_time(void)
{
    long start, end;
    
    //for 루프 시작 시간
    start = clock() / CLOCKS_PER_SEC;
    
    //for루프 돌아보기
    int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++) {
            printf("0");
        }
        printf("\n");
        sum++;
    }
    
    //for 루프 끝난 시간
    end = clock() / CLOCKS_PER_SEC;
    printf("프로그램 수행 시간 :%ld\n", (end-start));
    return 0;
}
