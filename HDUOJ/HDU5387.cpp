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
const int maxn = 1e6+5;
const int kuo = 360;

int hh, mm, ss;

int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b, a%b);
}

void slove()
{
    int aS = ss * 6 * kuo;
    int aM = mm * 6 * kuo + kuo * 6 * ss / 60;
    int aH = hh * 30 * kuo + 30 * aM / 360;
    int cHS, cHM, cMS;
    int f1 = kuo * 360, f2 = 180 * kuo;
    int g;

    if(aS > aH) cHS = aS - aH;
    else cHS = aH - aS;
    if(cHS >= f2) cHS = f1 - cHS;

    if(aM > aH) cHM = aM - aH;
    else cHM = aH - aM;
    if(cHM >= f2) cHM = f1 - cHM;

    if(aM > aS) cMS = aM - aS;
    else cMS = aS - aM;
    if(cMS >= f2) cMS = f1 - cMS;

    if(cHM % kuo == 0) printf("%d ", cHM / kuo);
    else 
    {
        g = gcd(cHM, kuo);
        printf("%d/%d ", cHM/g, 360/g);
    }        
    if(cHS % kuo == 0) printf("%d ", cHS / kuo);
    else 
    {
        g = gcd(cHS, kuo);
        printf("%d/%d ", cHS/g, 360/g);
    }    
    if(cMS % kuo == 0) printf("%d \n", cMS / kuo);
    else 
    {
        g = gcd(cMS, kuo);
        printf("%d/%d \n", cMS/g, 360/g);
    }    

}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        if(hh >= 12) hh -= 12;
        slove();
    }
    return 0;
}

