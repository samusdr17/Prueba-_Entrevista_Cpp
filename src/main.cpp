#include <iostream>
// =============================================================
// MAIN
// =============================================================
int main() {
    Module1 m1;
    Module2 m2;
    Module3 m3;

    m1.setNext(&m2);
    m2.setNext(&m3);

    m1.start();
    m2.start();
    m3.start();

    m1.join();
    m2.join();
    m3.join();

    return 0;
}