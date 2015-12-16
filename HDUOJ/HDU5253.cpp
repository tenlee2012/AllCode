#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std ;

typedef long long LL ;
const int INF = 0x3f3f3f3f ;
const int dir[4][2] = {{-1 , 0} , {0 , 1} , {1 , 0} , {0 , -1}} ;
const int N = 1e3 + 11 ;

int arr[1011][1011] ;
bool vis[N][N] ;
int n , m;

struct Node {
    int x , y ;
    int d ;

    Node(){}
    Node(int a , int b , int c) {
        x = a , y = b , d = c ;
    }

    friend bool operator<(const Node&a , const Node& b) {
        return a.d > b.d ;
    }
};



void init() {
    scanf("%d %d" ,&n ,&m) ;
    int cnt = 0 ;
    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 1 ; j <= m ; ++j) {
            scanf("%d" , &arr[i][j]) ;
        }
    }
}

bool at(int x , int y) {
    if(x < 1 || y < 1 || x > n || y > m || vis[x][y]) return false ;
    return true ;
}

void work() {
    memset(vis , 0 , sizeof(vis)) ;
    priority_queue<Node> que ;
    for(int i = 0 ; i < 4 ; ++i) {
        int x1 = 1 + dir[i][0] ;
        int y1 = 1 + dir[i][1] ;
        if(at(x1 , y1)) que.push(Node(x1 , y1 , abs(arr[x1][y1]-arr[1][1]))) ;
    }
    vis[1][1] = true ;
    LL ans = 0 ;
    while(!que.empty()) {
        Node fro = que.top() ; que.pop() ;
        if(vis[fro.x][fro.y]) continue ;
        vis[fro.x][fro.y] = true ;
        ans += fro.d ;
        for(int i = 0 ; i < 4 ; ++i) {
            int x1 = fro.x + dir[i][0] ;
            int y1 = fro.y + dir[i][1] ;
            if(at(x1 , y1)) que.push(Node(x1 , y1 , abs(arr[x1][y1]-arr[fro.x][fro.y]))) ;
        }
    }
    printf("%I64d\n" , ans) ;
}

int main() {
    //freopen("data.in", "r", stdin) ;
    int t , tt = 0 ;
    scanf("%d" ,&t) ;
    while(t--) {
        printf("Case #%d:\n" , ++tt) ;
        init() ;
        work() ;
    }
}