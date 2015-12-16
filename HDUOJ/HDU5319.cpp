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
const int maxn = 100;
int movex[2][2] = {-1, -1, 1, 1};
int movey[2][2] = {-1, 1,  1, -1};

int n, m, g[maxn][maxn], ans;

bool judge(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > m) return  false;
    return true;
}
void findx(int x, int y)
{
    int a = x, b = y;
    g[x][y] -= 1;
    while(judge(a, b))
    {
        a += movex[0][0];
        b += movex[0][1];
        if(g[a][b] == 2 || g[a][b] == 0) break;
        g[a][b] -= 1;
    }
    a = x, b = y;
    while(judge(a, b))
    {
        a += movex[1][0];
        b += movex[1][1];
        if(g[a][b] == 2 || g[a][b] == 0) break;
        g[a][b] -= 1;
    }

}
void findy(int x, int y)
{
    g[x][y] -= 2;
    int a = x, b = y;
    while(judge(a, b))
    {
        a += movey[0][0];
        b += movey[0][1];
        if(g[a][b]  == 1 || g[a][b] == 0) break;
        g[a][b] -= 2;
    }
    a = x, b = y;
    while(judge(a, b))
    {
        a += movey[1][0];
        b += movey[1][1];
        if(g[a][b]  == 1 || g[a][b] == 0) break;
        g[a][b] -= 2;
    }
}

void Print()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d", g[i][j]);
        }
        puts("");
    }
    puts("#####");
}
int main()
{
    //freopen("1.in", "r", stdin);
    int T;
    char col[maxn];
    char ch;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        clc(g, 0);
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf(" %s", col);
            m = strlen(col);
            for(int j = 0; col[j]; j++)
            {   
                ch = col[j];
                if(ch == 'R') g[i][j+1] = 1;
                if(ch == 'B') g[i][j+1] = 2;
                if(ch == 'G') g[i][j+1] = 3;
                if(ch == '.') g[i][j+1] = 0;
            }
        }
        //Print();
        for(int i = 1; i <=n ;i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(g[i][j] == 3)
                {
                    ans += 2;
                    findx(i, j);
                    findy(i, j);
                }
            }
        }
        //Print();
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(g[i][j] == 1)
                {
                    ans++;
                    findx(i, j);
                    //Print();
                }
                if(g[i][j] == 2) 
                {
                    ans++;
                    findy(i, j);
                    //Print();
                }
            }
        }
        //Print();
        printf("%d\n", ans);
    }
    return 0;
}
