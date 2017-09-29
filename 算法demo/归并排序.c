#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <malloc.h>

#define NUM 10

int heads[NUM];

 

/*

 * 扫描数组，将已排好序的子数组段的段首加入数组heads中。

 * 函数返回段首的总数。

 */

int check(int num[], int n)
{
    int num_of_head = 1;
    int i;
    heads[0] = 0;
    for (i = 1; i < n; i++)
    {
        if (num[i] < num[i - 1])
        {
            heads[num_of_head++] = i;
        }
    }
    return num_of_head;
}



 

/*

 * 将2路有序序列归并为1路。

 */

void Merge(int sourceArr[], int head, int mid, int tail)

{

    int i, j, k;
    int *targetArr;
    targetArr = (int *)malloc(sizeof(int)*(tail - head + 1));
    for (i = head, j = mid + 1, k = 0; i <= mid&&j <= tail; k++)
    {
        if (sourceArr[i] > sourceArr[j])
        {
            targetArr[k] = sourceArr[j++];
        }
        else
        {
            targetArr[k] = sourceArr[i++];
        }
    }
    for (; i <= mid; k++, i++)
    {
        targetArr[k] = sourceArr[i];
    }
    for (; j <= tail; k++, j++)
    {
        targetArr[k] = sourceArr[j];
    }
    for (i = head,k = 0; i <= tail; i++, k++)
    {
        sourceArr[i] = targetArr[k];
    }
}

void MergeSort(int num[], int n)
{
    int num_of_head;
    int i;
    while (1)
    {
        num_of_head = check(num, n);
        if (num_of_head == 1)
        {
            break;
        }
        else
        {
            for (i = 0; i < num_of_head - 1; i += 2)
            {
                if (i + 2 <= num_of_head - 1)
                {
                    Merge(num, heads[i], heads[i + 1] - 1, heads[i + 2] - 1);
                }
                else
                {
                    Merge(num, heads[i], heads[i + 1] - 1, n - 1);
                }   
            }
        }
    }
}

void main()
{
    int num[NUM];
    int i;
    for (i = 0; i < NUM; i++)
        scanf("%d", num + i);
    MergeSort(num, NUM);
    for (i = 0; i < NUM; i++)
        printf("%-3d ", num[i]);
}
