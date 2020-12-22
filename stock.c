#include<stdint.h>
#include "header.h"
#include <assert.h>

Share    share_buysell(int32_t price,int32_t n)
{
    n = sizeof(price)/sizeof(price[]);
    if (n == 1)
        return;

    int count = 0;
    Interval sol[n / 2 + 1];

    int i = 0;
    while (i < n - 1) {
        while ((i < n - 1) && (price[i + 1] <= price[i]))
            i++;
        if (i == n - 1)
            break;

        sol[count].buy = i++;

        while ((i < n) && (price[i] >= price[i - 1]))
            i++;

        sol[count].sell = i - 1;

        count++;
    }

    return;
}
