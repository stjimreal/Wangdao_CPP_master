#ifndef __PIMPL_HXX
#define __PIMPL_HXX

#include "./student.hxx"

/* 定义impl内部实现类，注意要加作用域才行啊！！！ */
class student::pimplMethod 
{
public:
    double avgCnt(const double *arr, const int num);
};

#endif