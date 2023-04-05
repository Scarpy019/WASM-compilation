#include "number.h"
#include <cstdint>
#include "valtype.h"
#pragma once

class u32:public number
{
private:
public:
    uint32_t x;
    u32(uint32_t x);
    ~u32();

    std::string pack();
};

std::string u32::pack(){
    std::string o="";
    uint8_t mask = 0b01111111;
    uint32_t encodable = x;
    while (true)
    {
        uint8_t b=encodable&mask;
        encodable>>=7;
        if(encodable==0){
            o.push_back(b);
            return o;
        }
        o.push_back(b | 0b10000000);
    }
}

u32::u32(uint32_t x): number(valtype::i32), x(x)
{
}

u32::~u32()
{
}
