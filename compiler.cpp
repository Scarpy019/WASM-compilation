#include <string>
#include <fstream>
#include <cstdint>
#include "elements/variables/u32.h"
#include "elements/variables/i32.h"
#include "./elements/sections/typeSection.h"
#include "./elements/sections/functionSection.h"
#define SWAP_INT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))
int main(int argc, char* argv[]){
    std::string outFilename="output.wasm";
    std::ofstream o_file(outFilename);
    
    //---module start---
    
    //magic number
    o_file.write("\0asm",4);

    //version
    uint32_t version = uint32_t(1);
    o_file.write((char*)&version, sizeof(uint32_t));

    
    //type section
    std::vector<valtype> paramV{
        valtype(valtype::i32)
    };
    vec<valtype> paramVec{paramV};
    resulttype params{paramVec};
    std::vector<valtype> returnV{
        valtype(valtype::i32)
    };
    vec<valtype> returnVec{returnV};
    resulttype returns{returnVec};
    funcType ftype{params, returns};
    std::vector<funcType> fts=std::vector<funcType>{ftype};
    vec<funcType> ftsVec{fts};
    TypeSection tsection{ftsVec};
    o_file<<tsection.pack();
    
    std::vector<u32> funcidx{u32(0)};
    vec<u32> functionVec{funcidx};
    FunctionSection funcSec{functionVec};
    o_file<<funcSec.pack();


    o_file.close();

}