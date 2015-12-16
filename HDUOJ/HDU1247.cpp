// hdu 1247 hat's word
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

char str[50005][50];
int flag = 0;
typedef struct TREE
{
    int end;
    TREE * next[26];
    TREE ()
    {
        end = 0;
        memset(next,0,sizeof(next));
    }
}trie;

TREE *root;

void creat(char * s)
{
    int len = strlen(s);
    TREE * x = root;

    for (int i = 0; i < len; i++)
    {
        int id = s[i] - 'a';

        if (x->next[id] == NULL)
            x->next[id] = new TREE();
        x = x->next[id];
    }
    x->end = 1;
}

int find1(char *s)
{
    //printf("%s\n",s);
    TREE * x = root;
    int id;
    for (int i = 0; s[i]; i++)
    {
        id = s[i] - 'a';
        if(x->next[id] == NULL)
        {
            flag = 0;
            return 0;
        }
        x = x->next[id];
    }
    if(x->end == 1) return 1;
    else return 0;
}

void find(char * s)
{
    flag = 0;
    TREE * x = root;
    char ss[50] = "\0";
    for (int i = 0;s[i]; i++)
    {
        int id = s[i] - 'a';
        x = x->next[id];
        if(x->end == 1 && s[i+1]!='\0')
        {
            strcpy(ss,&s[i+1]);
            //printf("%s##%",s);
            flag = find1(ss);
            if(flag) return;
        }
    }
    return;
}

int main()
{
    //freopen("1.in","r",stdin);
    root = new TREE();
    int i=0,j;
    while(gets(str[i]) && str[i][0] != '\0')
    {
       creat(str[i]);
       i++;
    }

    for(j=0;j<i;j++)
    {
        if(strlen(str[j])<2) continue;
        find(str[j]);
        if(flag)
            printf("%s\n", str[j]);
    }
    return 0;
}
