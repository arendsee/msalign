#include "needleman_wunsch.hpp"
#include <string>
#include <tuple>

int main(int argc, char * argv[]){
    std::string a = std::string(argv[1]);
    std::string b = std::string(argv[2]);

    NeedlemanWunsch nw(a, b);

    std::cout << nw.alignment << std::endl;
    return 0;
}
