//Author LJH
//www.cnblogs.com/tenlee
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define clc(a, b) memset(a, b, sizeof(a))
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
int n;

void n15()
{
    int i;
    printf("1 + 2\n");
    for(i = 1; i < 2; i++)
    {
        printf("%d + %d\n", n+i, i+2);
    }
    printf("%d / 4\n", n+2); //n+3 = 3
    printf("5 + 6\n"); // n + 4
    for(i = 7;i <= 12; i++)
    {
        printf("%d + %d\n", i, n+i-3);
    }
    printf("%d / %d\n", n+10, 13); //n+11  8
    printf("%d * %d\n", n+3, n+11); //n+12 3*8
    printf("14 - 15\n");//n+13
    for(i = n+14; i <= 2*n-2; i++)
    {
        printf("%d * %d\n", i-n+2, i-1);
    }
    printf("%d + %d\n", n+12, 2*n-2);
}
void n13()
{
    int i;
    printf("1 + 2\n");
    for(i = 1; i < 2; i++)
    {
        printf("%d + %d\n", n+i, i+2);
    }
    printf("%d / 4\n", n+2); //n+3 = 3
    printf("5 + 6\n"); // n + 4
    for(i = 7;i <= 12; i++)
    {
        printf("%d + %d\n", i, n+i-3);
    }
    printf("%d / %d\n", n+10, 13); //n+11  8
    printf("%d * %d\n", n+3, n+11); //n+12 3*8
}
void n14()
{
    puts("1 + 2"); //15 2*14
    puts("3 / 4"); //16 1
    puts("5 / 6"); //17 1
    puts("16 + 17");//18 2
    puts("7 / 8"); //19 1
    puts("9 / 10"); //20 1
    puts("19 + 20"); //21 2
    puts("18 + 21");//22 4
    puts("15 - 22"); //23 24
    puts("11 - 12");//24 0
    puts("13 - 14"); //25 0
    puts("24 + 25"); //26 0
    puts("26 + 23");// 27
}
void n4()
{
    printf("1 * 2\n"); 
    printf("3 + 5\n"); 
    printf("4 + 6\n"); 
}
void n5()
{
    printf("1 / 2\n"); 
    printf("6 / 3\n"); 
    printf("4 - 7\n"); 
    printf("5 * 8\n"); 
}
void n6()
{
    printf("1 * 2\n"); 
    printf("7 - 3\n"); 
    printf("8 - 4\n"); 
    printf("9 - 5\n"); 
    printf("10 + 6\n"); 
}
void n7()
{
    printf("1 * 2\n"); 
    printf("3 / 4\n"); 
    printf("5 + 6\n"); 
    printf("8 - 9\n"); 
    printf("11 / 10\n"); 
    printf("12 * 7\n"); 
}
void n8()
{
    printf("1 + 2\n"); 
    printf("3 + 9\n"); 
    printf("4 - 5\n"); 
    printf("6 * 11\n"); 
    printf("7 * 12\n");
	printf("8 * 13\n"); 
    printf("10 + 14\n"); 
}
void n9()
{
    printf("1 + 2\n"); 
    printf("3 + 10\n"); 
    printf("4 / 5\n"); 
    printf("6 / 7\n"); 
    printf("8 / 9\n");
	printf("11 - 12\n"); 
    printf("15 - 13\n"); 
    printf("16 - 14\n");
}
void n10()
{
    puts("1 + 2"); //11 20
    puts("3 / 4");//12 1
    puts("5 / 6");// 13 1
    puts("7 / 8");//14 1
    puts("9 / 10");//15 1
    puts("11 + 12");//16 21
    puts("16 + 13");//17 22
    puts("17 + 14");//18 23
    puts("18 + 15");//18 24
}
void n11()
{
    puts("1 + 2"); //12 22
    puts("12 / 3"); //13 2
    puts("4 + 5");//14 22
    puts("14 + 13"); //15 24
    puts("6 - 7");//16 0
    puts("8 - 9"); //17 0
    puts("10 - 11"); // 18 0
    puts("16 * 17");//19
    puts("18 * 19");//20
    puts("20 + 15");//21
    
}
void n12()
{
    puts("1 + 2"); // 13 24
    puts("3 - 4"); // 14
    puts("14 * 5"); //15
    puts("15 * 6"); //16
    puts("16 * 7");//17
    puts("17 * 8");//18
    puts("18 * 9");//19
    puts("19 * 10");//20
    puts("20 * 11");//21
    puts("21 * 12");//22
    puts("22 + 13");//23
}
int main()
{
    while(~scanf("%d", &n))
    {
        if(n < 4)
        {
            puts("-1");
            continue;
        }
        if(n == 4) n4();
        else if(n == 5) n5();
        else if(n == 6) n6();
        else if(n == 7) n7();
        else if(n == 8) n8();
        else if(n == 9) n9();
        else if(n == 10) n10();
        else if(n == 11) n11();
        else if(n == 12) n12();
        else if(n == 13) n13();
        else if(n == 14) n14();
        else
        {
            n15();
        }
    }
}
