#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

#define maxn 500
int nx, ny; //x �� y ���ϵĵ���
int edge[maxn][maxn];//edge[i][j]Ϊ1��ʾij����ƥ��
int match[maxn]; //��¼��V2�еĵ�ƥ��ĵ�ı��
bool flag, visit[maxn];//������¼�ö����Ƿ񱻷��ʹ���

bool crosspath(int u)
{
	int v;
	for(v = 1; v <= ny; v++)
	{
		if(edge[u][v] && !visit[v])
		{
			visit[v] = 1;
			if(match[v] == -1 || crosspath(match[v]))
			{
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int ans = 0;
	for(int i = 1; i <= nx; i++)
	{
		memset(visit, false, sizeof(visit));
		if(crosspath(i))
		{
			ans++;
		}
	}
	return ans;
}

int main()
{
	int t, k, v;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &nx, &ny);
		for(int i = 1; i <= nx; i++)
		{
			for(int j = 1; j <= ny; j++)
			{
				match[j] = -1;
				edge[i][j] = 0;
			}
		}

		flag = true;
		for(int i = 1; i <= nx; i++)
		{
			scanf("%d", &k);
			if(k == 0) flag = false;
			while(k--)
			{
				scanf("%d", &v);
				edge[i][v] = 1;
			}
		}
		if(flag)
			if(hungary() == nx)
				puts("YES");
			else
				puts("NO");
		else
			puts("NO");
	}
	return 0;
}
