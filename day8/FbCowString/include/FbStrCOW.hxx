#include <cstring>
#include <iostream>

namespace fbstr{
    class String
    {
        class charProxy
        {
        public:
            operator char();
            char& operator=(const char &);
            charProxy(String &self, std::size_t index)
            :_self(self), _idx(index)
            {}

        private:
            String& _self;
            std::size_t _idx;      
        };
    public:
        String();
        String(const char *);
        String(const String&);
        ~String();
        String &operator=(const String &);
        String &operator=(const char *);

        String &operator+=(const String &);
        String &operator+=(const char *);

        charProxy operator[](std::size_t index);
        const char &operator[](std::size_t index) const;

        std::size_t size() const;
        const char* c_str() const;

        // friend bool operator==(const String &, const String &);
        // friend bool operator!=(const String &, const String &);

        // friend bool operator<(const String &, const String &);
        // friend bool operator>(const String &, const String &);
        // friend bool operator<=(const String &, const String &);
        // friend bool operator>=(const String &, const String &);

        friend std::ostream &operator<<(std::ostream &os, const String &s);
        friend std::istream &operator>>(std::istream &is, String &s);

    private:
        inline void freeProcess();
        inline size_t getLen(const uint8_t type) const;
        inline char * getStr(String &, const uint8_t type);
        inline const char * getStr(const String &, const uint8_t type) const;
        inline uint8_t getType(const String &str) const;
        inline void setSize(const uint8_t type, const size_t length);
        union dataType{
            struct {
                uint8_t _size;
                char _buffer[23];
            }_short;
            struct{
                size_t _size;
                size_t _capacity;
                char * _pstr;
            }_long;
        };
        dataType _dat;
    };

    String operator+(const String &, const String &);
    String operator+(const String &, const char *);
    String operator+(const char *, const String &);

    const int BLOCK_SIZE = 24;

    inline size_t String::getLen(const uint8_t type) const
    {
        return type > 0 ? (_dat._long._size >> 2) : (_dat._short._size >> 2);
    }

    inline char* String::getStr(String &str, const uint8_t type)
    {
        return type > 0 ? str._dat._long._pstr : str._dat._short._buffer;
    }

    inline const char* String::getStr(const String &str, const uint8_t type) const
    {
        return type > 0 ? str._dat._long._pstr : str._dat._short._buffer;
    }
    
    inline uint8_t String::getType(const String &str) const
    {
        return *(uint8_t *)&str._dat & 3;
    }

    inline void String::setSize(const uint8_t type, const size_t length)
    {
        if(type > 0)
            *(size_t *)&_dat = type | length << 2;
        else
            *(uint8_t *)&_dat = type | length << 2;
    }

    /* 基于三种类型的堆空间释放 */
    inline void String::freeProcess()
    {
        const uint8_t type = getType(*this);
        switch (type)
        {
        case 1:
            if(_dat._long._pstr && --*(int*)(_dat._long._pstr - 4) <= 0){
                delete [](_dat._long._pstr - 4);
#ifndef NDEBUG
                printf("assignment1 freed %p\n", _dat._long._pstr);
#endif
            }
            _dat._long._pstr = nullptr;
            break;
        case 2:
            if(_dat._long._pstr)
                delete []_dat._long._pstr;
#ifndef NDEBUG
            printf("assignment2 freed %p\n", _dat._long._pstr);
#endif
            _dat._long._pstr = nullptr;
            break;
        default:
            break;
        }
    }
} // namespace str

