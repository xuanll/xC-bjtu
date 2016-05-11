#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
cosX在一个周期内的图形绘制用*组成
*/
int main()
{
    double y;
    int x,m;


    for(y = 1.0; y>=-1.0; y-=0.1)
    {
          //acos(y)对应的是y=1时x的坐标值，
          //y=cos(x)周期是2PI，这里花的是0到2PI的图；
          //乘以10可以使x轴拉长10倍，这样绘制的图形更好看
          //2PI的十倍62.8取整接近63

          //m是待绘制的点的横坐标接近值
          m =(int) (acos(y)*10);

          //m点左边绘制空字符串
          for( x=0; x<m; x++)
               printf(" ");

          //m点处绘制*     
          printf("*");

          //m点右边绘制空字符串
          for( ; x<63-m; x++)
               printf(" ");
          printf("*\n");
    }


    system("pause");

    return 0;
}
