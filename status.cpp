#include <iostream>
using namespace std;
class Context;
class CloseStatus;
class OpenStatus;
class RunStatus;
class StopStatus;

class ILiftStatus
{
public:
enum enStatus
{
    RUNSTATUS,
    STOPSTATUS,
    OPENSTATUS,
    CLOSESTATUS
};

public:
    ILiftStatus() = default;
    virtual ~ILiftStatus() = default;
    void setcontext(Context * pcontext) {mycontext = pcontext;}

    virtual void run() = 0;
    virtual void stop() = 0;
    virtual void open() = 0;
    virtual void close() = 0;

protected:
    Context* mycontext;
};

class Context
{
public:
    Context();
    ~Context();

    void setliftStatus(ILiftStatus::enStatus status);
    ILiftStatus* getliftStatus(){return myLiftStatus;}

private:
    ILiftStatus* myLiftStatus;

    ILiftStatus* myCloseStatus;
    ILiftStatus* myOpenStatus;
    ILiftStatus* myRunStatus;
    ILiftStatus* myStopStatus;
};

class CloseStatus:public ILiftStatus
{
public:
    CloseStatus() = default;
    ~CloseStatus() = default;

    virtual void run()
    {
        mycontext->setliftStatus(ILiftStatus::RUNSTATUS);
        mycontext->getliftStatus()->run();
    }

    virtual void stop()
    {
        mycontext->setliftStatus(ILiftStatus::STOPSTATUS);
        mycontext->getliftStatus()->stop();
    }

    virtual void close()
    {
        cout << "lift close" << endl;
    }

    virtual void open()
    {
        mycontext->setliftStatus(ILiftStatus::OPENSTATUS);
        mycontext->getliftStatus()->open();
    }
};

class OpenStatus:public ILiftStatus
{
public:
    OpenStatus() = default;
    ~OpenStatus() = default;

    virtual void run()
    {
        mycontext->setliftStatus(ILiftStatus::RUNSTATUS);
        mycontext->getliftStatus()->run();
    }

    virtual void stop()
    {
        mycontext->setliftStatus(ILiftStatus::STOPSTATUS);
        mycontext->getliftStatus()->stop();
    }

    virtual void close()
    {
        mycontext->setliftStatus(ILiftStatus::CLOSESTATUS);
        mycontext->getliftStatus()->close();
    }

    virtual void open()
    {
        cout << "lift open" << endl;
    }
};

class RunStatus:public ILiftStatus
{
public:
    RunStatus() = default;
    ~RunStatus() = default;

    virtual void run()
    {
        cout << "lift run" << endl;
    }

    virtual void stop()
    {
        mycontext->setliftStatus(ILiftStatus::STOPSTATUS);
        mycontext->getliftStatus()->stop();
    }

    virtual void close()
    {
        mycontext->setliftStatus(ILiftStatus::CLOSESTATUS);
        mycontext->getliftStatus()->close();
    }

    virtual void open()
    {
        mycontext->setliftStatus(ILiftStatus::OPENSTATUS);
        mycontext->getliftStatus()->open();
    }
};

class StopStatus:public ILiftStatus
{
public:
    StopStatus() = default;
    ~StopStatus() = default;

    virtual void run()
    {
        mycontext->setliftStatus(ILiftStatus::RUNSTATUS);
        mycontext->getliftStatus()->run();
    }

    virtual void stop()
    {
        cout << "lift stop" << endl;
    }

    virtual void close()
    {
        mycontext->setliftStatus(ILiftStatus::CLOSESTATUS);
        mycontext->getliftStatus()->close();
    }

    virtual void open()
    {
        mycontext->setliftStatus(ILiftStatus::OPENSTATUS);
        mycontext->getliftStatus()->open();
    }
};

Context::Context()
{
    myCloseStatus = new CloseStatus();
    myOpenStatus = new OpenStatus();
    myRunStatus = new RunStatus();
    myStopStatus = new StopStatus();
}

Context::~Context()
{
    delete myCloseStatus;
    delete myOpenStatus;
    delete myRunStatus;
    delete myStopStatus;
}

void Context::setliftStatus(ILiftStatus::enStatus status)
{
    switch(status)
    {
    case ILiftStatus::CLOSESTATUS:
        myLiftStatus = myCloseStatus;
        break;
    case ILiftStatus::OPENSTATUS:
        myLiftStatus = myOpenStatus;
        break;

    case ILiftStatus::RUNSTATUS:
        myLiftStatus = myRunStatus;
        break;

    case ILiftStatus::STOPSTATUS:
        myLiftStatus = myStopStatus;
        break;
    }
}

int main()
{
    CloseStatus myclosestatus;
    Context mycontext;

    myclosestatus.setcontext(&mycontext);

    myclosestatus.run();
    myclosestatus.stop();
    myclosestatus.close();
    myclosestatus.open();

    return 0;
}
