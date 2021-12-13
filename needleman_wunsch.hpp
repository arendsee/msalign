#ifndef __PAIRWISE_HPP__
#define __PAIRWISE_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

const int GAP_OPEN_PENALTY = -12;
const int GAP_EXTEND_PENALTY = -2;

class NeedlemanWunsch
{
    public:
        std::string query;
        std::string subject;
        std::vector<std::vector<int>> matrix;
        std::string alignment;
        std::vector<std::tuple<char, size_t, int>> insertions;

        NeedlemanWunsch(std::string queryIn, std::string subjectIn);
        void print_matrix();
        void print_insertions();
};

#endif
