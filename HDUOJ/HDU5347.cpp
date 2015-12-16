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
const int maxn = 1e6+5;

int a[100] = {
    0, 1312, 2372, 
    520,899,800,1086,1402,1313,1681,2080,
    495,737,577,786,1011,999,1251,1520
};
void init()
{
    a[1] = 1312; a[2] = 2372;
    a[3] = 520; a[4] = 899; a[5] = 800;a[6]=1086;a[7]=1402;a[8]=1313;a[9]=1681;a[10]=2080;
    a[11]=495;a[12]=737;a[13]=577;a[14]=786;a[15]=1011;a[16]=999;a[17]=1251;a[18]=1520;
    a[35]= 1139; a[36] = 1350;
    a[53] = 1008; a[54] = 1170;
    a[85] = 1000; a[86] = 1037;
}

int main()
{
    init();
    int x, y;
    while(~scanf("%d %d", &x, &y))
    {
        if(a[x] > a[y])
        {
            puts("FIRST BIGGER");
        }
        else
        {
            puts("SECOND BIGGER");
        }

    }
    return 0;
}

