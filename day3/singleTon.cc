#include <iostream>
/* singleton */
class soloA
{
    int _apple;
    static soloA* _savePtr;
    soloA(){std::cout<<"Constructor Called\n";}
    soloA(const soloA&x){}
    ~soloA(){std::cout<<"Destructor Called\n";}
    public:
        static soloA* getObj()
        {
            if (_savePtr)
            {
                return _savePtr;
            } else {
                _savePtr = new soloA();
                return _savePtr;
            }
        }
        static void destroy()
        {
            if(_savePtr)
            {
                delete _savePtr;
                _savePtr = nullptr;
            }
        }
        void print()
        {
            std::cout<<"Apple is "<<_apple++<<std::endl;
        }
        void print() const
        {
            std::cout<<"Apple is "<<_apple<<std::endl;
        }
};

soloA* soloA::_savePtr = nullptr;

int main()
{
    soloA* p1= soloA::getObj(), *p2 = soloA::getObj(), *p3 = p2;
    const soloA* p4;
    p4 = p2;
    p4->print();
    p3->print();
    p2->print();
    p1->print();
    std::cout<<"p1 = "<< p1<<std::endl
            <<"p2 = "<< p2<<std::endl
            <<"p3 = "<< p3<<std::endl
            <<"p4 = "<< p4<<std::endl;
    soloA::destroy();
    return 0;
}