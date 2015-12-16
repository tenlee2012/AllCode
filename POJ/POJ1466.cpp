#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

#define maxn 505
int nx, ny;
bool visit[maxn];
int match[maxn];
bool edge[maxn][maxn];

bool crosspath(int u)
{
	for(int i = 0; i < nx; i++)
	{
		if(edge[u][i] && !visit[i])
		{
			//printf("hehe\n");
			visit[i] = 1;
			if(match[i] == -1 || crosspath(match[i]))
			{
				match[i] = u;

				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int ans = 0;
	for(int i = 0; i < nx; i++)
	{
		memset(visit, false, sizeof(visit));
		if(crosspath(i))
		{
			printf("match %d\n", i);
			ans++;
		}
	}
	return ans;
}

int main()
{
	int t;
	while(~scanf("%d", &t))
	{
		nx = t;
		int x, y, z;
		for(int i = 0; i < nx; i++) match[i] = -1;
		while(t--)
		{
			scanf("%d: (%d)", &x, &y);
			for(int i = 0; i < y; i++)
			{
				scanf("%d", &z);
				printf("%d %d\n",x , z);
				edge[x][z] = true;
			}
		}
		printf("%d\n", nx - hungary());

	}
	return 0;
}
