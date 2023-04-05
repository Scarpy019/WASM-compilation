#include "../element.h"
#pragma once

class number : public element
{
private:
    /* data */
public:
    const uint8_t valueType;
    number(uint8_t vt): valueType(vt){};
    ~number(){};
};
