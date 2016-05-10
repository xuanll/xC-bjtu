/*
八皇后问题是一个以国际象棋为背景的问题：
如何能够在8×8的国际象棋棋盘上放置八个皇后，使得任何一个皇后都无法直接吃掉其他的皇后？
为了达到此目的，任两个皇后都不能处于同一条横行、纵行或斜线上。
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//suc满足条件的种数，初始为0，一旦满足，suc自增，调用打印函数打印
int suc = 0;

//八皇后问题，所以创建8个容量的数组。
//该数组在以下任意函数都可访问，
//该数组对应的元素值，如s[1]==2，代表第二位(列)的皇后放在第三行,
//每一列只有1个皇后，因此s[8]能代表所有的皇后位置.
//(x,s[x])代表皇后坐标，判断是否在棋盘一斜线上，通过棋盘（双色）可以看出，这些斜线斜率都为1或-1
int s[8];

int main()
{
    //后面用到该方法main之前没有写，这里需要提前声明
    void queen(int);

    queen(0);

    //等待用户输入任意键后继续
    system("pause");

    return 0;
}

void queen(int n)
{
   void printThis();
   bool isCan(int);

   int i;

   //因为是回朔法，所以用到递归，这里是递归的出口
   //n = 7时为最后一列的所有情况，此时queen(n+1)的参数为8
   if(n==8)
   {
       suc++;
       printThis();
       return;
   }

    //循环对一列中的所有行进行考虑
    for(i = 0; i < 8; i++)
    {
        //第n列放在第i行，n表示列.
        s[n] = i;

        //如果这种情况成立，则递归下去
        if(isCan(n))
        {
          //递归，对第n+1列进行考虑（一般最外面是从0列开始）
          queen(n+1);
        }

    }
}

//是否满足不被吃掉（八皇后）的条件
bool isCan(int n)
{
    int i;

    //第n列的皇后和所有其他皇后比较，i从0到n-1
    for(i = 0; i < n; i++)
    {

        //在同一行,不满足条件
        if(s[i]==s[n])
        {
           return false;
        }

        //在同一斜线上，不满足条件
        //使用到了abs，因此需要引入math.h
        if( abs(s[n]-s[i])==n-i )
        {
           return false;
        }

     }

     return true;
}

 //打印函数
void printThis()
{
     // "%d", var 格式化输出，这里是int类型，其余请类型请查阅资料
     printf("第%d种放法皇后分别放在以下列的以下行：\n", suc);

     for(int i=0;i<8;i++)
     {
         printf("第%d列的第%d行\n",i,s[i]);
     }

     system("pause");
}
