#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
/* 
99999999999999999999999999888888888888888812345678901234567789 12
6 6 
*/
/* 
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
99999999999999999999999999888888888888888812345678901234567801
25
25
26
12
12
12
13
13
14
 */
const int MAX = 110; 
class CHugeInt {
    public:
        CHugeInt(int n)
        {
            bzero(_hugeInt, sizeof(_hugeInt));
            int i = 0;
            while(n)
            {
                _hugeInt[i++] = n % 10 + '0';
                n /= 10;
            }
            _size = i;
        }
        CHugeInt(const char *s)
        {
            bzero(_hugeInt, sizeof(_hugeInt));
            const char *i = s;
            _size = 0;
            while(*i != '\0')
            {
                ++i;
                ++_size;
            }

            for (int j = 0; j < _size; ++j)
            {
                _hugeInt[j] = *--i;
            }
        }
        CHugeInt(int size, char value)
        : _size(size)
        {
            memset(_hugeInt, value, sizeof(_hugeInt));
        }
        friend CHugeInt operator+(const CHugeInt& x, const CHugeInt& y)
        {
            int size = x._size > y._size? x._size: y._size;
            const char* largePtr = x._size > y._size?x._hugeInt: y._hugeInt;
            CHugeInt rtn(size, '\0');
            int rised = 0;
            int cnt = x._size < y._size? x._size: y._size;
            int i;
            for (i = 0; i < cnt; ++i)
            {
                if(x._hugeInt[i] - '0' + y._hugeInt[i] - '0' + rised >= 10)
                {
                    rtn._hugeInt[i] = rised + x._hugeInt[i] + y._hugeInt[i] - '0' - 10;
                    rised = 1;
                } else {
                    rtn._hugeInt[i] = rised + x._hugeInt[i] + y._hugeInt[i] - '0';
                    rised = 0;
                }
            }
            if(rised)
            {
                while(largePtr[i] == '9')
                {
                    rtn._hugeInt[i++] = '0';
                }
                if(largePtr[i] >= '0'){
                    rtn._hugeInt[i] = largePtr[i] + rised;
                    ++i;
                    rised = 0;
                } else {
                    rtn._hugeInt[i] = '1';
                    rised = 0;
                }
            }
            while(largePtr[i] >= '0' && largePtr[i] <= '9')
            {
                rtn._hugeInt[i] = largePtr[i];
                ++i;
            }
            return rtn;
        }

        CHugeInt& operator+=(int n)
        {
            CHugeInt tmp = *this + n;
            strcpy(_hugeInt, tmp._hugeInt);
            _size = tmp._size;
            return *this;
        }

        CHugeInt& operator++()
        {
            int i = 0;
            while(_hugeInt[i] == '9')
            {
                _hugeInt[i++] = '0';
            }
            if(_hugeInt[i] >= '0'){
                _hugeInt[i] = _hugeInt[i] + 1;
                ++i;
            } else {
                ++_size;
                _hugeInt[i] = '1';
            }
            return *this;
        }
        CHugeInt operator++(int x)
        {
            CHugeInt tmp = *this;
            this->operator++();
            return tmp;
        }
        friend ostream& operator<<(ostream& os, const CHugeInt& x)
        {
            int i = 0;
            while(x._hugeInt[i] != '\0')
                ++i;
            while(i > 0)
            {
                printf("%c", x._hugeInt[--i]);
            }
            return os;
        }

    private:
        char _hugeInt[2 * MAX];
        int _size;
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
