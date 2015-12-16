#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int m,n;
char map[105][105];
int visit[105][105];
int dir[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1}};
int net[6];       //dfs的标记数组
int min_sum;      
int jnum;        //包起点的总珠宝数
int jcount;      //珠宝数
int dist[6][6];
struct node{
    int x;
    int y;
    int number;     //序号，其中贼起点为0
    int step;       //求路径长度时的步数
}jerry[6];
bool inmap(int x,int y){
    if(x >= 1 && x <= n)
        if( y >=1 && y <= m)
            return true;
    return false;
}
void dfs(int index,int sum,int count){
    if(count == jcount){
        if(sum < min_sum)
            min_sum = sum;
        return;
    }
    for(int i=1;i<jnum;i++){
        if(!net[i]){
            net[i] = 1;
            dfs(i,sum+dist[index][i],count+1);
            net[i] = 0;
        }
    }
    return;
}

int bfs(struct node s,struct node e){
    queue<struct node> q;
    int tx,ty;
    struct node temp,cur;
    while(!q.empty())
        q.pop();
    q.push(s);
    visit[s.x][s.y] = 1;
    if(s.x == e.x && s.y== e.y)return 0;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            tx = cur.x + dir[i][0];
            ty = cur.y + dir[i][1];
            temp.x = tx;
            temp.y = ty;
            temp.step = cur.step + 1;
            if( !visit[tx][ty] && inmap(tx,ty) && map[tx][ty] != '#' ){
                visit[tx][ty] = 1;
                if(tx == e.x && ty == e.y){
                    return temp.step;
                }
                q.push(temp);
             }
        }
    }
    return -1;
}
int main()
{
    int i,j,k,tx,ty,flag;
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    while(scanf("%d%d",&n,&m)!=EOF,m+n){
        getchar();
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%c",&map[i][j]);
                if(map[i][j] =='@'){
                    jerry[0].x = i;
                    jerry[0].y = j;
                    jerry[0].number = 0;
                }
            }
            getchar();
        }
        scanf("%d",&jcount);
        for(i=1;i<=jcount;i++){
            scanf("%d%d",&jerry[i].x,&jerry[i].y);
            jerry[i].number = i;
        }
        jnum = jcount+1;
        flag = 0;
        for(i=0;i<jnum;i++){
            for(j=i+1;j<jnum;j++){
                memset(visit,0,sizeof(visit));
                dist[i][j] = dist[j][i] = bfs(jerry[i],jerry[j]);
                if(dist[i][j] == -1){
                    flag = 1;
                    break;
               }
            }
        }
        if(flag == 1){
            printf("-1\n");
        }
        else{
            min_sum = 1<<20;
            memset(net,0,sizeof(net));
            net[0] = 1;
            dfs(0,0,0);
            printf("%d\n",min_sum);
        }
    }
    return 0;
}
