#include <iostream>
#include <fstream>

// Интерфейс
class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print() = 0;
};

// Команды
class LogCommandToConsole : public LogCommand
{
    std::string message_;
public:
    LogCommandToConsole(const std::string& message) : message_(message) {};
    void print() 
    {
        std::cout << message_;
    }
};

class LogCommandToFile : public LogCommand
{
    std::string message_;
public:
    LogCommandToFile(const std::string& message) : message_(message) {};
    virtual void print()
    {
        std::ofstream file("log.txt");
        file << "log: " << message_ << "\n";
    }
    ~LogCommandToFile()
    {
        file.close();
    };
protected:
    std::ofstream file;
};

void print(LogCommand& cmd)
{
    cmd.print();
}



int main()
{
// Создание команд
    LogCommandToConsole LogToConsole("Test");
    LogCommandToFile LogToFile("Test2");

// Исполнение команд
    print(LogToFile);
    print(LogToConsole);
}