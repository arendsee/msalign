#include "pairwise.hpp"
#include <string>

int main(int argc, char * argv[]){
    std::string a = std::string(argv[1]);
    std::string b = std::string(argv[2]);
    needleman_wunsch(a, b);
    return 0;
}
