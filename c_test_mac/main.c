//
//  main.c
//  c_test_mac
//
//  Created by kwon on 2022/02/15.
//

#include <stdio.h>

int main_temp(void)
{
    printf("Hello, World!\n");
    
    // 구구단
    
    //    for(int i = 2 ; i <= 9 ; i++)
    //    {
    //        printf("%d단\n", i);
    //        for(int j = 1 ; j <= 9 ; j++)
    //        {
    //            printf("   %d x %d = %d\n", i, j, i*j);
    //        }
    //    }
    
    // 피라미드 쌓기
    int floor;
    printf("몇층으로 쌓겠습니까?");
    scanf("%d", &floor);
    for (int i = 0; i < floor; i++)
    {
        for (int j = i; j < floor-1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i*2+1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

