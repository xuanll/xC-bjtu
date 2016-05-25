#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    void binaryInsertSort(int[],int);
    void printArray(int[],int);

    int n,i,array[MAX];
    printf("\t\t\t\tBinaryInsetSort\nInput the size of the array:");
    scanf(" %d",&n);

    for(i=1; i<n+1; i++)
        scanf(" %d",&array[i]);
    printf("Input finished!\n");

    binaryInsertSort(array,n);
    printf("Sort finished!\n");

    printArray(array,n);

    system("pause");
    return 0;
}


//折半插入排序
void binaryInsertSort(int array[],int n)
{
     void printArray(int[] ,int);
     int i,j,m,low,high;

     for(i=2;i<n+1;i++)
     {
         array[0] = array[i];         //将array[i]暂存在array[0]里
         low = 1; high = i-1;

         while(low <= high)           //折半
         {
             m = (low+high)/2;
             if(array[0]<array[m])
                 high = m-1;
             else low = m+1;
         }

         for(j=i-1;j>=high+1;j--)     //已排序的元素后移，为待排序元素挪出空间
             array[j+1] = array[j];

         array[high+1] = array[0];    //插入元素

         printArray(array,n);
         printf("\n");
     }

}


//打印数组
void printArray(int array[] ,int n)
{
     int i = 1;     //array[0]作为暂存空间，因此打印index从1开始
     while(i<n+1)
     {
         printf(" %d",array[i]);
         i++;
     }
}
