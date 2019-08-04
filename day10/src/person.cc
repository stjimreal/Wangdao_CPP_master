#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class person
{
public:
    person()
    : _name(), _age(-1){}
    person(string nm, int age)
    : _name(nm), _age(age){}
    virtual void display()
    {
        cout<<_name<<' '<<_age<<' ';
    }
private:
    string _name;
    int _age;
};

class employee: public person
{
public:
    employee()
    : person()
    , _department(), _salary(-1)
    {}
    employee(string nm, int age, string depart, double salary)
    : person(nm, age)
    , _department(depart)
    , _salary(salary)
    {}
    void display()
    {
        person::display();
        cout<<_department<<' '<<_salary<<endl;
    }
    double getSalary()
    {
        return _salary;
    }
private:
    string _department;
    double _salary;
};

int main()
{
    employee g, t, q;
    g = employee("guang", 12, "MTA", 2200.63);
    t = employee("tou", 21, "DNT", 16003.89);
    q = employee("qiang", 35, "DNT", 54223.49);
    person& m1 = g;
    m1.display();
    g.display();
    t.display();
    q.display();
    cout<<"avg salary = "<<(g.getSalary() + t.getSalary() + q.getSalary()) / 3<<endl;
    return 0;
}