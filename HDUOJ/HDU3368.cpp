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
const int maxn = 10;

int Move[8][2] = {0, -1, 0, 1, -1, 0, 1, 0, -1, -1, -1, 1, 1, -1, 1, 1};
int ans = 0, k = 0, sx, sy;
char G[maxn][maxn];

bool judge(int x, int y)
{
    if(x < 0 || x >= 8 || y < 0 || y >= 8) return false;
    return true;
}
void BFS(int x, int y)
{
    int xx, yy, num;
    //printf("x = %d, y = %d\n", x, y);
    for(int i = 0; i < 8; i++)
    {
        num = 0;
        xx = x; yy = y;
        while(true) 
        {
            xx += Move[i][0];
            yy += Move[i][1];
            if(!judge(xx, yy) || G[xx][yy] == '*') 
            {
                num = 0;
                break;
            }
            if(G[xx][yy] == 'L')
            {
                num++;
                //printf("num = %d\n", num);
            }
            if(G[xx][yy] == 'D') break;
        }
        k += num;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        ans = 0;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                scanf(" %c", &G[i][j]);
            }
        }

        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(G[i][j] == '*')
                {
                    k = 0;
                    sx = i; sy = j;
                    BFS(i, j);
                   // puts("###");
                    if(k > ans) ans = k;
                }   
            }
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}

