#include "section.h"
#include "../element.h"
#include "../variables/vec.h"
#include "../variables/u32.h"
#pragma once
class FunctionSectionContent:public element{
private:

public:
    vec<u32>& typeidx;
    FunctionSectionContent(vec<u32>& types)
        : typeidx(types){
    };
    ~FunctionSectionContent(){};
    std::string pack(){
        return typeidx.pack();
    };
};

class FunctionSection:section
{
private:
    
public:
    FunctionSectionContent fsc;
    FunctionSection(vec<u32>& funcTypes):
        fsc(funcTypes), section(3,fsc){
        };
    ~FunctionSection(){};
    std::string pack(){
        return section::pack();
    };
};

