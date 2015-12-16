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

using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 33000;
int pri[maxn], hash[maxn], k;
int a[maxn], b[maxn];
int sum;
void findprime()
{
    int i = 0, j = 0;
    k = 0;
    memset(hash, 0, sizeof(hash));
    memset(pri, 0, sizeof(pri));
    hash[0] = hash[1] = 1;
    for(int i = 2; i < maxn; i++)
    {
        if(hash[i]) continue;
        pri[k++] = i;
        for(int j = 2; j * i < maxn; j++)
        {
            hash[j*i] = 1;
        }
    }
}
bool readline()
{
    double x;
    int y;
    while(1)
    {
        scanf("%lf", &x);
        if(x == 0) return false;
        scanf("%d", &y);
        sum = sum * (int)pow((double)x, y);
        //printf("%d  %d# %lf %lf %lf\n", sum, (int)pow(x, y), pow(x, y), x, y);
        if(getchar() == '\n')
            return true;
    }
}

int main()
{
    findprime();
    while(true)
    {
        sum = 1;
        if(!readline()) break;
        sum = sum - 1;
        //printf("sum = %d\n", sum);
        int i = 0, j = 0, t = 0, x = 0, y = 0;
        long long temp = i;

        for (i = 0; pri[i] <= sum && sum != 1; ++i)
        {

            int ct = 0;
            while (sum % pri[i] == 0)
            {
                ct++;
                sum /= pri[i];
            }

            if (ct != 0)
            {

                a[j] = pri[i];
                b[j++] = ct;
            }
        }
        //printf("j = %d#", j);
        for(i = j - 1; i > 0; i--)
        {
            printf("%d %d ", a[i], b[i]);
        }
        printf("%d %d\n", a[0], b[0]);

    }
}
