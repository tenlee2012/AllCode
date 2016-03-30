//Author LJH
//www.cnblogs.com/tenlee
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;

struct Rect { //矩形的定义
    double l, r, h; //l是左下角的x坐标,r是右下角的x坐标,纵坐标
    int flag; //标记1代表底边, -1代表顶边
    Rect(){}
    Rect(double a, double b, double c, int d) : l(a), r(b), h(c), flag(d){}
}rect[maxn<<2]; //矩形的数组

struct Node { //线段树节点的定义
    int l, r, cover;
    double len;
    Node() {}
    Node(int a, int b, int c, double d) : l(a), r(b), cover(c), len(d){}
}tree[maxn<<2]; //定义线段树
double x[maxn<<2]; //所有横坐标值的定义

bool cmp(Rect A, Rect B) {
    return A.h < B.h;
}

//二分查找
int binary_search(double key, int low, int high) {
    int mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(x[mid] > key) high = mid - 1;
        else if(x[mid] < key) low = mid + 1;
        else return mid;
    }
    return -1; //没有找到
}

//线段树建树
void Build(int i, int l, int r) {
    tree[i] = Node(l, r, 0, 0);
    if(l == r) return;
    int mid = (l + r) / 2;
    Build(i<<1, l, mid);
    Build(i<<1|1, mid+1, r);
}

//线段树向上更新
void PushUp(int i) {
    if(tree[i].cover) //非0,被整段覆盖
        tree[i].len = x[tree[i].r+1] - x[tree[i].l];
    else if(tree[i].l == tree[i].r) //不是线段
        tree[i].len = 0;
    else
        tree[i].len = tree[i<<1].len + tree[i<<1|1].len;
}

//线段树的更新
void Update(int i, int l, int r, int val) {
    if(tree[i].l == l && tree[i].r == r) {
        tree[i].cover += val;
        PushUp(i);
        return;
    }
    int mid = (tree[i].l + tree[i].r) >> 1;
    if(r <= mid) {
        Update(i<<1, l, r, val);
    }
    else if(l > mid) {
        Update(i<<1|1, l, r, val);
    }
    else {
        Update(i<<1, l, mid, val);
        Update(i<<1|1, mid+1, r, val);
    }
    PushUp(i);
}

int main() {
    int n; 
    while(~scanf("%d", &n) && n) { //输入n代表矩形的个数
        int m = 0;
        for(int i = 0; i < n; i++) {
            double x1, y1, x2, y2;
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            x[m] = x1;
            rect[m++] = Rect(x1, x2, y1, 1);
            x[m] = x2;
            rect[m++] = Rect(x1, x2, y2, -1);
        }
        sort(x, x+m); //把x坐标升序排序
        sort(rect, rect+m, cmp); //横线,按照纵坐标升序排序
        int k = 1;
        for(int i = 1; i < m; i++) { //去重
            if(x[i] != x[i-1])
                x[k++] = x[i];
        }
        Build(1, 0, k-1); //建树
        double sum = 0;
        for(int i = 0; i < m-1; i++) {
            int l = binary_search(rect[i].l, 0, k-1);
            int r = binary_search(rect[i].r, 0, k-1) - 1;
            //因为离散化了,所以需要根据矩形的l,r找到对应x数组的下标
            Update(1, l, r, rect[i].flag);
            sum += (rect[i+1].h - rect[i].h) * tree[1].len;
        }
        printf("sum = %f\n", sum);
    }
    return 0;
}
// 测试样例 1
// 1
// 0 0 1 1
// 1
// 测试样例 2
// 2
// 0 0 2 2
// 1 0 3 2
// 6
// 测试样例 3
// 2
// 0 0 2 2
// 1 1 3 3
// 7
// 测试样例 4
// 2
// 0 0 2 2
// 0 0 2 2
// 4
