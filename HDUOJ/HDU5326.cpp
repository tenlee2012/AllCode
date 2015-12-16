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
const int maxn = 1e2+5;
int g[maxn][maxn];
vector<int> v[maxn];
int n, k;
int s[maxn];

int dfs(int id)
{
    int sum = 0, k;
    if(s[id] != -1)
    {
        return s[id];
    }
    for(int i = 0; i < (int)v[id].size(); i++)
    {
        //printf("i = %d, %d\n", i, v[id][i]);
        k = 0;
        k += (int)v[v[id][i]].size();
        k += dfs(v[id][i]);
        //printf("##%d %d\n", v[id][i], k);
        s[v[id][i]] = k;
        sum += k;
    }
    return sum;
}

int main()
{
    int x, y;
    while(~scanf("%d %d", &n, &k))
    {
        clc(s, -1);
        clc(g, 0);
        for(int i = 0; i <= n; i++)
            v[i].clear();
        for(int i = 0; i < n-1; i++)
        {
            scanf("%d %d", &x, &y);
            if(g[x][y] != 0) continue;
            g[x][y] = 1;
            v[x].push_back(y);
        }
        int sum = 0, num = 0;
        for(int i = 1; i <= n; i++)
        {
            sum = 0;
            if(s[i] == -1)
            {
                sum += (int)v[i].size();
                if(sum > k) continue;
                sum += dfs(i);   
            }
            else
            {
                sum = s[i];
            }
            //printf("i = %d, sum = %d\n", i, sum);
            if(sum == k) num++;
        }
        printf("%d\n", num);
    }
    return 0;
}
