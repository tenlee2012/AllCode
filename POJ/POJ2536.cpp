#include <iostream>
#include <cstring>
using namespace std;
 
const int MAX = 300;
 
struct coordinate
{
    double x,y;
};
 
coordinate gopher[MAX];
coordinate holes[MAX];
 
bool arcs[MAX][MAX];
bool isvisit[MAX];
int match[MAX];
int n, m, s, v;
 
bool find(int u)
{
    for (int i = 1; i <= m; i++)
        if (arcs[u][i] && !isvisit[i])
        {
            isvisit[i] = true;
            if (!match[i] || find(match[i]))
            {
                match[i] = u;
                return true;
            }
        }
 
    return false;
}
 
int main()
{
    while (cin >> n >> m >> s >> v)
    {
        double d = s*v*s*v;
        for (int i = 0; i < n; i++)
            cin >> gopher[i].x >> gopher[i].y;
 
        for (int i = 0; i < m; i++)
            cin >> holes[i].x >> holes[i].y;
 
        memset(arcs, false, sizeof(arcs));
        memset(match, 0, sizeof(match));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if ((holes[j].x - gopher[i].x)*(holes[j].x - gopher[i].x) + (holes[j].y - gopher[i].y)*(holes[j].y - gopher[i].y) <= d)
                    arcs[i+1][j+1] = true;
 
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            memset(isvisit, false, sizeof(isvisit));
            if (find(i))
                ans++;
        }
 
        cout << n - ans << endl;
    }
    return 0;
}
