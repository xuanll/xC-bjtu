#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int binaryFind(int[],int,int);
    void printArray(int[],int);

    int n,i,j,key,array[MAX];
    printf("\t\t\t\tBinaryFind8\nInput the size of the array:");
    scanf(" %d",&n);

    printf("Input a sort of increase numbers:\n");
    for(i=0; i<n; i++)
        scanf(" %d",&array[i]);
    printf("Input finished!\n");

    printf("Input the key you would like to find:");
    scanf(" %d",&key);
    j = binaryFind(array,n,key);

    printf("\nThe position of the key is : %d",j+1);


    system("pause");
    return 0;

}


int binaryFind(int array[],int n,int key)
{
    //low低值，high高值，mid中值
    int low = 0;
    int high = n-1;
    int mid;

    //查找key
    while(low <= high)
    {
        //更新中间位置index
        mid = (low + high)/2;

        //找到key，返回位置index
        if(array[mid] == key)
            return mid;
        //中值大于key,key在前半部分，更新high
        else if(array[mid] > key)
            high = mid-1;
        //中值小于key,key在后半部分，更新low
        else low = mid+1;
    }

    //没有找到，返回-1
    return -1;
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
