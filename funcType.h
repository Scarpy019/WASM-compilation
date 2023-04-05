#include "element.h"
#include "resulttype.h"
#pragma once
class funcType : public element
{
private:
    /* data */
public:

    resulttype& resType1;
    resulttype& resType2;
    funcType(resulttype& resType1, resulttype& resType2)
        : resType1(resType1), resType2(resType2){};
    ~funcType(){};
    std::string pack(){
        std::string o = "";
        o.push_back(0x60);
        o+=resType1.pack();
        o+=resType2.pack();
        return o;
    }
};

