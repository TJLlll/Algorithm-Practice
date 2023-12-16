#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WEEK    7

int maxProfit(int prices[], int Days) 
{
    
    if (Days < 2) 
    {
        return 0;
    }
    
    int minPrice = prices[0];   /* 历史最低售价 */
    int maxProfit = 0;          /* 历史最高利润 */
    int minPriceDay = 1;        /* 历史最低售价对应的那天 */
    int bestBuyDay = 2;         /* 最佳买入的那天 */
    int betSellDay = 0;         /* 最佳卖出的那天 */

    for (int i = 1; i < Days; i++) 
    {
        if (prices[i] < minPrice) 
        {
            minPrice = prices[i];
            minPriceDay = i + 1;
        }
        else 
        {
            int currProfit = prices[i] - minPrice;/* 当前可获取到的利润 */
            while(currProfit > maxProfit)/* 与历史最佳利润进行比较，当currProfit大，就取这天为最佳卖出 */
            {
                maxProfit = currProfit;     /* 更新最大利润 */
                bestBuyDay = minPriceDay;   /* 把新出现的最低价格 */
                betSellDay = i;
            }
            //maxProfit = (currProfit > maxProfit) ? currProfit : maxProfit;
        }
    }
    printf("\n最佳买入天为第%d天 ，最佳卖出天为第%d天\n", bestBuyDay, betSellDay + 1);
    return maxProfit;
}

int main() 
{
    srand(time(NULL));
    
    /* 生成7个随机数 */
    int prices[WEEK];
    printf("七天的股票价格分别为：\n");
    for(int idx = 0; idx < WEEK; idx++)
    {
        prices[idx] = rand() % 20 + 1;
        printf("%d   ",prices[idx]);
    }

    /* 调用函数 */
    int result = maxProfit(prices, WEEK);
    printf("\n最大利润为: %d\n", result);
    
    return 0;
}