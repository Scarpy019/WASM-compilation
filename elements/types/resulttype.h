#include "../element.h"
#include "../variables/vec.h"
#pragma once
class resulttype : public element
{
private:
    /* data */
public:
    vec<valtype>& types;
    resulttype(vec<valtype>& vals) : types(vals){};
    ~resulttype(){};
    std::string pack(){
        return types.pack();
    }
};
