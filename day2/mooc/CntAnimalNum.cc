#include <iostream>
using namespace std;

class Animal
{
    public:
    static int number;
    Animal(){++number;}
    virtual ~Animal();
};

struct Dog: public Animal
{
    public:
	static int number;
    Dog(){++number;}
    ~Dog(){--number;}
};

struct Cat: public Animal
{
    public:
    static int number;
    Cat(){++number;}
    ~Cat(){--number;}
};

Animal::~Animal()
{
	--number;
}

int Animal::number = 0;
int Dog::number = 0;
int Cat::number = 0;

void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	print();
	delete c2;
	delete d3;
	print();


	return 0;
}