#include "../include/pimpl.hxx"
#include "../include/student.hxx"

int main()
{
    double arr[] = {83.4, 82.32, 83.45, 84.55};
    student jim("jimlau", 14208145, 22, arr, 4);
    std::cout<<jim<<std::endl;
    return 0;
}