#include "MySingleton.h"
#include <iostream>

using namespace std;

std::unique_ptr<MySingleton> MySingleton::instance;
std::once_flag MySingleton::initInstanceFlag;

MySingleton::MySingleton()
{
    cout << "MySingleton" <<endl;
}

MySingleton::~MySingleton()
{
    cout << "~MySingleton" <<endl;
}

void MySingleton::test(const std::string& msg)
{
    cout << msg << endl;
}

std::unique_ptr<MySingleton>& MySingleton::getInstance()
{
    std::call_once(initInstanceFlag, &MySingleton::initSingleton);
    return instance;
}

void MySingleton::initSingleton()
{
    instance.reset(new MySingleton);
}
