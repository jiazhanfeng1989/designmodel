#include <iostream>
#include <memory>

using namespace std;
class IProduct
{
public:
    IProduct() = default;
    virtual ~IProduct() = default;

    virtual void produce() = 0;
};

class CProduct1:public IProduct
{
public:
    CProduct1() {cout << "CProduct1" << endl;}
    virtual ~CProduct1() {cout << "~CProduct1" << endl;}
    virtual void produce(){cout << "produce CProduct1" << endl;}
};

class CProduct2:public IProduct
{
public:
    CProduct2() {cout << "CProduct2" << endl;}
    virtual ~CProduct2() {cout << "~CProduct2" << endl;}
    virtual void produce(){cout << "produce CProduct2" << endl;}
};

class Factory
{
public:
    Factory() = default;
    ~Factory() = default;

    unique_ptr<IProduct> CreateProduct(const std::string& productname);
};

unique_ptr<IProduct> Factory::CreateProduct(const std::string& productname)
{
    if (productname == "Product1")
    {
        return unique_ptr<IProduct>(new CProduct1);
    }
    else if (productname == "Product2")
    {
        return unique_ptr<IProduct>(new CProduct2);
    }

    return unique_ptr<IProduct>(nullptr);
}


int main()
{
    Factory myfactory;

    unique_ptr<IProduct> product1 = myfactory.CreateProduct("Product1");
    product1->produce();

    unique_ptr<IProduct> product2 = myfactory.CreateProduct("Product2");
    product2->produce();

    unique_ptr<IProduct> errproduct = myfactory.CreateProduct("Product3");

    return 0;
}
