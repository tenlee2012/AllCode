#include "cstdio"
#include "cstring"
#include "queue"
using namespace std;
int move[6][3] = {0, 0, -1, 0, 0, 1, 0, -1, 0, 0, 1, 0, -1, 0, 0, 1, 0, 0};
int map[55][55][55];
int a, b, c, t, flag, sum;
struct point
{
    int x, y, z, step;
} st;
queue<point>q;

void bfs();
int  main()
{
    int tt;
    scanf("%d", &tt);

    while (tt--)
    {
        scanf("%d %d %d %d", &a, &b, &c, &t);
        int i, j, k;

        for (i = 0; i < a; i++)
        {
            for (j = 0; j < b; j++)
            {
                for (k = 0; k < c; k++)
                {
                    scanf("%d", &map[i][j][k]);
                }
            }
        }
        flag = 0;
        st.x = 0;
        st.y = 0;
        st.z = 0;
        st.step = 0;
        bfs();
        if(flag) printf("%d\n",sum);
        else printf("-1\n");
    }

    return 0;
}

void bfs()
{
    while(!q.empty())
    {
        q.pop();
    }

    q.push(st);
    while(!q.empty())
    {
        point now = q.front();
        q.pop();
        //printf("x %d y %d z %d t %d\n",now.x,now.y,now.z,now.step);
        if(now.z==a-1 && now.x==b-1 &&now.y==c-1 && now.step<=t)
        {
            flag = 1;
            sum = now.step;
            return;
        }
        for(int i=0;i<6;i++)
        {
            point next = now;
            int xx = now.x, yy = now.y, zz = now.z;
            xx += move[i][1];
            yy += move[i][2];
            zz += move[i][0];

            if(map[zz][xx][yy] == 1) continue;
            if(zz>=a || zz<0 || xx>=b || xx<0 || yy>=c || yy<0) continue;
            map[zz][xx][yy] = 1;
            next.x = xx;
            next.y = yy;
            next.z = zz;
            next.step++;
            q.push(next);
        }
    }
}
