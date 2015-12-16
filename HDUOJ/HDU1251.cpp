#include <iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
struct tree
{
    int num;
    tree * next[26];
} trie;

tree root;

void creat(char * s);
int  find(char * s);
int main()
{
    for (int i = 0; i < 26; ++i)
    {
        root.next[i] = NULL;
    }
    char s[15], ss[15];

    while (gets(s) && s[0] != '\0')
    {
        creat(s);
    }

    while (gets(ss) && ss[0] != '\0')
    {
        printf("%d\n", find(ss));
    }

    return 0;
}

void creat(char * s)
{
    int len = strlen(s);
    tree * x = &root, *y;

    for (int i = 0; i < len; i++)
    {
        int id = s[i] - 'a';

        if (x->next[id] == NULL)
        {
            y = (tree *)malloc(sizeof(root));
            y->num = 1;

            for (int j = 0; j < 26; j++)
            {
                y->next[j] = NULL;
            }
            x->next[id] = y;
            x = x->next[id];
        }
        else
        {
            x->next[id]->num++;
            x = x->next[id];
        }
    }
}

int find(char * s)
{
    int n = strlen(s);
    tree * x = &root;

    for (int i = 0; i < n; i++)
    {
        int id = s[i] - 'a';
        x = x->next[id];

        if (x == NULL)
        {
            return 0;
        }
    }

    return x->num;
}
