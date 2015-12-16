#include<stdio.h>
#include<map>
#include<cstring>
#include<string>
using namespace std;
map<string,int>m;
int main()
{
    char s[1005][20];
    int n;
    while(~scanf("%d",&n)&&n!=0)
    {
        getchar();
        m.clear();
        int k = 0,max = 1;
        char ss[20];
        for(int i = 0;i<n;i++)
        {
            gets(s[i]);
            if(m[s[i]] == 0)
            {
                m[s[i]] = 1;
                k++;
                //printf("%d\n",m[s[i]]);
            }
            else
            {
                m[s[i]]++;
                if(m[s[i]] > max)
                {
                    max = m[s[i]];
                    strcpy(ss,s[i]);
                }
            }
        }
        if(max != 1)
            puts(ss);
        else
            for(int j=0;j<n;j++) puts(s[j]);
    }
    return 0;
}