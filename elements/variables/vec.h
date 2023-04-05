#include "../element.h"
#include "u32.h"
#include <vector>
#include <type_traits>
#pragma once

template <typename SubElement>
class vec:public element
{
private:
    
public:
    std::vector<SubElement>& vecElements;
    vec(std::vector<SubElement>& vecElems):vecElements(vecElems){
        static_assert(std::is_base_of<element,SubElement>::value, "Bad type");
    };
    ~vec(){};
    std::string pack(){
        std::string o="";
        for(auto el : vecElements){
            o+=el.pack();
        }
        o=u32(vecElements.size()).pack()+o;
        return o;
    };
};

