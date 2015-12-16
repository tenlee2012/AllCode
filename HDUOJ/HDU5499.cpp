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
const int maxn = 1e3+5;

struct People
{
    double r1, r2, r;
    char name[30];
}man[maxn], woman[maxn], all[maxn];
int n, m;

bool cmp(People A, People B)
{
    return A.r > B.r;
}

int main()
{
    int T;
    char name[maxn], sex[maxn];
    double s1, s2, r1, r2, r, mr1, mr2;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        double s1 = s2 = mr1 = mr2 = 0;
        int ma = 0, fe = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%s %s %lf %lf", name, sex, &r1, &r2);
            if(sex[0] == 'f')
            {
                strcpy(woman[fe].name, name);
                woman[fe].r1 = r1;
                woman[fe++].r2 = r2;  
            }
            else
            {
                strcpy(man[ma].name, name);
                man[ma].r1 = r1;
                man[ma++].r2 = r2;  
            }
            mr1 = max(mr1, r1);
            mr2 = max(mr2, r2);
            s1 += r1;
            s2 += r2;
        }
        double k1 = 300.0 / mr1;
        double k2 = 300.0 / mr2;
        int j = 0;
        for(int i = 0; i < ma; i++)
        {
            man[i].r = man[i].r1 * k1 * 0.3 + man[i].r2 * k2 * 0.7;
            all[j++] = man[i];
        }
        for(int i = 0; i < fe; i++)
        {
            woman[i].r = woman[i].r1 * k1 * 0.3 + woman[i].r2 * k2 * 0.7;
            all[j++] = woman[i];
        }
        sort(man, man+ma, cmp);
        sort(all, all+n, cmp);
        sort(woman, woman+fe, cmp);
        puts("The member list of Shandong team is as follows:");
        if(fe)
        {
            for(int i = 0; i < m-1; i++)
                printf("%s\n", all[i].name);
            if(all[m-1].r >= woman[0].r)
            {
                printf("%s\n", woman[0].name);
            }
            else
            {
                printf("%s\n", all[m-1].name);
            }
        }
        else
        {
            for(int i = 0; i < m; i++)
                printf("%s\n", all[i].name);
        }
    }
}
