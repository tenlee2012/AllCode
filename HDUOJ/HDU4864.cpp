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

struct Task
{
    int x, y;
}task[maxn], mac[maxn];
int n, m;
int ha[maxn];

bool cmp(Task A, Task B)
{
    if(A.x == B.x) return A.y > B.y;
    return A.x > B.x;
}
int main()
{
    while(~scanf("%d %d", &n, &m))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &mac[i].x, &mac[i].y);
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &task[i].x, &task[i].y);
        }
        sort(mac, mac+n, cmp);
        sort(task, task+m, cmp);
        memset(ha, 0, sizeof(ha));
        int j = 0, k = 0, num = 0;
        long long ans = 0;
        for(int i = 0; i < m; i++) 
        {
            while(j < n && (mac[j].x >= task[i].x)) // 找到 下限 的 机器 j 
            {
                ha[mac[j].y]++; //把所有 x 合适的 机器的 y 记下来
                j++;
            }
            for(k = task[i].y; k <= 100; k++)
            {
                if(ha[k]) //从 x 合适 的机器 中 挑选 y 也合适， 同时 y 最小
                {
                    ans += (500 * task[i].x + 2 * task[i].y);
                    ha[k]--; //该机器已用，减去
                    num++;
                    break;
                }
            }
        }
        printf("%d %lld\n", num, ans);
    }
    return 0;
}
