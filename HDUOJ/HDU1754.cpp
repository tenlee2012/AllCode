#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 200000 //区间,
#define MAX 10000
int Max = -1 << 20;
struct node
{
    int lchild, rchild;// 区间 [left,right]
    int num; // 结点对应区间的权值
} node[4 * maxn];

void BuildTree(int i, int l, int r)// 为区间[left,right]建立一个
//以i为祖先的线段树，i为数组下标，我称作结点序号
{
    node[i].lchild = l;// 写入第i个结点中的 左区间
    node[i].rchild = r;// 写入第i个结点中的 右区间
    node[i].num = 0;// 每个区间初始化为 0

    if (l == r) // 当区间长度为 0 时，结束递归
    {
        scanf("%d", &node[i].num);
        return;
    }

    int dou = i << 1, mid = (l + r) >> 1;// << 乘2, >> 除2
    BuildTree(dou, l, mid);
    BuildTree(dou | 1, mid + 1, r);
    node[i].num = node[dou].num > node[dou | 1].num ? node[dou].num : node[dou | 1].num;
}

void Update(int i, int num, int id)
{
    if (node[i].lchild == node[i].rchild)
    {
        node[i].num = num;
        return; //这个不加,非法内存访问
    }
    else
    {
        int dou = i << 1;

        if (id <= node[dou].rchild)
        {
            Update(dou, num, id);
        }
        else
        {
            Update(dou | 1, num, id);
        }
        node[i].num = node[dou].num > node[dou | 1].num ? node[dou].num : node[dou | 1].num;
    }
}
int Query(int i, int l, int r)
{
    if (node[i].lchild == l && node[i].rchild == r)
    {
        return node[i].num;
    }

    int mid = (node[i].lchild + node[i].rchild) >> 1,
        dou = i << 1;
    if (l > mid)
    {
        return Query(dou + 1, l, r);
    }
    else if (r <= mid)
    {
        return Query(dou, l, r);
    }
    else
    {
        int a = Query(dou, l, mid), b = Query(dou | 1 , mid + 1, r);
        return a > b ? a : b;
    }
}

int main()
{
    int m, n, a, b;
    char c;
    while(~scanf("%d %d", &n, &m))
    {
        BuildTree(1, 1, n);
        while(m--)
        {
            scanf(" %c %d %d", &c, &a, &b);
            //printf("%c\n", c);
            if(c == 'Q')
            {
                printf("%d\n", Query(1, a, b));
            }
            else if(c == 'U')
            {
                Update(1, b, a);
            }
            /*printf("Debug ");
            while(scanf("%d", &a) && a != -1)
            {
                printf("%d   ", node[a].num);
            }
            printf("End\n");*/
        }
        //printf("haha");
    }
    return 0;
}
