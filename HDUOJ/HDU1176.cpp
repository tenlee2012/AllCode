#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;

const int maxn = 100005;
const int maxm = 12;
int n;
int point[maxn][maxm], sum[maxn][maxm];

void Init()
{
    memset(point, 0, sizeof(point));
    memset(sum, 0, sizeof(sum));
}

int main()
{
    while(~scanf("%d", &n) && n)
    {
        Init();
        int x, t, T = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &t);
            point[t][x]++;
            T = max(t, T);
        }
        int s = 0;
        
        sum[1][4] = point[1][4];
        sum[1][5] = point[1][5];
        sum[1][6] = point[1][6];
        for(int i = 2; i <= T; i++)
        {
            for(int j = 0; j <= 10; j++)
            {
                if(j == 0) 
                    sum[i][j] = max(sum[i-1][j], sum[i-1][j+1])
                        + point[i][j];
                else if (j == 10) 
                    sum[i][j] = max(sum[i-1][j], sum[i-1][j-1])
                        + point[i][j];
                else
                    sum[i][j] = max(sum[i-1][j-1],  
                            max(sum[i-1][j], sum[i-1][j+1])) 
                        + point[i][j];
                //printf("%d %d %d\n", j, i, sum[j][i]);
                s = max(sum[i][j], s);
            }
        }
        printf("%d\n", s);
    }
    return 0;
}
