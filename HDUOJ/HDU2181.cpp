#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

#define maxn 10000000
struct Ball
{
    int a, b, c;
}ball[30];
bool visit[30];
int an[30], sta;
int res[30];
int lop=0;
void DFS(int n, int num)
{
    res[num] = n;
    int a = ball[n].a, b = ball[n].b, c = ball[n].c;
    if(num == 19)
    {
        if(a==sta || b==sta || c==sta)
        { 
           printf("%d:  ", ++lop); 
            for(int i = 0; i <= 19; i++)
                printf("%d ", res[i]);
            printf("%d\n", sta);
        }
        return;
    }
    int aa = ++num, bb = num, cc = num;
    if(!visit[a])
    {
        visit[a] = 1;
        DFS(ball[n].a, aa);
        visit[a] = 0;
    }
    if(!visit[b])
    {
        visit[b] = 1;
        DFS(b, bb);
        visit[b] = 0;
    }

    if(!visit[c])
    {
        visit[c] = 1;
        DFS(c, cc);
        visit[c] = 0;
    }

}
int main()
{
    //freopen("1.txt", "r", stdin);
   // freopen("3.txt", "w", stdout);
    int n;
    for(int i = 1; i <= 20; i++)
    {
        scanf("%d %d %d", &ball[i].a, &ball[i].b, &ball[i].c);
    }
    while(1)
    {
        scanf("%d", &n);
        sta = n;
        if(!n) break;
        memset(visit, false, sizeof(visit));
        visit[n] = 1;
        lop=0;
        DFS(n, 0);
    }
    return 0;
}
