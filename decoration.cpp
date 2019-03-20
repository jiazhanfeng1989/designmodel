#include <iostream>
#include <memory>
using namespace std;

class ISchooleReport
{
public:
    ISchooleReport() = default;
    virtual ~ISchooleReport() = default;

    virtual void report() = 0;
    virtual void sign() = 0;
};

class FourthReport:public ISchooleReport
{
public:
    FourthReport() = default;
    virtual ~FourthReport() = default;

    virtual void report()
    {
        cout << "this is fourth report" << endl;
    }
    virtual void sign()
    {
        cout << "sing fourth report" << endl;
    }
};

class DecorationSchoolReport:public ISchooleReport
{
public:
    DecorationSchoolReport(ISchooleReport* report):m_report(report)
    {

    }
    virtual ~DecorationSchoolReport() = default;

    virtual void report() {m_report->report();}
    virtual void sign(){m_report->sign();}

private:
    ISchooleReport* m_report;

};

class SortReport:public DecorationSchoolReport
{
public:
    SortReport(ISchooleReport* report):DecorationSchoolReport(report)
    {

    }
    virtual ~SortReport() = default;

    virtual void report()
    {
        DecorationSchoolReport::report();
        cout << "this is sort report" << endl;
    }

    virtual void sign()
    {
        DecorationSchoolReport::sign();
    }
};

class HighReport:public DecorationSchoolReport
{
public:
    HighReport(ISchooleReport* report):DecorationSchoolReport(report)
    {

    }
    ~HighReport() =  default;

    virtual void report()
    {
        DecorationSchoolReport::report();
        cout << "this is high report" << endl;
    }
    virtual void sign()
    {
        DecorationSchoolReport::sign();
    }
};

int main()
{
    ISchooleReport* myfourthreport = new FourthReport();
    ISchooleReport* myhighreport = new HighReport(myfourthreport);
    ISchooleReport* mysortreport = new SortReport(myhighreport);

    mysortreport->report();
    mysortreport->sign();
	
	delete myfourthreport;
	delete myhighreport;
	delete mysortreport;
}
