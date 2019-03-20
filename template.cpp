#include <iostream>
#include <memory>
using namespace std;

class Base
{
public:
    Base() = default;
    virtual ~Base() = default;

    void run();
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void process()= 0;
};

void Base::run()
{
    start();
    process();
    stop();
}

class Driver:public Base
{
public:
    Driver(){cout << "Driver" << endl;}
    virtual ~Driver(){cout << "~Dirver" << endl;}

    virtual void start(){cout << "driver start" << endl;}
    virtual void stop(){cout <<"driver stop" <<endl;}
    virtual void process(){cout << "driver process"<<endl;}
};

int main()
{
  unique_ptr<Base> ptr(new Driver);

  ptr->run();
}
