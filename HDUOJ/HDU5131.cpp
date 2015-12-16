//Author LJH
//www.cnblogs.com/tenlee
#include <iostream>
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
#include <string>
#define clc(a, b) memset(a, b, sizeof(a))
#define LL long long
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 300+5;

struct Outlaw
{
    string name;
    int minor, major;
    int num;
}outlaws[maxn];
map<string, int>mp;

bool cmp(Outlaw A, Outlaw B)
{
    if(A.num == B.num) return A.name < B.name;
    return A.num > B.num;
}

inline void print(int id)
{
    cout << outlaws[id].name << " " << outlaws[id].num << endl;
}

int main()
{
    int n;
    while(~scanf("%d", &n) && n)
    {
        mp.clear();
        for(int i = 1; i <= n; i++)
        {
            cin >> outlaws[i].name >> outlaws[i].num;
        }
        sort(outlaws+1, outlaws+n+1, cmp);
        int k = 1;
        print(1);
        mp[outlaws[1].name] = 1;
        outlaws[1].minor = 1;
        outlaws[1].major = 1;
        for(int i = 2; i <= n; i++)
        {
            print(i);
            if(outlaws[i].num == outlaws[i-1].num)
            {
                k++;
            }
            else 
            {
                k = 1;
            }
            mp[outlaws[i].name] = i;
            outlaws[i].major = i-k+1;
            outlaws[i].minor = k;
        }
        int m, id;
        string name;
        scanf("%d", &m);
        while(m--)
        {
            cin >> name;
            id = mp[name];
            if(outlaws[id].minor == 1)
            {
                printf("%d\n", outlaws[id].major);
            }
            else
            {
                printf("%d %d\n", outlaws[id].major, outlaws[id].minor);
            }
        }
    }
    return 0;
}

