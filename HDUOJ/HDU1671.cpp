#include <stdio.h>
#include <algorithm>
#include <iostream>
#include<cstring>
using namespace std;
#define  MAX    10
int flag = 0;
typedef struct TrieNode
{
    int nEndFlag; //标记该字符是否是某一字符串的结尾
    TrieNode * next[MAX];
} TrieNode;

TrieNode Memory[1000000];
int allocp = 0 , nFlag = 0;

void InitTrieRoot(TrieNode ** pRoot)
{
    *pRoot = NULL;
}

TrieNode * CreateTrieNode()
{
    int i;
    TrieNode * p;

    p = &Memory[allocp++];
    p->nEndFlag = 0;

    for (i = 0 ; i < MAX ; i++)
    {
        p->next[i] = NULL;
    }

    return p;
}

void InsertTrie(TrieNode ** pRoot , char * s)
{
    int i , k;
    TrieNode * p;

    if (!(p = *pRoot))
    {
        p = *pRoot = CreateTrieNode();
    }

    i = 0;

    while (s[i])
    {
        k = s[i++] - '0';
        if (!(p->next[k]))
        {
            p->next[k] = CreateTrieNode();
        }
        p = p->next[k];
        if(p->nEndFlag)
        {
            flag = 1;
            return;
        }
    }
    p->nEndFlag = 1;  //标记结尾
}
struct Code
{
    int len;
    char num[15];
}code[10005];

bool cmp(Code a, Code b)
{
    return a.len < b.len;
}
int main()
{
    //freopen("1.in","r",stdin);
    int  t, n;
    TrieNode  *root;
    cin >> t;

    while (t--)
    {
        nFlag = allocp = 0;
        InitTrieRoot(&root);
        int i = 0;
        cin >> n;
        getchar();

        while (n--)
        {
            gets(code[i].num);
            code[i].len = strlen(code[i].num);
            i++;
        }
        sort(code, code + i, cmp);
        for (int j = 0; j < i; j++)
        {
            InsertTrie(&root,code[j].num);
        }
        if (flag)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }

        flag = 0;
    }
    return 0;
}
