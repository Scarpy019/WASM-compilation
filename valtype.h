#include "element.h"
#pragma once


class valtype : public element
{
private:
    /* data */
public:
    enum numtype
    {
        i32 = uint8_t(0x7F),
        i64 = uint8_t(0x7E),
        f32 = uint8_t(0x7D),
        f64 = uint8_t(0x7C)
    };
    enum vectype{
        v128 = uint8_t(0x7B)
    };
    enum reftype{
        funcref = uint8_t(0x70),
        externref = uint8_t(0x6F)
    };
    
    uint8_t t;
    valtype(uint8_t t):t(t){};
    ~valtype(){};
    std::string pack(){
        std::string o="";
        o.push_back(t);
        return o;
    }
};
