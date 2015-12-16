#include<iostream>
#include<cmath>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int Max = 205;
const int inf = 9999999;
 
struct{
    int r, c;
}man[Max], hou[Max];
int M, H, n, m;           //  n为X集合顶点数量，m为Y集合顶点数量。(1~n和1~m)
int map[Max][Max];        //  map[i][j]：记录X集合中的i到Y集合中的j所需的费用。
int lx[Max], ly[Max];   //左边点的定标值，右边点的定标值
int match[Max];     //右边点匹配的结果，右边点的松弛值
bool x[Max], y[Max];    //找增光轨过程中使用过(交错树中)的左边、右边的点
 
bool dfs(int u)
{          //  判断能否找到最大完全匹配。
    x[u] = true;    //标记为交错树中的点
    for(int v = 1; v <= m; v++)
        if(!y[v] && lx[u] + ly[v] == map[u][v])
        {
            y[v] = true;
            if(!match[v] || dfs(match[v]))//尚未匹配 || 已经匹配但从其出发仍然可以找到增广轨
            {
                match[v] = u;
                return true;
            }
        }
    return false;
}
 
int KM()
{                 //  KM算法。
    int i, j, k, mi;
    //初始化顶标值，左边为连接各边的最大值，右边为0
    for(i = 1; i <= n; i ++)
        for(lx[i] = -inf, j = 1; j <= m; j ++)       
            lx[i] = max(lx[i], map[i][j]);      //初始化松弛值

    memset(ly, 0, sizeof(ly));
    memset(match, 0, sizeof(match));
    for(i = 1; i <= n; i++)
    {
        while(1)
        {
            memset(x, 0, sizeof(x));
            memset(y, 0, sizeof(y));
            if(dfs(i)) break;       //找到增广轨
            mi = inf;       //未找到增广轨，修改定标值
            for(j = 1; j <= n; j++)
                if(x[j])
                    for(k = 1; k <= m; k++)
                        if(!y[k])
                            mi = min(mi, lx[j] + ly[k] - map[j][k]);
            for(j = 1; j <= n; j ++) if(x[j]) lx[j] -= mi;
            for(j = 1; j <= m; j ++) if(y[j]) ly[j] += mi;
        }
    }
    int ans = 0;
    for(i = 1; i <= m; i++)
        if(match[i] > 0)
            ans += map[match[i]][i];
    return ans;
}
 
int main(){
    int row, col, i, j;
    char ch;
    while(cin >> row >> col)
    {
        if(row == 0 && col == 0) break;
        M = 0, H = 0;
        for(i = 0; i < row; i ++)
            for(j = 0; j < col; j ++)
            {
                cin >> ch;
                if(ch == 'm')
                {
                    man[++ M].r = i;
                    man[M].c = j;
                }
                else if(ch == 'H')
                {
                    hou[++ H].r = i;
                    hou[H].c = j;
                }
            }
        n = m = M;
        for(int i = 1; i <= M; i ++)      //  KM算法是求最大权，故这里存负数，最后取反求最小权。
            for(int j = 1; j <= H; j ++)
                map[i][j] = -abs(man[i].r-hou[j].r)-abs(man[i].c-hou[j].c);
        cout << -KM() << endl;
    }
    return 0;
}