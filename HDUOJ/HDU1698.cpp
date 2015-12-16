#include <stdio.h>
#include <iostream>
using namespace std;

#define maxn 100005
struct Tree
{
    int left, right, num; //num 为 -1,表示这个区间内不纯
}node[4 * maxn];

void BuildTree(int i, int l, int r);

void Update(int i, int num, int l, int r);

int Search(int i);

int main()
{
    int t, num, n, m, k = 0, l, r;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        BuildTree(1, 1, n);
        while(m--)
        {
            scanf("%d %d %d", &l, &r, &num);
            Update(1, num, l, r);
        }
        printf("Case %d: The total value of the hook is %d.\n", ++k, Search(1));
    }
    return 0;
}

void BuildTree(int i, int l, int r)
{
    node[i].left = l;
    node[i].right = r;
    node[i].num = 1; //初始化每个区间都是 纯1 的;
    if(node[i].left == node[i].right) return;

    int mid = (node[i].left + node[i].right) >> 1;
    BuildTree(i << 1, l, mid);
    BuildTree(i << 1 | 1, mid + 1, r);
}

void Update(int i, int num, int l, int r)
{
    if(node[i].num == num) return;
    if(node[i].left == l && node[i].right == r)
    {
        node[i].num = num;
        return;
    }
    if(node[i].num != -1)//这段区间是 纯 的,我们要修改这个区间,则这个区间就不 纯了
    {
        node[i << 1].num = node[i << 1 | 1].num = node[i].num;
        node[i].num = -1;//这个区间不纯了
    }
    int mid = (node[i].left + node[i].right) / 2;
    if(r <= mid) Update(i << 1, num, l, r);
    else if(l > mid) Update(i << 1 | 1, num ,l, r);
    else
    {
        Update(i << 1, num, l, mid);
        Update(i << 1 | 1, num, mid + 1, r);
    }
}
int Search(int i)
{
    if(node[i].num != -1) //即这段区间是纯的, 则不需要向下查询,直接根据线段树的特点算出
    {
        return node[i].num * (node[i].right - node[i].left + 1);
    }
    else
        return Search(i << 1) + Search(i << 1 | 1);
}
/*
1
10
2
1 5 2
1 2 1 5
hehe2 2 1 5
5 9 3
1 3 5 9
2 3 5 5
hehe5 3 5 5
hehe11 3 5 5
3 3 6 9
hehe6 3 6 8
7 3 9 9
hehe14 3 9 9
1
2
4
5
10
11
3
6
7
14
15
Case 1: The total value of the hook is 24.

Process returned 0 (0x0)   execution time : 7.010 s
Press any key to continue.

*/
