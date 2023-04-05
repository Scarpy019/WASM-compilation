#include "section.h"
#include "../element.h"
#include "../variables/vec.h"
#include "../types/funcType.h"
#pragma once
class TypeSectionContent:public element{
private:

public:
    vec<funcType>& functs;
    TypeSectionContent(vec<funcType>& funcTypes)
        : functs(funcTypes){
    };
    ~TypeSectionContent(){};
    std::string pack(){
        return functs.pack();
    };
};

class TypeSection:section
{
private:
    
public:
    TypeSectionContent tsc;
    TypeSection(vec<funcType>& funcTypes):
        tsc(funcTypes), section(1,tsc){
        };
    ~TypeSection(){};
    std::string pack(){
        return section::pack();
    };
};

