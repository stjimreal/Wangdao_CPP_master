#include <string>
class Computer
{
public:
    Computer(std::string name, double price)
    : _Name(name)
    , _Price(price)
    {}
    Computer()
    : _Name()
    , _Price(-1)
    {}

private:
    std::string _Name;
    double _Price;
};