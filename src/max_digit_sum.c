/* max_digit_sum.c */
/* Author: Видук Павел, group 10 */

#include "max_digit_sum.h"

int digit_sum(int n)
{
    int sum = 0;
    if (n < 0) n = -n;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

size_t find_numbers_with_max_sum(const int *arr, size_t size, int *result, size_t result_size)
{
    if (arr == NULL || result == NULL || size == 0) return 0;
    int max_sum = -1;
    for (size_t i = 0; i < size; i++)
    {
        int cur_sum = digit_sum(arr[i]);
        if (cur_sum > max_sum) max_sum = cur_sum;
    }
    size_t count = 0;
    for (size_t i = 0; i < size && count < result_size; i++)
    {
        if (digit_sum(arr[i]) == max_sum)
        {
            result[count] = arr[i];
            count++;
        }
    }
    return count;
}
