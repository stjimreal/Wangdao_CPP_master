#ifndef __STUDENT_HXX
#define __STUDENT_HXX

#include <iostream>
#include <string>

class student
{
public:
    student(const std::string& name, const int sno, const int age, const double *arr, const int num);
    ~student();
    friend std::ostream& operator<<(std::ostream& os, const student& stu);

private:
    std::string _name;
    int _sno, _age;
    double _avgGrade;
    class pimplMethod;
    pimplMethod* _stu_pimpl;
};
#endif