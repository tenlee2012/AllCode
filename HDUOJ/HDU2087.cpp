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

char pattern[maxn], text[maxn];

int find_substring(char *pattern, char *text)
{
    int n = strlen(pattern);
    vector <int> next(n+1, 0);//初始化n+1个值为0的数组
    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(j > 0)
        {
            j = next[j];
            if(pattern[j] == pattern[i])
            {
                next[i+1] = j + 1;
                break;
            }
        }
    }
    vector<int> positions;
    int m = strlen(text);
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
            j = 0;
        }
    }
    return (int)positions.size();
}

int main()
{
    while(~scanf("%s", text))
    {
        if(text[0] == '#') break;
        scanf("%s", pattern);
        int x = find_substring(pattern, text);
        printf("%d\n", x);
    }
    return 0;
}

