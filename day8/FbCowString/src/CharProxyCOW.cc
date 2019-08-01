#include "../include/FbStrCOW.hxx"

namespace fbstr
{
    String::charProxy::operator char()
    {
        return _self._dat._long._pstr[_idx];
    }

    char& String::charProxy::operator=(const char &ch)
    {
        uint8_t type = _self.getType(_self);
        char* str = _self.getStr(_self, type);
        if(type != 1 || *(uint32_t *)(str - 4) <= 1)
        {
            str[_idx] = ch;
            return str[_idx];
        }

        /* 开始进行引用计数处理 */
        --*(uint32_t *)(str - 4);
        printf("引用计数为 %u\n", *(uint32_t *)(str - 4));
        _self._dat._long._pstr = new char[_self._dat._long._capacity + 5] + 4;
        *(uint32_t *)(_self._dat._long._pstr - 4) = 1;
        strcpy(_self._dat._long._pstr, str);

        _self._dat._long._pstr[_idx] = ch;
        return _self._dat._long._pstr[_idx];
    }
};
