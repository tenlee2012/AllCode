#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

#define maxn  200005
struct Tree
{
    int left, rignt, num;
}node[maxn << 2];

int f;

void BuildTree(int i, int num, int l, int r);

void Update(int i, int num);

int main()
{
    int h, w, q;
    while(~scanf("%d %d %d", &h, &w, &q))
    {
        int n = h < q ? h :q;

        BuildTree(1, w, 1, n);
        while(q--)
        {
            int len;
            f = 0;
            scanf("%d", &len);
            Update(1, len);
            if(f) printf("%d\n", f);
            else printf("-1\n");
        }
    }
    return 0;
}

void BuildTree(int i, int num, int l, int r)
{
    node[i].left = l;
    node[i].rignt = r;
    node[i].num = num;
    if(l == r) return;
    int mid = (l + r) >> 1;
    BuildTree(i << 1, num, l, mid);
    BuildTree(i << 1 | 1, num, mid + 1, r);
}

void Update(int i, int num)
{
    //printf("i = %d\n", i);
    if(node[i].num < num) return;
    //if(f) return;
    if(node[i].left == node[i].rignt)
    {
        //printf("f = %d\n", f);
        f = node[i].left;
        node[i].num -= num;
        return;
    }
    Update(i << 1, num);
    if(!f) Update(i << 1 | 1, num);
    node[i].num = max(node[i << 1].num, node[i << 1 | 1].num);

}
