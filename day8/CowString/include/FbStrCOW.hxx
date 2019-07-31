#include <cstring>
#include <iostream>

namespace fbstr{
    class String
    {
    public:
        String();
        String(const char *);
        String(const String&);
        ~String();
        String &operator=(const String &);
        String &operator=(const char *);

        // String &operator+=(const String &);
        // String &operator+=(const char *);

        // char &operator[](std::size_t index);
        // const char &operator[](std::size_t index) const;

        // std::size_t size() const;
        // const char* c_str() const;

        // friend bool operator==(const String &, const String &);
        // friend bool operator!=(const String &, const String &);

        // friend bool operator<(const String &, const String &);
        // friend bool operator>(const String &, const String &);
        // friend bool operator<=(const String &, const String &);
        // friend bool operator>=(const String &, const String &);

        friend std::ostream &operator<<(std::ostream &os, const String &s);
        // friend std::istream &operator>>(std::istream &is, String &s);

    private:
        inline void freeProcess();
        union{
            struct {
                uint8_t _size;
                char _buffer[23];
            }_short;
            struct{
                size_t _size;
                size_t _capacity;
                char * _pstr;
            }_long;
        }_dat;
    };

    // String operator+(const String &, const String &);
    // String operator+(const String &, const char *);
    // String operator+(const char *, const String &);

    const int BLOCK_SIZE = 24;
} // namespace str