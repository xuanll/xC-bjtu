#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    void selectSort(int[], int);
    void printArray(int[] ,int);

    int n,i,array[MAX];
    printf("\t\t\t\tSelectSort\nInput the size of the array:");
    scanf(" %d",&n);

    for(i=0; i<n; i++)
        scanf(" %d",&array[i]);
    printf("Input finished!\n");

    selectSort(array,n);
    printf("Sort finished!\n");

    printArray(array,n);

    system("pause");
    return 0;
}

//选择排序
void selectSort(int array[], int n)
{
     void printArray(int[] ,int);

     int i;
     int minN;

     //每次循环，index为i的元素就是最小的
     for(i=0; i<n; i++)
     {
         //从j开始和最小值比较
         int j = i+1;

         //默认未排序部分的最小值是index为i的元素，min表示最小值的index
         int min = i;
         minN = array[i];

         //while循环比较未排序部分与最小值minN的大小
         while(j<n)
         {
             //这里不用等，是排序稳定的
             if(minN>array[j])
             {
                 min = j;
                 minN = array[j];
             }
             j++;
         }

         //未排序部分最小值不是index为i的元素，需要将最小值与index为i的元素互换
         if(min != i)
         {
             int temp;
             temp = array[i];
             array[i] = array[min];
             array[min] = temp;
         }
         printArray(array,n);
         printf("\n");
     }
}

//打印数组
void printArray(int array[] ,int n)
{
     int i = 0;
     while(i<n)
     {
         printf(" %d",array[i]);
         i++;
     }
}
