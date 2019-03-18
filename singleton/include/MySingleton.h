#ifndef MYSINGLETON_H
#define MYSINGLETON_H
#include <mutex>
#include <memory>
#include <string>
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

#endif // MYSINGLETON_H
