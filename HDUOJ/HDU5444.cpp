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

struct Node
{
    int data, flag;
    Node *lchild, *rchild;
}node, tree;

bool Search(Node *T, int key)
{
    Node *p = T;
    while(p)
    {
        if(p->data == key) return true;
        if(key < p->data)
        {
            printf("E");
            p = p->lchild;
        }
        else
        {
            printf("W");
            p = p->rchild;
        }
    }
    return false;
}
Node* Insert(Node *T, int key)
{
    Node *f = T, *p = T;
    while(p)
    {
        if(p->data == key) return T;
        f = p;
        p = (key < p->data) ? p->lchild : p->rchild;
    }
    p = (Node*)malloc(sizeof(Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(T == NULL)
    {
        T = p;
    }
    else if(key < f->data)
    {
        f->lchild = p;
    }
    else
        f->rchild = p;
    return T;
}
void Des(Node *T)
{
    if(T)
    {
        if(T->lchild)
            Des(T->lchild);
        if(T->rchild)
            Des(T->rchild);
        free(T);
        T = NULL;
    }
}
int main()
{
    int tt, n, q, x;
    scanf("%d", &tt);
    Node *tree = NULL;
    while(tt--)
    {
        tree = NULL;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            tree = Insert(tree, x);
        }
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d", &x);
            Search(tree, x);
            puts("");
        }
        //Des(tree);
    }
    return 0;
}
