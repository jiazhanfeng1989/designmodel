#include <iostream>
#include <thread>
#include "MySingleton.h"

using namespace std;
void test1()
{
     MySingleton::getInstance()->test("test1");
}

void test2()
{
    MySingleton::getInstance()->test("test2");
}

int main()
{
    thread t1(test1);
    thread t2(test2);

    t1.join();
    t2.join();
    return 0;
}
