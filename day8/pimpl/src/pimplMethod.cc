#include "../include/pimpl.hxx"

double student::pimplMethod::avgCnt(const double *arr, const int num)
{    
    double sum = 0;
    for (auto i = 0; i < num; ++i)
    {
        sum += arr[i];
    }
    return sum / 4;
}