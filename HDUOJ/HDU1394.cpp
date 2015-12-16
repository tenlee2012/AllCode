#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

#define manx 5005
struct Tree
{
    int left; 
    int right;
    int num; //该区间内，已经出现的个数
}tree[4 * manx];
int a[manx];

void BuildTree(int i, int l, int r);
void Update(int i, int id);
int Query(int i, int l, int r);

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int ans = 0;
        BuildTree(1, 1, n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            Update(1, a[i] + 1);
            ans += Query(1, a[i] + 2, n);//询问比他大区间已经出现的次数
            //printf("ans = %d\n", ans);
        }
        int m = ans;
        for(int i = 0; i < n; i++)
        {
            m = m + n - 2 * a[i] - 1;
            if(m < ans)
                ans = m;
        }
        printf("%d\n", ans);
    }
    return 0;
}

void BuildTree(int i, int l, int r)//建树
{
    tree[i].left = l;
    tree[i].right = r;
    tree[i].num = 0;//初始化全部为0,因为还没有输入
    if(tree[i].left == tree[i].right) return;
    int mid = (l + r) >> 1;
    BuildTree(i << 1, l, mid);
    BuildTree(i << 1 | 1, mid + 1, r);
}

void Update(int i, int id)//更新
{
    if(tree[i].left == id && tree[i].right == id)
    {
        tree[i].num = 1;//输入过了,标记为1
        return;
    }
    int mid = (tree[i].left + tree[i].right) >> 1;
    if(id > mid)  Update(i << 1 | 1, id);
    else   Update(i << 1, id);
    tree[i].num = tree[i << 1].num + tree[i << 1 | 1].num;//更新此区间内,已经出现过的总数
}

int Query(int i, int l, int r)//询问该区间已经出现的次数
{
    //printf("%d %d %d\n", i, l, r);
    if(l > r) return 0;
    if(tree[i].left == l && tree[i].right == r) return tree[i].num;
    int mid = (tree[i].left + tree[i].right) >> 1;

    if(r <= mid) return Query(i << 1, l, r);
    else if(l > mid) return Query(i << 1 | 1, l, r);
    else return Query(i << 1, l, mid) + Query(i << 1 | 1, mid + 1, r);
}                                                        //这里是mid+1
