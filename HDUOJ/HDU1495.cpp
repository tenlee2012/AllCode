#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 500;
struct Coke
{
    int a, b, c;
    int step;
}coke[maxn];

int a, b, c, ok;
int Hash[maxn][maxn], dir[3];
queue<Coke> q;
Coke now, Ne;

bool judge(int x, int y, int z)
{
    //printf("In %d %d %d\n", x, y, z);
    if(x < 0 || x > a) return false;
    if(y < 0 || y > b) return false;
    if(z < 0 || z > c) return false;
    if(Hash[x][y]) return false;
    Ne.a = x; Ne.b = y; Ne.c = z; Ne.step = now.step+1;
    //printf("out %d %d %d\n", x, y, z);
    Hash[x][y] = 1;
    q.push(Ne);
    if(x==a/2 && y==a/2) ok=1;
    if(x==a/2 && z==a/2) ok=1;
    if(z==a/2 && y==a/2) ok=1;
    return true;
}
int BFS()
{
    while(!q.empty()) q.pop();

    int x, y, z, mi, ma;
    Coke s;
    s.a = a; s.b = 0; s.c = 0; s.step = 0;
    q.push(s);
    Hash[a][0] = 1;
    while(!q.empty())
    {
        now = q.front(); q.pop();
        Ne = now;
        //a->b
        mi = min(now.a, (b-now.b));
        x = now.a - mi; y = now.b + mi; z = now.c;
        judge(x, y, z);
        //a->c
        mi = min(now.a, (c-now.c));
        x = now.a - mi; z = now.c + mi; y = now.b;
        judge(x, y, z);
        //b->a
        mi = min(now.b, (a-now.a));
        y = now.b - mi; x = now.a + mi; z = now.c;
        judge(x, y, z);
        //b->c
        mi = min(now.b, (c-now.c));
        y = now.b - mi; z = now.c + mi; x = now.a;
        judge(x, y, z);
        //c->a
        mi = min(now.c, (a-now.a));
        z = now.c - mi; x = now.a + mi; y = now.b;
        judge(x, y, z);
        //c->b
        mi = min(now.c, (b-now.b));
        z = now.c - mi; y = now.b + mi; x = now.a;
        judge(x, y, z);
        
        if(ok == 1) return now.step+1;
    }
    return 0;
}

int main()
{
    while(scanf("%d %d %d", &a, &b, &c) && (a+b+c))
    {
        if(a%2)
        {
            puts("NO"); continue;
        }
        ok = 0;
        memset(Hash, 0, sizeof(Hash));
        int ans = 0;
        if(ans = BFS()) printf("%d\n", ans);
        else puts("NO");
    }
    return 0;
}
