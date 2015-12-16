#include "iostream"
#include "cstdio"
#include "algorithm"
using namespace std;
struct Block
{
    int x, y, z;
} block[200];

int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}
bool cmp(Block a, Block b)
{
    if (a.x * a.y == b.x * b.y)
    {
        return a.y > b.y;
    }
    else
    {
        return a.x * a.y > b.x * b.y;
    }
}
int main()
{
    //freopen("1.in", "r", stdin);
    int n, t=0;
    while (~scanf("%d", &n) && n!=0)
    {
        int a, b, c, k = 0;

        while (n--)
        {
            scanf("%d %d %d", &a, &b, &c);
            block[k].x = max(a, b);
            block[k].y = min(a, b);
            block[k].z = c;
            k++;
            block[k].x = max(a, c);
            block[k].y = min(a, c);
            block[k].z = b;
            k++;
            block[k].x = max(b, c);
            block[k].y = min(b, c);
            block[k].z = a;
            k++;
        }

        sort(block, block + k, cmp);
        int i, j;
    /*    for (i = 0; i < k; i++)
        {
            printf("%d %d %d\n", block[i].x, block[i].y, block[i].z);
        }
*/
        int sum[200], max1;
        sum[0] = block[0].z;
        for(i=1;i<k;i++)
        {
            max1 = -1;
            /*if(block[i].x==block[i-1].x && block[i].y==block[i-1].y && block[i-1].z==block[i-1].z)
                continue;*/
            for(j=0;j<i;j++)
            {
                if(block[i].x < block[j].x && block[i].y < block[j].y && max1<sum[j])
                {
                    max1 = sum[j];
                }
            }
            if(max1 == -1)
            {
                sum[i] = block[i].z;
            }
            else
            {
                sum[i] = max1 + block[i].z;
            }
        }
        max1 = -1;
        for(i=0;i<k;i++)
        {
            if(sum[i] > max1) max1 = sum[i];
        }
        printf("Case %d: maximum height = %d\n", ++t, max1);
    }
}