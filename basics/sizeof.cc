#include <iostream>
using namespace std;

class A {
};

class B {
    public:
        B(){};
        ~B(){};
};

class C {
    public:
        C(){};
        virtual ~C(){};
};

int main(){
    A a;
    B b;
    C c;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    cout << sizeof(int) << endl;
    return 0;
}
