    #include <iostream>  
    #include <cstdio>  
    #include <cstring>  
    #include <algorithm>  
    typedef __int64 ll;  
    using namespace std;  
      
    int main() {  
        int n;  
        while (scanf("%d", &n) != EOF) {  
            ll ans = 0;  
            ll tmp;  
            for (int i = 0; i < n; i++) {  
                scanf("%I64d", &tmp);  
                ans ^= tmp;  
            }  
            if (ans == 0)  
                printf("Lose\n");  
            else printf("Win\n");  
        }     
    }  