#include <stdio.h>
#include <stdlib.h>

//编译预处理，定义最大值MAX为100
#define MAX 100

int main()
{
    //声明函数，因为在main之后定义
    void bubbleSort(int[], int);
    void printArray(int[] ,int);
    printf("\t\t\t\tBubblesort\n");

    //定义
    int i,n,array[MAX];

    //提示用户输入待比较的元素的个数
    printf("Input the size of the number:\n");
    scanf("%d",&n);

    //提示用户逐个输入待比较的元素（这里是整数）
    printf("Input the numbers:\n");
    for(i = 0; i<n; i++)
        scanf(" %d",&array[i]);
    printf("Input finished\n");

    //调用冒泡排序算法对数组进行排序
    bubbleSort(array, n);
    printf("Sort finished\n");

    //打印排序后的数组
    printArray(array, n);

    //防止程序直接return 0退出，这样什么都看不到，黑窗口一闪而过……
    system("pause");
    return 0;

}

void bubbleSort(int array[] ,int n)
{
     void printArray(int[] ,int);

     int i,j;

     //外层循环每进行一次，前i个元素就排列好了，从前往后
     for(i=1; i<n; i++)
     {
         //内层循环，从后往前，将最小的往前挪，每次循环结束，第i个元素就排好了
         for(j=n-1; j>=i;j--)
         {
             if(array[j-1]>array[j])
             {
                 //这里用到了临时变量，为了交换值而引入；
                 // - temp的声明可以放到外面，节省内存空间
                 // - 也可以不用temp，进行数据交换，详见snap/swapAB.png
                 int temp;
                 temp = array[j-1];
                 array[j-1] = array[j];
                 array[j] = temp;
             }
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
