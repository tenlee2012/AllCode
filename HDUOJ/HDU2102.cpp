// hdu 2102 A ji hua (xiu gai ban)
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

#define N 15
struct point
{
    int x, y, floor, time;
} st;
int m, n, t, flag;
char s[2][N][N];
int move[4][2] = {0, -1, 0, 1, -1, 0, 1, 0};
queue<point>q;

void bfs();

int main()
{
    //freopen("1.in", "r", stdin);
    int tt;
    cin >> tt;

    while (tt--)
    {
        int i, j;
        cin >> n >> m >> t;

        memset(s,'*',sizeof(s));

        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> s[i][j];
            }
        }
        flag = 0;
        st.x = 0;
        st.y = 0;
        st.floor = 0;
        st.time = 0;
        bfs();
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
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
        //printf("x %d y %d f %d t %d\n",now.x, now.y, now.floor, now.time);
        for(int i=0;i<4;i++)
        {
            point next = now;
            int xx = now.x, yy = now.y, f = now.floor;
            //printf("xx %d yy %d\n",xx,yy);
            xx += move[i][0];
            yy += move[i][1];
            next.time++;

            if(next.time>t) continue;
            if(xx<0 || xx>=n || yy<0 || yy>=m)    continue;
            if(s[f][xx][yy] == '*') continue;

            if (s[f][xx][yy] == 'P')
            {
                flag = 1;
                return;
            }
            if(s[f][xx][yy]=='#' && s[1-f][xx][yy] == 'P')
            {
                flag = 1;
                return;
            }

            if(s[f][xx][yy]=='#' && s[1-f][xx][yy] == '#')
            {
                s[0][xx][yy] = '*';
                s[1][xx][yy] = '*';
                continue;
            }
            if(s[f][xx][yy]=='#' && s[1-f][xx][yy] == '*')
            {
                s[0][xx][yy] = '*';
                s[1][xx][yy] = '*';
                continue;
            }
            if(s[f][xx][yy]=='#' && s[1-f][xx][yy] == '.')
            {
                s[f][xx][yy] = '*';
                s[1-f][xx][yy] = '*';
                next.floor = 1-f;
                next.x = xx;
                next.y = yy;
            }
            if(s[f][xx][yy] == '.')
            {
                s[f][xx][yy] = '*';
                next.x = xx;
                next.y = yy;
            }
            q.push(next);
        }
    }
}
