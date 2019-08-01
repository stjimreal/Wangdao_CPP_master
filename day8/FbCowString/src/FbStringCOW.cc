#include "../include/FbStrCOW.hxx"
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

namespace fbstr{

    /* 默认构造函数开辟 BLOCK_SIZE = 24 字节的空间 */
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
            setSize(0, len);
            strcpy(_dat._short._buffer, str);
        } else if(len > 255) {
            setSize(1, len);
            _dat._long._capacity = len;
            _dat._long._pstr = new char[_dat._long._capacity + 5] + 4;
            *(int*)(_dat._long._pstr - 4) = 1;
            strcpy(_dat._long._pstr, str);
        } else {
            setSize(2, len);
            _dat._long._capacity = len;
            _dat._long._pstr = new char[_dat._long._capacity + 1];
            strcpy(_dat._long._pstr, str);
        }
    }

    /* 简单的复制构造函数 */
    String::String(const String& str)
    {
        memcpy(&this->_dat, &str._dat, sizeof(_dat));
        if(getType(*this) == 1)
            ++*(int*)(_dat._long._pstr - 4);
        else if(getType(str) == 2)
        {
            _dat._long._pstr = new char[_dat._long._capacity + 1];
            strcpy(this -> _dat._long._pstr, str._dat._long._pstr);
        }
    }

    /* 析构函数释放空间 */
    String::~String()
    {
        this->freeProcess();
    }

    /* 赋值重载函数，深拷贝 */
    String& String::operator=(const String &str)
    {
        if(&str == this)
            return *this;
        
        /* 先释放再拷贝 */
        this->freeProcess();

        const uint8_t type = getType(str);
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

    /* 拼接字符串 */
    String& String::operator+=(const String &str)
    {
        const uint8_t strType = getType(str), thisType = getType(*this);
        uint8_t type;
        size_t length = str.size() + getLen(thisType);
        char * thisStr = getStr(*this, thisType);
        const char * strStr = getStr(str, strType);

        if(length < 23)
            type = 0;
        else if(length > 255)
            type = 1;
        else
            type = 2;

        switch (type)
        {
        case 0:
        {
            strcat(_dat._short._buffer, str._dat._short._buffer);
            setSize(0, length);
            break;
        }
        case 1:
        {
            if(thisType == 1 && _dat._long._capacity >= length)
            {
                strcat(thisStr, strStr);
                setSize(1, length);
                break;
            }
            char *tmp = new char[length * 2 + 5] + 4;
            sprintf(tmp, "%s%s", thisStr, strStr);
            freeProcess();
            _dat._long._pstr = tmp;
            *(int *)(_dat._long._pstr - 4) = 1;
            setSize(1, length);
            _dat._long._capacity = length * 2;
            break;
        }
        case 2:
        {
            if(thisType > 0 && _dat._long._capacity >= length)
            {
                strcat(thisStr, strStr);
                setSize(2, length);
                break;
            }
  
            size_t capacity = 2 * length > 255 ? 255 : 2 * length;
            char *tmp = new char[_dat._long._capacity];
            sprintf(tmp, "%s%s", thisStr, strStr);
            freeProcess();
            _dat._long._pstr = tmp;
            _dat._long._capacity = capacity;
            setSize(2, length);
            break;
        }
        }
        return *this;
    }

    /* 拼接C风格字符串 */
    String& String::operator+=(const char *str)
    {
        return *this += String(str);
    }

    /* 重载[]方便调用容器中的成员 */
    String::charProxy String::operator[](std::size_t index)
    {
        return charProxy(*this, index);
    }

    /* const风格[]重载 */
    const char &String::operator[](std::size_t index) const
    {
        const char* str = getStr(*this, getType(*this));
        printf("引用计数为 %u\n", *(uint32_t *)(str - 4));
        return str[index];
    }

    /* 查看长度 */
    std::size_t String::size() const
    {
        return getLen(getType(*this));
    }

    /* 传出只读的 C风格字符串 */
    const char* String::c_str() const
    {
        return getStr(*this, getType(*this));
    }

    /* 输出友元函数 */
    std::ostream& operator<<(std::ostream &os, const String &s)
    {
        if(s.getType(s) == 0)
        {
            printf("%s", s._dat._short._buffer);
            return os;
        }
        printf("%s", s._dat._long._pstr);
        return os;
    }

    /* 输入友元函数 */
    std::istream& operator>>(std::istream &is, String &s)
    {
        char ch;
        vector<char> buffer;
        while((ch = is.get()) != '\n' && ch != '\0')
        {
            buffer.push_back(ch);
        }
        buffer.push_back('\0');
        s = &buffer[0];
        return is;
    }

    /* 重载加法函数 */
    String operator+(const String &s1, const String &s2)
    {
        String tmp = s1;
        tmp += s2;
        return tmp;
    }

    /* 重载加法函数 */
    String operator+(const String &s1, const char *s2)
    {
        return s1 + String(s2);
    }

    /* 重载加法函数 */
    String operator+(const char *s1, const String &s2)
    {
        return String(s1) + s2;
    }
}