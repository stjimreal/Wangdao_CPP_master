#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class student
{
public:
    virtual void info()const =0;
    student(const string&nm, long int sno)
    : _nm(nm), _sno(sno)
    {}

    friend std::ostream& operator<<(std::ostream& os, const student &stu)
    {
        os<<"学生信息是"<<endl;
        stu.info();
        return os;
    }

protected:
    string _nm;
    long int _sno;
};

class CollegeStudent: public student
{
public:
    CollegeStudent(string name, long int sno, float gpa = 0, bool failed = 0)
    :student(name, sno), _failbit(failed), _gpa(gpa){}
    void info()const
    {
        cout<<"大学生：";
        cout<<student::_nm<<' '<<student::_sno<<' ';
        if(_failbit)
            cout<<"有挂科 ";
        else
            cout<<"无挂科 ";
        cout<<"GPA"<<_gpa<<endl;
    }
private:
    bool _failbit;
    float _gpa;
};

class SeniorStudent: public student
{
public:
    SeniorStudent(string name, long int sno, int rank = -1, int latestGrade = -1, bool scienceOrArts = 0)
    : student(name, sno), _rank(rank), _latestGrade(latestGrade), _scienceOrArts(scienceOrArts){}
    void info()const
    {
        cout<<"高中生：";
        cout<<student::_nm<<' '<<student::_sno<<' '<<"年级排名："<<_rank<<' ';
        if(_scienceOrArts)
            cout<<"理科 ";
        else
            cout<<"文科 ";
        cout<<"总分："<<_latestGrade<<endl;
    }
private:
    int _rank;
    int _latestGrade;
    bool _scienceOrArts;
};


int main()
{
    CollegeStudent xuyuhui("xuyuhui", 15204144, 3.32);
    SeniorStudent me("Jimmy", 2044, 23, 635, 1);
    cout<<xuyuhui;
    cout<<me;
    return 0;
}