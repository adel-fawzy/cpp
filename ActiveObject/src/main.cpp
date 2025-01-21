#include <ActiveObject.hpp>
#include <iostream>
class Calculator : public ActiveObject
{
public:
    Calculator() = default;
    void add(int firstNumber, int secondNumber)
    {
        addEvent([=](){
            std::cout << (firstNumber + secondNumber) << std::endl;
        });
    }
};

int main()
{
    Calculator x{};
    x.add(3, 4);
    return 0;
}