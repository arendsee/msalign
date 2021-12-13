#include "pairwise.hpp"
#include <string>
#include <tuple>

int main(int argc, char * argv[]){
    std::string a = std::string(argv[1]);
    std::string b = std::string(argv[2]);
    std::tuple<std::string, std::vector<std::tuple<char, size_t, int>>> result = needleman_wunsch(a, b);
    std::cout << std::get<0>(result) << std::endl;
    return 0;
}
