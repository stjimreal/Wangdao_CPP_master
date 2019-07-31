#include "../include/FbStrCOW.hxx"

using std::cout;
using std::cin;
using std::endl;

namespace fbstr{

    /* 默认构造函数开辟 BLOCK_SIZE = 24 字节的空间 */
    inline void String::freeProcess()
    {
        uint8_t type = *(uint8_t*)&_dat & 3;
        switch (type)
        {
        case 1:
            if(_dat._long._pstr && --*(int*)(_dat._long._pstr - 4) <= 0){
                delete [](_dat._long._pstr - 4);
                printf("assignment1 freed %p\n", _dat._long._pstr);
            }
            _dat._long._pstr = nullptr;
            break;
        case 2:
            if(_dat._long._pstr)
                delete []_dat._long._pstr;
            printf("assignment2 freed %p\n", _dat._long._pstr);
            _dat._long._pstr = nullptr;
            break;
        default:
            break;
        }
    }
    String::String()
    {
        bzero(&_dat, sizeof(_dat));  // 0 代表短字符串
    }

    /* 类型转换构造函数方便传入C风格字符串 */
    /* 0 代表 0 ~ 23 短字符串 */
    /* 1 代表 24 ~ 255 字符串 */
    /* 2 代表 256 ~ 字符串 */
    String::String(const char * str)
    {
        size_t len = strlen(str);
        if(len < 23)
        {
            _dat._short._size = len << 2;
            strcpy(_dat._short._buffer, str);
        } else if(len > 255) {
            _dat._long._size = 1 | (len << 2);
            _dat._long._capacity = len;
            _dat._long._pstr = new char[_dat._long._capacity + 5] + 4;
            *(int*)(_dat._long._pstr - 4) = 1;
            strcpy(_dat._long._pstr, str);
        } else {
            _dat._long._size = 2 | (len << 2);
            _dat._long._capacity = len;
            _dat._long._pstr = new char[_dat._long._capacity + 1];
            strcpy(_dat._long._pstr, str);
        }
    }

    /* 简单的复制构造函数 */
    String::String(const String& str)
    {
        memcpy(&this->_dat, &str._dat, sizeof(_dat));
        if((*(uint8_t*)&_dat & 3) == 1)
            ++*(int*)(_dat._long._pstr - 4);
        else if((*(uint8_t*)&str._dat & 3) == 2)
        {
            _dat._long._pstr = new char[_dat._long._capacity + 1];
            strcpy(this -> _dat._long._pstr, str._dat._long._pstr);
        }
    }

    /* 析构函数释放空间 */
    String::~String()
    {
        // if((*(uint8_t*)&_dat & 3) == 0)
        //     return ; 
        this->freeProcess();
        printf("here1\n");
    }

    /* 赋值重载函数，深拷贝 */
    String& String::operator=(const String &str)
    {
        if(&str == this)
            return *this;
        
        /* 先释放再拷贝 */
        this->freeProcess();

        uint8_t type = *(uint8_t*)&str._dat & 3;
        memcpy(&_dat, &str._dat, sizeof(_dat));
        switch (type)
        {
        case 1:
            ++*(int*)(_dat._long._pstr - 4);
            break;
        case 2:
            _dat._long._pstr = new char[_dat._long._capacity + 1];
            printf("address = %p\n", _dat._long._pstr);
            strcpy(_dat._long._pstr, str._dat._long._pstr);
            break;
        default:
            break;
        }
        return *this;
    }

    /* 重用以上赋值=、类型转换构造函数函数 */
    String& String::operator=(const char *str)
    {
        *this = String(str);
        return *this;
    }

//     /* 拼接字符串 */
//     String& String::operator+=(const String &str)
//     {
        
//         if(_pstr==nullptr || sizeof(_pstr) < strlen(_pstr) + strlen(str._pstr) + 1)
//         {
//             char * tmp = _pstr;
//             tmp = new char[strlen(_pstr) + strlen(str._pstr) + BLOCK_SIZE + 1];
//             sprintf(tmp, "%s%s", _pstr, str._pstr);
//             if(_pstr)
//                 delete []_pstr;
//             _pstr = tmp;
//         } else {
//             sprintf(_pstr, "%s%s", _pstr, str._pstr);
//         }

//         return *this;
//     }


//     /* 拼接C风格字符串 */
//     String& String::operator+=(const char *str)
//     {
//         return *this += String(str);
//     }

//     /* 重载[]方便调用容器中的成员 */
//     char &String::operator[](std::size_t index)
//     {
//         return _pstr[index];
//     }

//     /* const风格[]重载 */
//     const char &String::operator[](std::size_t index) const
//     {
//         return _pstr[index];
//     }

//     /* 查看长度 */
//     std::size_t String::size() const
//     {
//         return strlen(_pstr);
//     }

//     /* 传出只读的 C风格字符串 */
//     const char* String::c_str() const
//     {
//         return _pstr;
//     }

//     /* 封装 strcmp 函数进行判断 */
//     bool operator==(const String &s1, const String &s2)
//     {
//         return !strcmp(s1._pstr, s2._pstr);
//     }

//     /* 封装 strcmp 函数进行判断 */
//     bool operator!=(const String &s1, const String &s2)
//     {
//         return !operator==(s1, s2);
//     }

//     /* 封装 strcmp 函数进行判断 */
//     bool operator<(const String &s1, const String &s2)
//     {
//         return strcmp(s1._pstr, s2._pstr) < 0;
//     }

//     /* 封装 strcmp 函数进行判断 */
//     bool operator>(const String &s1, const String &s2)
//     {
//         return strcmp(s1._pstr, s2._pstr) > 0;
//     }

//     /* 封装 strcmp 函数进行判断 */
//     bool operator<=(const String &s1, const String &s2)
//     {
//         return strcmp(s1._pstr, s2._pstr) <= 0;
//     }

//     /* 封装 strcmp 函数进行判断 */
//     bool operator>=(const String &s1, const String &s2)
//     {
//          return strcmp(s1._pstr, s2._pstr) >= 0;
//     }

    /* 输出友元函数 */
    std::ostream& operator<<(std::ostream &os, const String &s)
    {
        if((*(uint8_t *)&s & 3) == 0)
        {
            printf("%s", s._dat._short._buffer);
            return os;
        }
        printf("%s", s._dat._long._pstr);
        return os;
    }

//     /* 输入友元函数 */
//     std::istream& operator>>(std::istream &is, String &s)
//     {
//         return is>>s._pstr;
//     }

//     /* 重载加法函数 */
//     String operator+(const String &s1, const String &s2)
//     {
//         String tmp = s1;
//         tmp += s2;
//         return tmp;
//     }

//     /* 重载加法函数 */
//     String operator+(const String &s1, const char *s2)
//     {
//         return s1 + String(s2);
//     }

//     /* 重载加法函数 */
//     String operator+(const char *s1, const String &s2)
//     {
//         return String(s1) + s2;
//     }
}