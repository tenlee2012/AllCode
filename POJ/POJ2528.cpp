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
const int maxn = 2e4+5;
const int maxm = 1e7+5;

struct Node
{
    int l, r;
    int num;
}tree[maxn << 2];

struct Post
{
    int l, r;
}post[maxn];

int ha[maxm], ans = 0, flag[maxn]; 

void BuildTree(int i, int l, int r);

void Update(int i, int num, int l, int r);

void PushDown(int i);

void Query(int i);

int main()
{
	int t, n, i, j, x, y;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);

		for(i = 1; i <= n; i++)
		{
			scanf("%d %d", &post[i].l, &post[i].r);
			flag[2*i-1] = post[i].l , flag[2*i] = post[i].r;
		}
		sort(flag + 1 , flag + 2*n + 1);
		j = 1;
		memset(ha, 0, sizeof(ha));
		for(i = 1; i <= 2 * n; i++)
		{
			if(!ha[flag[i]])
				ha[flag[i]] = j++;
		}

		BuildTree(1, 1, maxn);
		for(i = 1; i <= n; i++)
		{
		    x = ha[post[i].l];
		    y = ha[post[i].r];
			Update(1, i, x, y);
		}
		memset(ha, 0, sizeof(ha));
		ans = 0;
		Query(1);
		printf("%d\n", ans);
	}
}

void BuildTree(int i, int l, int r)
{
	tree[i].l = l;
	tree[i].r = r;
	tree[i].num = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	BuildTree(i << 1, l, mid);
	BuildTree(i << 1 | 1, mid + 1, r);
}

void Update(int i, int num, int l, int r)
{
	if(tree[i].l == l && tree[i].r == r)
	{
		tree[i].num = num;
		return;
	}
	if(tree[i].num != -1)
	{
		PushDown(i);
		tree[i].num = -1;
	}
	int mid = (tree[i].l + tree[i].r) >> 1;
	if(r <= mid) Update(i << 1, num, l, r);
	else if(l > mid) Update(i << 1 | 1, num, l, r);
	else
	{
		Update(i << 1, num, l, mid);
		Update(i << 1 | 1, num, mid + 1, r);
	}

}

void PushDown(int i)
{
	tree[i << 1].num = tree[i << 1 | 1].num = tree[i].num;
}

void Query(int i)
{
	if(tree[i].num != -1)
	{
		if(tree[i].num > 0 && ha[tree[i].num] == 0)
		{
			ha[tree[i].num] = 1;
			ans++;
		}
		return;
	}
	else
	{
		Query(i << 1);
		Query(i << 1 | 1);
	}
}
