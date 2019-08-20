#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
# if defined(__sgi)
    cout<<"__sgi"<<endl;
# endif
# if defined(__GNUC__)
    cout<<"__GNUC__"<<endl;
    cout<<__GNUC__<<' '<<__GNUC_MINOR__<<endl;
# endif

#ifdef __STL_NO_DRAND48
    cout<<"__STL_NO_DRAND48 defined"<<endl;
#else
    cout<<"__STL_NO_DRAND48 undefined"<<endl;
# endif


#ifdef __STL_STATIC_TEMPLATE_MEMBER_BUG
    cout<<"__STL_STATIC_TEMPLATE_MEMBER_BUG defined"<<endl;
#else
    cout<<"__STL_STATIC_TEMPLATE_MEMBER_BUG undefined"<<endl;
#endif

#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
    cout<<"__STL_CLASS_PARTIAL_SPECIALIZATION defined"<<endl;
#else
    cout<<"__STL_CLASS_PARTIAL_SPECIALIZATION undefined"<<endl;
#endif

#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER
    cout<<"__STL_FUNCTION_TMPL_PARTIAL_ORDER defined"<<endl;
#else
    cout<<"__STL_FUNCTION_TMPL_PARTIAL_ORDER undefined"<<endl;
#endif

    return 0;
}