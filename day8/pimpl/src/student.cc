#include "../include/pimpl.hxx"
#include "../include/student.hxx"

student::student(const std::string& name, const int sno, const int age, const double *arr, const int num)
: _name(name), _sno(sno), _age(age), _stu_pimpl(new pimplMethod)
{
    _avgGrade = _stu_pimpl->avgCnt(arr, num);
}

student::~student(){delete _stu_pimpl;}

std::ostream& operator<<(std::ostream& os, const student &stu)
{
    os<<stu._name<<' '<<stu._sno<<' '<<stu._age<<' '<<stu._avgGrade;
    return os;
}
