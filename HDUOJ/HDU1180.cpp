#include "cstdio"
#include "cstring"
#include "queue"
#include "algorithm"
using namespace std;
int n,m, s;
char map[25][25];
int vis[25][25];
int move[4][2] = {0,-1,0,1,-1,0,1,0};
struct point
{
    int x, y, step;
}st;
queue<point>q;

bool cmp(point a, point b)
{
    return a.step < b.step;
}
void bfs();

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    while(~scanf("%d %d",&n,&m))
    {
        memset(map,'*',sizeof(map));

        int i, j;
        getchar();

        for(i=0;i<n;i++)
        {
            gets(map[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(map[i][j] == 'S')
                {
                    st.x = i;
                    st.y = j;
                    st.step = 0;
                    map[i][j] = '*';
                    break;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                vis[i][j] = 1000;
            }
        }
        s = 1000;
        bfs();
        printf("%d\n",s);
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
        int i=0;
        point now = q.front();
        q.pop();
        //printf("x = %d y = %d t = %d \n",now.x,now.y,now.step);

        if(map[now.x][now.y] == 'T')
        {
            s = now.step<s?now.step:s;
        }
        for(i=0;i<4;i++)
        {
            point next = now;
            int xx = now.x, yy = now.y;
            xx += move[i][0];
            yy += move[i][1];
            next.x = xx;
            next.y = yy;

            if(map[xx][yy] == '*') continue;
            if(xx>=n || xx<0 || yy>=m || yy <0) continue;

            int xxx = xx+move[i][0], yyy=yy+move[i][1];

            if(map[xx][yy] == '|')
            {
                if(xxx<n && xxx>=0 && yyy<m && yyy >=0)
                {
                    next.x += move[i][0];
                    next.y += move[i][1];
                    next.step = now.step;
                }
                else continue;
                if(now.step%2==1 && i<2) //这个时候阶梯是   -
                {
                    next.step = now.step+1;
                }
                else if(now.step%2==0 && i>1)//这个时候阶梯是   |
                {
                    next.step = now.step+1;
                }
                else
                {
                    next.step += 2;
                }
            }
            else if(map[xx][yy] == '-')
            {
                if(xxx<n && xxx>=0 && yyy<m && yyy >=0)
                {
                    next.x += move[i][0];
                    next.y += move[i][1];
                    next.step = now.step;
                }
                else continue;

                if(now.step%2==1 && i>1) //这个时候阶梯是   |
                {
                    next.step += 1;
                }
                else if(now.step%2==0 && i<2)//这个时候阶梯是   -
                {
                    next.step += 1;
                }
                else
                {
                    next.step += 2;
                }
            }
            else
            {
                next.step++;
            }

            if(next.step < vis[next.x][next.y])
            {
                //printf("\t%d %d %d\n",next.x,next.y,next.step);
                vis[next.x][next.y] = next.step;
                q.push(next);
            }
        }
    }
}
