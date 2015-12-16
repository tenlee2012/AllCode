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

int pattern[maxn], text[maxn];

vector <int> find_substring(int m, int n)
{
    //int n = strlen(pattern);
    vector <int> next(n + 1, 0);
    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(j > 0)
        {
            j = next[j];
            if(pattern[j] == pattern[i])
            {
                next[i + 1] = j + 1;
                break;
            }
        }
    }

    vector <int> positions;
    //int m = strlen(text);
    for(int i = 0, j = 0; i < m; i++)
    {
        if(j < n && text[i] == pattern[j])
        {
            j++;
        }
        else 
        {
            while(j > 0)
            {
                j = next[j];
                if(text[i] == pattern[j])
                {
                    j++;
                    break;
                }
            }
        }
        if(j == n)
        {
            positions.push_back(i - n + 1);
        }
    }
    return positions;
}

int main()
{
    int T;
    int m, n, i, j;
    vector <int> posi;
    scanf("%d", &T);
    while(T--)
    {
        i = j = 0;
        scanf("%d %d", &m, &n);
        for(i = 0; i < m; i++)
        {
            scanf("%d", &text[i]);
        }
        for(j = 0; j < n; j++)
        {
            scanf("%d", &pattern[j]);
        }
        posi = find_substring(m, n);
        if(!posi.size())
        {
            puts("-1");
        }
        else
        {
            printf("%d\n", posi[0] + 1);
        }
    }
}
