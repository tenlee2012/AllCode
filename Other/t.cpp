#include <stdio.h>
#include <math.h>

bool is_prime(int num) {
    for(int i = 2; i <= (int)sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    for(int i = 0; i < 1000; i++) {
        if(is_prime(i)) {
            printf("%d ", i);
        }
    }
}
