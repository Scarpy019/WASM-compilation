#include "u32.h"
#include "element.h"
#include <cstdint>
#pragma once

class section : public element
{
protected:
    u32 N;//section id
    element &content;
public:
    section(uint32_t sectionType, element& el): N(sectionType), content(el) {};
    ~section() {};
    std::string pack();
};

std::string section::pack(){
    std::string o="";
    o+=N.pack();
    std::string contentString = content.pack();
    o+= u32(contentString.size()).pack();
    o+=contentString;
    return o;
}