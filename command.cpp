#include <iostream>
#include <memory>
using namespace std;

class ICommand
{
public:
    ICommand() = default;
    virtual ~ICommand() = default;

    virtual void execute() = 0;
};

class CRequireCommand :public ICommand
{
public:
    CRequireCommand() = default;
    virtual ~CRequireCommand() = default;

    virtual void execute(){cout << "do require" << endl;}
};

class CProcessCommand:public ICommand
{
public:
    CProcessCommand() = default;
    virtual ~CProcessCommand() = default;

    virtual void execute(){cout << "do process" << endl;}
};

class Invoke
{
public:
    Invoke() = default;
    ~Invoke() = default;
    void setcommand(unique_ptr<ICommand>&& command) {m_command = std::move(command);}

    void action(){m_command->execute();}
private:
    unique_ptr<ICommand> m_command;
};

int main()
{
  Invoke myinvoke;

  unique_ptr<ICommand> require(new CRequireCommand);
  myinvoke.setcommand(std::move(require));
  myinvoke.action();

  unique_ptr<ICommand> process(new CProcessCommand);
  myinvoke.setcommand(std::move(process));
  myinvoke.action();
}
