#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std ;

const int N = 1e2 + 11 ;

int n , m , p , q ;
char ms[N] ;
int mlen ;
string ss = "anniversary";
string str ;

bool work(){
    str = ms ;
    mlen = ss.length() ;
    for(int i = 1 ; i < mlen ; ++i) {
        for(int j = i+1 ; j < mlen ; ++j) {
                string s1 = ss.substr(0 , i) ;
                string s2 = ss.substr(i , j-i) ;
                string s3 = ss.substr(j , mlen-j) ;
                int a1 = (int)str.find(s1) ;
                if(a1 == -1) continue ;
                   int b1 = (int)str.find(s2 , a1+s1.length()) ;
                if(b1 == -1) continue ;
                int c1 = (int)str.find(s3 , b1+s2.length()) ;
                if(c1 == -1) continue ;
                return true ;
        }
    }
    return false ;
}

int main() {
    int t ;
    //freopen("data.in" , "r" ,stdin);
    scanf("%d" , &t) ;
    while(t--) {
        scanf("%s" , ms) ;
        if(work()) printf("YES\n") ;
        else printf("NO\n") ;
    }
}