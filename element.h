#include <string>

#pragma once
class element
{
private:
    /* data */
public:
    element(/* args */);
    ~element();
    virtual std::string pack()=0;
};

element::element(/* args */)
{
}

element::~element()
{
}
