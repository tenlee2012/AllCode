#include <stdio.h>
#include <iostream>

static int num = 0;

class A {
private:
    int a;
    char s[100];
public:
    A() {
        printf("constor\n");
        a = 20;
    }
    A(int a) {
        this->a = a;
    }
    void setA(int a) {
        this->a = a;
    }
    void getA() {
        printf("%d\n", this->a);
    }
    ~A() {
        printf("destory %d\n", ++num);
    }
};

int main() {
    A a(10);
    a.setA(1);
    a.getA();
    A *as = new A[10];
    as[1].getA();
    delete[] as;
    return 0;
}
