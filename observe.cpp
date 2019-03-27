#include <iostream>
#include <memory>
#include <map>
using namespace std;

class IObserve
{
public:
    IObserve(const std::string& name) {myname = name;};
    virtual ~IObserve() = default;
    virtual void update(const std::string& msg) = 0;
    std::string getname(){return myname;}

private:
    string myname;
};

class ObserveOne:public IObserve
{
public:
    ObserveOne():IObserve("observeone"){cout << "observeone" << endl;}
    virtual ~ObserveOne() {cout << "~observeone" << endl;};
    virtual void update(const std::string& msg)
    {
        cout << "observeone receive msg:" << msg << endl;
    }
};

class ObserveTwo:public IObserve
{
public:
    ObserveTwo():IObserve("observetwo"){cout << "observetwo" << endl;}
    virtual ~ObserveTwo() {cout << "~observetwo" << endl;}
    virtual void update(const std::string& msg)
    {
        cout << "observetwo receive msg:" << msg << endl;
    }
};


class Observeable
{
public:
    Observeable() = default;
    virtual ~Observeable() = default;

    void AddObserve(unique_ptr<IObserve>&& observe)
    {
        myobservermap[observe->getname()] = std::move(observe);
    }

    void DeleteObserve(const std::string& name)
    {
        myobservermap.erase(name);
    }

    void notifyall(const std::string& msg)
    {
        for(auto iter = myobservermap.begin(); iter != myobservermap.end(); iter++)
        {
            iter->second->update(msg);
        }
    }

    void dotest()
    {
        notifyall("dotest");
    }

private:
    std::map<std::string, unique_ptr<IObserve> > myobservermap;
};

int main()
{
    Observeable myobserverable;

    std::unique_ptr<IObserve> myIObeserveone(new ObserveOne());
    std::unique_ptr<IObserve> myIObeservetwo(new ObserveTwo());

    myobserverable.AddObserve(std::move(myIObeserveone));
    myobserverable.AddObserve(std::move(myIObeservetwo));

    myobserverable.dotest();

    myobserverable.DeleteObserve("observeone");
    myobserverable.DeleteObserve("observetwo");

    cout << "delete all" << endl;
}
