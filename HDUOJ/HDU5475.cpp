#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
 
#define manx 100005
struct Tree
{
    int left;
    int right;
    long long num; //该区间内，已经出现的个数
}tree[4 * manx];
int a[manx], n, m;
 
void BuildTree(int i, int l, int r);
void Update(int i, int id, int val);
int Query(int i, int l, int r);
 
int main()
{
    int T, x, y;
    scanf("%d", &T);
    for(int tt = 1; tt <= T; tt++)
    {
        scanf("%d %d", &n, &m);
        BuildTree(1, 1, n);
        printf("Case #%d:\n", tt);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d", &x, &y);
            if(x == 1)
            {
                Update(1, i, y);
                printf("%lld\n", tree[1].num);
            }
            else
            {
                Update(1, y, 1);
                printf("%lld\n", tree[1].num);
            }
        }
    }
    return 0;
}
 
void BuildTree(int i, int l, int r)//建树
{
    tree[i].left = l;
    tree[i].right = r;
    tree[i].num = 1;//初始化全部为0,因为还没有输入
    if(tree[i].left == tree[i].right) return;
    int mid = (l + r) >> 1;
    BuildTree(i << 1, l, mid);
    BuildTree(i << 1 | 1, mid + 1, r);
}
 
void Update(int i, int id, int val)//更新
{
    if(tree[i].left == id && tree[i].right == id)
    {
        tree[i].num = val;//输入过了,标记为1
        return;
    }
    int mid = (tree[i].left + tree[i].right) >> 1;
    if(id > mid)  Update(i << 1 | 1, id, val);
    else   Update(i << 1, id, val);
    tree[i].num = (tree[i << 1].num * tree[i << 1 | 1].num) % m;//更新此区间内,已经出现过的总数
}
