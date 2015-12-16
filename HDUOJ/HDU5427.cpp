//Author LJH
//www.cnblogs.com/tenlee
#include <stdio.h>
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
const int maxn = 500;

int n;
char str[maxn][maxn];
struct Man
{
    char name[maxn];
    int age;
}man[maxn];

bool cmp(Man A, Man B)
{
    return A.age > B.age;
}

void slove()
{
    int j = 0, k = 0, ll;
    for(int i = 0; i < n; i++)
    {
        ll = strlen(str[i]);
        k = 0;
        for(j = 0; j < ll - 5; j++)
        {
            man[i].name[k++] = str[i][j];
        }
        man[i].name[k++] = '\0';
        j++;
        man[i].age = 1000 * (str[i][j] - '0') + 100 * (str[i][j+1] - '0')
            + 10 * (str[i][j+2] - '0') + str[i][j+3] - '0';
    }
    sort(man, man+n, cmp);
    for(int i = 0; i < n; i++)
    {
        puts(man[i].name);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        getchar();
        for(int i = 0; i < n; i++)
        {
            gets(str[i]);
        }
        slove();
    }
    return 0;
}
