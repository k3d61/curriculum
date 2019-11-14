#include <iostream>
#include <vector>
namespace {
    void test1() {
        using namespace std;
        cout << "test1" << endl;
    }
}

void test2() {
    test1();
}