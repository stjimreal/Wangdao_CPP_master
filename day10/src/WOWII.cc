#include <iostream>
#include <vector>
#include <map>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;

#define whichArm(arm)(arm == 0?"sword":(arm == 1?"bomb":"arrow"))

enum WORR
{
    Dra=0,
    Nin=1,
    Ice=2,
    Lio=3,
    Wol=4
};

class worrior
{
protected:
    worrior(int no, int strength)
    : _wno(no), _strength(strength){}
    void getInfo(int &Strength, int &WNo)const
    {
        Strength = _strength;
        WNo = _wno;
    }
private:
    int _wno;
    int _strength;

};

class Dragen: public worrior
{
public:
    Dragen(int strength, int num, int total)
    : worrior(num, strength)
    , _morale(((double)total - strength) / strength)
    , _arm(num % 3)
    {}
    void getInfo(int &Strength, int &WNo, double &Morale, uint8_t &Arm) const
    {
        worrior::getInfo(Strength, WNo);
        Morale = _morale;
        Arm = _arm;
    }
private:
    double _morale;
    uint8_t _arm;
};

class Ninja: public worrior
{
public:
    Ninja(int strength, int num)
    : worrior(num, strength)
    , _mainArm(num % 3)
    , _secArm((num + 1) % 3)
    {}
    void getInfo(int &Strength, int &WNo, uint8_t &MainArm, uint8_t &SecArm) const
    {
        worrior::getInfo(Strength, WNo);
        MainArm = _mainArm;
        SecArm = _secArm;
    }

private:
    uint8_t _mainArm;
    uint8_t _secArm;
};

class Iceman: public worrior
{
public:
    Iceman(int strength, int num)
    : worrior(num, strength)
    , _arm(num % 3)
    {}
    void getInfo(int &Strength, int &WNo, uint8_t &Arm)const
    {
        worrior::getInfo(Strength, WNo);
        Arm = _arm;
    }
private:
    uint8_t _arm;
};

class Lion: public worrior
{
public:
    Lion(int strength, int num, int total)
    : worrior(num, strength)
    , _loyalty(total - strength)
    {}
    void getInfo(int &Strength, int &WNo, int &Loyalty)const
    {
        worrior::getInfo(Strength, WNo);
        Loyalty = _loyalty;
    }
private:
    int _loyalty;
};

class Wolf: public worrior
{
public:
    Wolf(int strength, int num)
    : worrior(num, strength)
    {}
    void getInfo(int &Strength, int &WNo)const
    {
        worrior::getInfo(Strength, WNo);
    }
};

class center
{
public:
    center()
    : _n(0)
    {
        cin>>_M;
        cin>>_dStrength>>_nStrength>>_iStrength>>_lStrength>>_wStrength;
    }
    center(const center& cent)
    : _M(cent._M)
    , _dStrength(cent._dStrength)
    , _nStrength(cent._nStrength)
    , _iStrength(cent._iStrength)
    , _lStrength(cent._lStrength)
    , _wStrength(cent._wStrength) 
    , _n(cent._n)
    {}
    Dragen& makeDragen()
    {
        dStroop.push_back(Dragen(_dStrength, ++_n, _M));
        _M -= _dStrength;
        return dStroop.back();
    }
    Ninja& makeNinja(){nStroop.push_back(Ninja(_nStrength, ++_n)); _M -= _nStrength; return nStroop.back();}
    Iceman& makeIceman(){iStroop.push_back(Iceman(_iStrength, ++_n)); _M -= _iStrength; return iStroop.back();}
    Lion& makeLion(){lStroop.push_back(Lion(_lStrength, ++_n, _M)); _M -= _lStrength; return lStroop.back();}
    Wolf& makeWolf(){wStroop.push_back(Wolf(_wStrength, ++_n)); _M -= _wStrength; return wStroop.back();}

    int MakeinLog(const char* centerName, const WORR worrType, const int time)
    {
        int num; int strength; 
        switch (worrType)
        {
        case Dra:
        {
            if(_M < _dStrength)
                return -1;
            double morale; uint8_t arm;
            makeDragen().getInfo(strength, num, morale, arm);
            genLog(time, centerName, "dragon", num, strength, dStroop.size());
            printf("It has a %s,and it's morale is %.2lf\n", whichArm(arm), morale);
            break;
        }
        case Nin:
            if(_M < _nStrength)
                return -1;
            uint8_t mainArm, secArm;
            makeNinja().getInfo(strength, num, mainArm, secArm);
            genLog(time, centerName, "ninja", num, strength, nStroop.size());
            printf("It has a %s and a %s\n", whichArm(mainArm), whichArm(secArm));
            break;
        case Ice:
            if(_M < _iStrength)
                return -1;
            uint8_t arm;
            makeIceman().getInfo(strength, num, arm);
            genLog(time, centerName, "iceman", num, strength, iStroop.size());
            printf("It has a %s\n", whichArm(arm));
            break;
        case Lio:
            if(_M < _lStrength)
                return -1;
            int loyalty;
            makeLion().getInfo(strength, num, loyalty);
            genLog(time, centerName, "lion", num, strength, lStroop.size());
            printf("It's loyalty is %d\n", loyalty);
            break;
        case Wol:
            if(_M < _wStrength)
                return -1;
            makeWolf().getInfo(strength, num);
            genLog(time, centerName, "wolf", num, strength, wStroop.size());
            break;
        default:
            break;
        }
        return 0;
    }

private:
    inline void genLog(int time, const char* centerName, const char* WorriorName, int num, int strength, size_t size)
    {
        printf("%03d %s %s %d born with strength %d,%ld %s in %s headquarter\n", time, centerName, WorriorName, num, strength, size, WorriorName, centerName);
    }
    int _M;
    int _dStrength, _nStrength, _iStrength, _lStrength, _wStrength;
    int _n;
    vector<Dragen> dStroop;
    vector<Ninja> nStroop;
    vector<Iceman> iStroop;
    vector<Lion> lStroop;
    vector<Wolf> wStroop;
};

/* 控制center制造勇士，直到不够制造最小生命值的勇士 */
void rollAll(center red, center blue)
{
    // 红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。 
    map<int, WORR> redOrder, blueOrder;
    redOrder[0] = Ice; redOrder[1] = Lio; redOrder[2] = Wol; redOrder[3] = Nin; redOrder[4] = Dra;
    blueOrder[0] = Lio; blueOrder[1] = Dra; blueOrder[2] = Nin; blueOrder[3] = Ice; blueOrder[4] = Wol;

    // 蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。 
    int iRed = 0, iBlue = 0;
    int bOK = 0, rOK = 0;
    int t = 0;
    uint8_t pBBit = 0, pRBit = 0;
    while(1)
    {
        for (int cnt = 0, right = -1; rOK == 0 && right == -1; iRed = (iRed + 1) % 5)
        {
            right = red.MakeinLog("red", redOrder[iRed], t);
            if(right) ++cnt;
            if(cnt == 5) rOK = -1;
        }
        if(rOK && pRBit == 0)
        {
            printf("%03d %s headquarter stops making warriors\n", t, "red");
            pRBit = 1;
        }
        
        for (int cnt = 0, right = -1; bOK == 0 && right == -1; iBlue = (iBlue + 1) % 5)
        {
            right = blue.MakeinLog("blue", blueOrder[iBlue], t);
            if(right) ++cnt;
            if(cnt == 5) bOK = -1;
        }
        if(bOK && pBBit == 0)
        {
            printf("%03d %s headquarter stops making warriors\n", t, "blue");
            pBBit = 1;
        }
            
        if(bOK && rOK)
            break;
        ++t;
    }
}

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        printf("Case:%d\n", i + 1);
        center red, blue(red);
        rollAll(red, blue);
    }
    return 0;
}