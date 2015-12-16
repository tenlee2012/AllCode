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

using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 510;
int n, m;
bool edge[maxn][maxn], visit[maxn];
int match[maxn];
struct Stu
{
    int age;
    char sex, music[maxn], sport[maxn];
}stu[maxn];

bool dfs(int u)
{
    for(int v = 1; v <= n; v++)
    {
        if(edge[u][v] && !visit[v])
        {
            visit[v] = 1;
            if(match[v] == -1 || dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(visit, 0, sizeof(visit));
        if(dfs(i)) sum++;
    }
    return sum;
}

bool Judge(int i, int j)
{
    if(abs(stu[i].age - stu[j].age) > 40) return true;
    if(stu[i].sex == stu[j].sex) return true;
    if(strcmp(stu[i].music, stu[j].music)) return true;
    if(!strcmp(stu[i].sport, stu[j].sport)) return true;
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %c %s %s", &stu[i].age, &stu[i].sex, stu[i].music, stu[i].sport);
        }
        memset(edge, 0, sizeof(edge));
        memset(match, -1, sizeof(match));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(!Judge(i, j)) edge[i][j] = edge[j][i] = 1;
            }
        }
        printf("%d\n", n - hungary()/2);
    }
}
