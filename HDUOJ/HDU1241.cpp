#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int m, n;
char field[105][105];
void dfs(int x, int y);
int main()
{
    while (~scanf("%d%d", &m, &n) && m+n!=0)
    {
        memset(field,0,sizeof(field));
        int i, j, t = 0;

        for (i = 0; i < m; i++)
        {
            getchar();
            scanf("%s",field[i]);
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (field[i][j] == '@')
                {

                    dfs(i, j);
                    t++;
                }
            }
        }

        printf("%d\n", t);
    }
}

void dfs(int x, int y)
{
    int i, j;
    field[x][y] = '*';

    for (i = -1; i < 2; i++)
    {
        for (j = -1; j < 2; j++)
        {
            int nx = x + i, ny = y + j;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && field[nx][ny] == '@')
            {

                dfs(nx, ny);
            }
        }
    }

    return;
}
