#include "number.h"
#include <cstdint>
#include "../types/valtype.h"
#pragma once
class i32 : public number
{
private:
public:
    int32_t x;
    i32(int32_t x);
    ~i32();
    std::string pack();
};

std::string i32::pack(){
    std::string o="";
    uint8_t mask = 0b01111111;//seven bit mask
    uint32_t encodable = abs(x);
    const bool neg = x<0;
    uint8_t carry=1;
    uint32_t size=32;
    while (true)
    {
        uint8_t b=encodable&mask;
        encodable>>=7;
        size-=7;
        if(neg){
            encodable|=(~0)<<(32-size);//sign extend
            b=(~b&mask)+carry;//negate the 7-bit number without flipping the 8th bit
            carry=b>>7;//if the 8th bit is 1, carry must go on to the next byte
            b&=mask;//clear 8th bit
        }
        if((encodable==0 && (b&0b01000000)==0)||
            (encodable==~uint32_t(0)) && (b&0b01000000)!=0){
            o.push_back(b);
            return o;
        }
        o.push_back(b | 0b10000000);
    }
}

i32::i32(int32_t x): number(valtype::i32), x(x)
{
}

i32::~i32()
{
}
