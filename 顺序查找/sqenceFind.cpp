#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int seqenceFind(int[],int,int);
    void printArray(int[],int);

    int n,i,j,key,array[MAX];
    printf("\t\t\t\tSeqenceFind\nInput the size of the array:");
    scanf(" %d",&n);

    //获取用户输入，array[0]保留为存储key的元素，详见seqenceFind函数
    for(i=1; i<n+1; i++)
        scanf(" %d",&array[i]);
    printf("Input array finished!\n");

    printArray(array,n);

    //要求用户输入待查找key
    printf("Input the key you would like to find:");
    scanf(" %d",&key);
    j = seqenceFind(array,n,key);

    printf("\nThe position of the key is : %d",j);


    system("pause");
    return 0;

}

//顺序查找，找到返回位置（输入数组中的第几个），返回0表示未找到
int seqenceFind(int array[], int n,int key)
{
    int i = 0;
    array[0] = key;
    for(i=n; array[i] != key; i--)
        ;
    return i;           //i=0 代表未找到
}

//打印数组
void printArray(int array[] ,int n)
{
     int i = 1; //打印用户输入的array，这里因为arry[0]被用作存储key，因此打印从arry[1]开始
     while(i<n+1)
     {
         printf(" %d",array[i]);
         i++;
     }
}
