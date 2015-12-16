#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
void dfs(int x, int y);
char room[25][25];
int m, n, k;
int main()
{
    while (~scanf("%d%d", &n, &m) && m+n !=0)
    {
        int i, j;
        k = 0;
        memset(room,0,sizeof(room));
        for (i = 0; i < m; i++)
        {
            getchar();
            for (j = 0; j < n; j++)
            {

                scanf("%c", &room[i][j]);
            }
        }
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (room[i][j] == '@')
                {
                    dfs(i, j);
                }
            }
        }
        printf("%d\n",k);
    }
}

void dfs(int x, int y)
{
    k++;
    room[x][y] = '#';
    int i, j;

    for (i = -1; i < 2; i++)
    {
        for (j = -1; j < 2; j++)
        {
            int nx = x+i,ny = y+j;
            if ((nx == x || ny == y ) && room[nx][ny] == '.')
            {
                dfs(nx, ny);
            }
        }
    }
}
