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

struct Node
{
    int dis, fuel;
    bool operator < (const Node &a) const
    {   //由大到小排列
        return fuel < a.fuel;
    }
}node[maxn];

bool cmp(Node a, Node b)
{
    return a.dis < b.dis;
}

int main()
{
    int n, x, y, ans = 0, f = 0;
    priority_queue<Node> q;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &node[i].dis, &node[i].fuel);
        }
        scanf("%d %d", &x, &y);
        for(int i = 0; i < n; i++)
            node[i].dis = n - node[i].dis;
        sort(node, node + n, cmp);

        while(!q.empty()) q.pop();
        ans = 0;
        f = 0;
        int i = 0;
        for(i = 0; i < n; i++)
        {
            if(node[i].dis  > y)
            {
                ans++;
                y += q.top().fuel;
                q.pop();
            }
            if(node[i].dis <= y)
            {
                q.push(node[i]);
            }
        }
        while(!q.empty() && y < x)
        {
            y += q.top().fuel;
            ans++;
            q.pop();
        }
        if(y < x)
        {
            puts("-1");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}
