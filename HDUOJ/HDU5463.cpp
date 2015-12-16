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
const int maxn = 1e6+5;

int n;
struct Met
{
    int type, num;
}met[maxn];

bool cmp(Met A, Met B)
{
    return A.type < B.type;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);   
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &met[i].type, &met[i].num);
        }
        sort(met, met+n, cmp);
        int i = 0, j, k = 0, sum;
        while(i < n)
        {
            j = i+1;
            sum = met[i].num;
            while(met[j].type == met[i].type)
            {
                sum += met[j].num;
                j++;
            }
            i = j;
            if(sum%64) k += (sum / 64 + 1);
            else k += (sum / 64);
        }
        if(k % 36) printf("%d\n", k / 36 + 1);
        else printf("%d\n", k / 36);
    }
    return 0;
}
