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
#define LL long long
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 150005;

struct Person
{
    int v, id;
    char name[205];
    bool operator < (const Person & A) const
    {
        if(A.v == v) return id > A.id;
        return v < A.v;
    }
}per[maxn];
struct TT
{
    int t, p;
    bool operator < (const TT & A) const
    {
        return t < A.t;
    }

}tt[maxn];
int ans[maxn];
int k, m, qq;
priority_queue<Person> q;

int main()
{
    int T;
    int x, y, i, f;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &k, &m, &qq);
        for(i = 0; i < k; i++)
        {
            scanf("%s %d", per[i].name, &per[i].v);
            per[i].id = i;
        }
        i = 0, f = 1;
        for(int j = 0; j < m; j++)
        {
            scanf("%d %d", &tt[j].t, &tt[j].p);
        }
        sort(tt, tt+m);
        for(int j = 0; j < m; j++)
        {
            x = tt[j].t; y = tt[j].p;
            for(; i < x; i++)
            {
                if(i > k) break;
                q.push(per[i]);
            }
            for(int ii = 0; ii < y; ii++)
            {
                if(q.empty()) break;
                ans[f++] = q.top().id;
                q.pop();
            }
        }

        for(; i < k; i++)
        {
            q.push(per[i]);
        }
        while(!q.empty())
        {
            ans[f++] = q.top().id;
            q.pop();
        }
        for(int ii = 0; ii < qq; ii++)
        {
            scanf("%d", &x);
            printf("%s", per[ans[x]].name);
            if(ii != qq-1) printf(" ");
        }
        puts("");
    }
    return 0;
}

