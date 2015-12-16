#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
const int maxn = 5843;
long long table[maxn] = {0,1,2,3,4,5,6,7,8,9,10,12,14,15,16,18,20,21,24,25,27};
int hehe[4] = {2,3,5,7};
void make_table()
{
    int i,j,k;
    for(i = 21; i < maxn; i++)
    {
        table[i] = 2*table[i-1];
        for(j = i - 2; j >=1; j--)
            if(table[j]*7 <= table[i-1])
                break;
            else
                for(k = 3; k >= 0; k--)
                    if(table[j]*hehe[k] > table[i-1] && table[j]*hehe[k] < table[i])
                        table[i] = table[j]*hehe[k];
    }
}
int main()
{
    int n;
    make_table();
    while(cin >> n && n)
    {
        int gewei = n%10;
        cout << "The " << n;
        if(n%100 == 11 || n%100 == 12 || n%100 ==13)
        {
            cout << "th humble number is " << table[n] << "." << endl;
            continue;
        }
        switch(gewei)
        {
        case 1:cout << "st humble number is " << table[n] << "." << endl;
           break;
        case 2:cout << "nd humble number is " << table[n] << "." << endl;
            break;
        case 3:cout << "rd humble number is " << table[n] << "." << endl;
            break;
        default:cout << "th humble number is " << table[n] << "." << endl;
            break;
        }
    }
    return 0;
}

