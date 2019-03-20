#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <string>

using namespace std;
class MySingleton
{
public:
    static std::unique_ptr<MySingleton>& getInstance();
    ~MySingleton();

    void test(const std::string& msg);

private:
    MySingleton();
	MySingleton(const MySingleton&) = delete;
	MySingleton& operator=(const MySingleton&) = delete;
    static void initSingleton();
	static std::unique_ptr<MySingleton> instance;
	static std::once_flag initInstanceFlag;
};

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
