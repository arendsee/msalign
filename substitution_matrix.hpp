#ifndef __BLOSUM90_HPP__
#define __BLOSUM90_HPP__

#include <vector>
#include <iostream>

// The BLOSUM90 substitution matrix
// 
// The matrix contains 26 columns and 26 rows. These correspond to the letters
// of the alphabet. 'Z' stores gaps. The letters that are not used are for
// amino acids, unknowns ('X') or gaps are filled with 0's.

std::vector<int> BLOSUM90_0  { 5,  0,  -1,  -3,  -1,  -3,   0,  -2,  -2,  0,  -1,  -2,  -2,  -2,  0,  -1,  -1,  -2,   1,   0,  0,  -1,  -4,  -1,  -3,  -1};
std::vector<int> BLOSUM90_1  { 0,  0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0};
std::vector<int> BLOSUM90_2  {-1,  0,   9,  -5,  -6,  -3,  -4,  -5,  -2,  0,  -4,  -2,  -2,  -4,  0,  -4,  -4,  -5,  -2,  -2,  0,  -2,  -4,  -1,  -4,  -1};
std::vector<int> BLOSUM90_3  {-3,  0,  -5,   7,   1,  -5,  -2,  -2,  -5,  0,  -1,  -5,  -4,   1,  0,  -3,  -1,  -3,  -1,  -2,  0,  -5,  -6,  -1,  -4,  -1};
std::vector<int> BLOSUM90_4  {-1,  0,  -6,   1,   6,  -5,  -3,  -1,  -4,  0,   0,  -4,  -3,  -1,  0,  -2,   2,  -1,  -1,  -1,  0,  -3,  -5,  -1,  -4,  -1};
std::vector<int> BLOSUM90_5  {-3,  0,  -3,  -5,  -5,   7,  -5,  -2,  -1,  0,  -4,   0,  -1,  -4,  0,  -4,  -4,  -4,  -3,  -3,  0,  -2,   0,  -1,   3,  -1};
std::vector<int> BLOSUM90_6  { 0,  0,  -4,  -2,  -3,  -5,   6,  -3,  -5,  0,  -2,  -5,  -4,  -1,  0,  -3,  -3,  -3,  -1,  -3,  0,  -5,  -4,  -1,  -5,  -1};
std::vector<int> BLOSUM90_7  {-2,  0,  -5,  -2,  -1,  -2,  -3,   8,  -4,  0,  -1,  -4,  -3,   0,  0,  -3,   1,   0,  -2,  -2,  0,  -4,  -3,  -1,   1,  -1};
std::vector<int> BLOSUM90_8  {-2,  0,  -2,  -5,  -4,  -1,  -5,  -4,   5,  0,  -4,   1,   1,  -4,  0,  -4,  -4,  -4,  -3,  -1,  0,   3,  -4,  -1,  -2,  -1};
std::vector<int> BLOSUM90_9  { 0,  0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0};
std::vector<int> BLOSUM90_10 {-1,  0,  -4,  -1,   0,  -4,  -2,  -1,  -4,  0,   6,  -3,  -2,   0,  0,  -2,   1,   2,  -1,  -1,  0,  -3,  -5,  -1,  -3,  -1};
std::vector<int> BLOSUM90_11 {-2,  0,  -2,  -5,  -4,   0,  -5,  -4,   1,  0,  -3,   5,   2,  -4,  0,  -4,  -3,  -3,  -3,  -2,  0,   0,  -3,  -1,  -2,  -1};
std::vector<int> BLOSUM90_12 {-2,  0,  -2,  -4,  -3,  -1,  -4,  -3,   1,  0,  -2,   2,   7,  -3,  0,  -3,   0,  -2,  -2,  -1,  0,   0,  -2,  -1,  -2,  -1};
std::vector<int> BLOSUM90_13 {-2,  0,  -4,   1,  -1,  -4,  -1,   0,  -4,  0,   0,  -4,  -3,   7,  0,  -3,   0,  -1,   0,   0,  0,  -4,  -5,  -1,  -3,  -1};
std::vector<int> BLOSUM90_14 { 0,  0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0};
std::vector<int> BLOSUM90_15 {-1,  0,  -4,  -3,  -2,  -4,  -3,  -3,  -4,  0,  -2,  -4,  -3,  -3,  0,   8,  -2,  -3,  -2,  -2,  0,  -3,  -5,  -1,  -4,  -1};
std::vector<int> BLOSUM90_16 {-1,  0,  -4,  -1,   2,  -4,  -3,   1,  -4,  0,   1,  -3,  0,    0,  0,  -2,   7,   1,  -1,  -1,  0,  -3,  -3,  -1,  -3,  -1};
std::vector<int> BLOSUM90_17 {-2,  0,  -5,  -3,  -1,  -4,  -3,   0,  -4,  0,   2,  -3,  -2,  -1,  0,  -3,   1,   6,  -1,  -2,  0,  -3,  -4,  -1,  -3,  -1};
std::vector<int> BLOSUM90_18 { 1,  0,  -2,  -1,  -1,  -3,  -1,  -2,  -3,  0,  -1,  -3,  -2,   0,  0,  -2,  -1,  -1,   5,   1,  0,  -2,  -4,  -1,  -3,  -1};
std::vector<int> BLOSUM90_19 { 0,  0,  -2,  -2,  -1,  -3,  -3,  -2,  -1,  0,  -1,  -2,  -1,   0,  0,  -2,  -1,  -2,   1,   6,  0,  -1,  -4,  -1,  -2,  -1};
std::vector<int> BLOSUM90_20 { 0,  0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0};
std::vector<int> BLOSUM90_21 {-1,  0,  -2,  -5,  -3,  -2,  -5,  -4,   3,  0,  -3,   0,   0,  -4,  0,  -3,  -3,  -3,  -2,  -1,  0,   5,  -3,  -1,  -3,  -1};
std::vector<int> BLOSUM90_22 {-4,  0,  -4,  -6,  -5,   0,  -4,  -3,  -4,  0,  -5,  -3,  -2,  -5,  0,  -5,  -3,  -4,  -4,  -4,  0,  -3,  11,  -1,   2,  -1};
std::vector<int> BLOSUM90_23 {-1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  -1,  -1,  -1,  -1,  0,  -1,  -1,  -1,  -1,  -1,  0,  -1,  -1,  -1,  -1,  -1};
std::vector<int> BLOSUM90_24 {-3,  0,  -4,  -4,  -4,   3,  -5  , 1,  -2,  0,  -3,  -2,  -2,  -3,  0,  -4,  -3,  -3,  -3,  -2,  0,  -3,   2,  -1,   8,  -1};
std::vector<int> BLOSUM90_25 { 0,  0,   0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0};

std::vector<std::vector<int>> BLOSUM90 {
    BLOSUM90_0, BLOSUM90_1, BLOSUM90_2, BLOSUM90_3, BLOSUM90_4, BLOSUM90_5,
    BLOSUM90_6, BLOSUM90_7, BLOSUM90_8, BLOSUM90_9, BLOSUM90_10, BLOSUM90_11,
    BLOSUM90_12, BLOSUM90_13, BLOSUM90_14, BLOSUM90_15, BLOSUM90_16,
    BLOSUM90_17, BLOSUM90_18, BLOSUM90_19, BLOSUM90_20, BLOSUM90_21,
    BLOSUM90_22, BLOSUM90_23, BLOSUM90_24, BLOSUM90_25
};



int substitution_score(char a, char b){
    return BLOSUM90[a - 65][b - 65];
}



bool isGap(char a){
    return (a == 'Z');
}



// This is pass-by-copy. The string is changed and a new string is returned. I
// do not change in place. That gives the alignment algorithm and this cleaning
// function the freedom to specialize the string format (such as turning '-' to
// 'Z') without side effects.
std::string cleanSeq(std::string x, bool is_query){
    for(size_t i = 0; i < x.size(); i++){
        char c = x[i];
        if (c == '-' || c == '_')
            c = 'Z'; // map gaps to 'Z' so that lookup is possible by index
        else if  (c >= 97 && c <= 122){
            c -= 32;
        }

        if (c == 'B' || c == 'J' || c == 'O' || ! (c >= 65 && c <= 90)){
            std::cerr << "Bad input: " << c << std::endl;
            std::exit(1);
        }

        if (is_query && c == 'Z') {
            std::cerr << "The query sequence must not have gaps" << std::endl;
            std::exit(1);
        }

        x[i] = c;
    }

    return x;
}

#endif
