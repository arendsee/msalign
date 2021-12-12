#ifndef __PAIRWISE_HPP__
#define __PAIRWISE_HPP__

#include <iostream>
#include <vector>
#include <string>

#define GAP_OPEN_PENALTY -12
#define GAP_EXTEND_PENALTY -2


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
std::vector<int> BLOSUM90_14 { 0,  0  , 0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0};
std::vector<int> BLOSUM90_15 {-1,  0,  -4,  -3,  -2,  -4,  -3,  -3,  -4,  0,  -2,  -4,  -3,  -3,  0,   8,  -2,  -3,  -2,  -2,  0,  -3,  -5,  -1,  -4,  -1};
std::vector<int> BLOSUM90_16 {-1,  0,  -4,  -1,   2,  -4,  -3,   1,  -4,  0,   1,  -3,  0,    0,  0,  -2,   7,   1,  -1,  -1,  0,  -3,  -3,  -1,  -3,  -1};
std::vector<int> BLOSUM90_17 {-2,  0,  -5,  -3,  -1,  -4,  -3,   0,  -4,  0,   2,  -3,  -2,  -1,  0,  -3,   1,   6,  -1,  -2,  0,  -3,  -4,  -1,  -3,  -1};
std::vector<int> BLOSUM90_18 { 1,  0,  -2,  -1,  -1,  -3,  -1,  -2,  -3,  0,  -1,  -3,  -2,   0,  0,  -2,  -1,  -1,   5,   1,  0,  -2,  -4,  -1,  -3,  -1};
std::vector<int> BLOSUM90_19 { 0,  0,  -2,  -2,  -1,  -3,  -3,  -2,  -1,  0,  -1,  -2,  -1,   0,  0,  -2,  -1,  -2,   1,   6,  0,  -1,  -4,  -1,  -2,  -1};
std::vector<int> BLOSUM90_20 { 0,  0  , 0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0};
std::vector<int> BLOSUM90_21 {-1,  0,  -2,  -5,  -3,  -2,  -5,  -4,   3,  0,  -3,   0,   0,  -4,  0,  -3,  -3,  -3,  -2,  -1,  0,   5,  -3,  -1,  -3,  -1};
std::vector<int> BLOSUM90_22 {-4,  0,  -4,  -6,  -5,   0,  -4,  -3,  -4,  0,  -5,  -3,  -2,  -5,  0,  -5,  -3,  -4,  -4,  -4,  0,  -3,  11,  -1,   2,  -1};
std::vector<int> BLOSUM90_23 {-1,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  -1,  -1,  -1,  -1,  0,  -1,  -1,  -1,  -1,  -1,  0,  -1,  -1,  -1,  -1,  -1};
std::vector<int> BLOSUM90_24 {-3,  0,  -4,  -4,  -4,   3,  -5  , 1,  -2,  0,  -3,  -2,  -2,  -3,  0,  -4,  -3,  -3,  -3,  -2,  0,  -3,   2,  -1,   8,  -1};
std::vector<int> BLOSUM90_25 { 0,  0  , 0,   0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0,  0,   0,   0,   0,   0,   0};

std::vector<std::vector<int>> BLOSUM90 {
    BLOSUM90_0, BLOSUM90_1, BLOSUM90_2, BLOSUM90_3, BLOSUM90_4, BLOSUM90_5,
    BLOSUM90_6, BLOSUM90_7, BLOSUM90_8, BLOSUM90_9, BLOSUM90_10, BLOSUM90_11,
    BLOSUM90_12, BLOSUM90_13, BLOSUM90_14, BLOSUM90_15, BLOSUM90_16,
    BLOSUM90_17, BLOSUM90_18, BLOSUM90_19, BLOSUM90_20, BLOSUM90_21,
    BLOSUM90_22, BLOSUM90_23, BLOSUM90_24, BLOSUM90_25
};



// typedef struct Alignment{
//     std::string alignment;
//     size_t offset;
//     std::vector<Insert> inserts;
//     size_t ninsert;
// } Alignment;
//
// typedef struct Insert{
//     char insert;
//     size_t pos;  // the MSA index the insertion is relative two ([0..m-1], where m is the MSA length)
//     int distance; // offset from the MSA index
//                   // negative values indicate the insertion preceeds the reference position (..-1)
//                   // positive values are after the reference position (1..)
// } Insert;


void cleanSeq(std::string x, bool is_query){
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
}

void dump_score_matrix(std::vector<std::vector<int>> matrix, std::string query, std::string subject){
    // print the score matrix
    std::cout << "    . ";
    for (size_t i = 0; i < subject.size(); i++){
        char c = subject[i];
        if (c == 'Z')
            c = '-';
        std::cout << subject[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < matrix.size(); i++){
        if (i > 0){
            std::cout << query[i-1] << " ";
        } else {
            std::cout << ".  ";
        }
        for (size_t j = 0; j < matrix[i].size(); j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void needleman_wunsch(std::string query, std::string subject){

    cleanSeq(query, true);
    cleanSeq(subject, false);

    // initialize the matrix for holding the scores
    std::vector<std::vector<int>> matrix(query.size() + 1);

    // initialize the matrix for holding gap initialization states
    // contains '.', 'v', or '>', for ungapped, query gap, and subject gap
    std::vector<std::vector<char>> delmat(query.size() + 1);

    int gap_penalty[2];
    gap_penalty[0] = GAP_EXTEND_PENALTY;
    gap_penalty[1] = GAP_OPEN_PENALTY;

    // fill score matrix
    //  * initialize the first row of the insertion state matrix with '>'
    //    > against - is 0 , you agree with the subject gap
    //    v against - is (-2/-12), you are extending the gap with a new deletion event
    std::vector<char> firstRowDelmat(subject.size()+1, '>');
    delmat[0] = firstRowDelmat;
    //  * initialize the first row to values [0,-1,-2,..]
    std::vector<int> firstRowScores(subject.size() + 1, 0);
    matrix[0] = firstRowScores;
    for (size_t i = 1; i < query.size() + 1; i++){
        // initialize ith row of the score matrix
        std::vector<int> row(subject.size() + 1);
        matrix[i] = row;
        // initialize ith row of the insertion state matrix
        std::vector<char> delrow(subject.size() + 1);
        delmat[i] = delrow;
        // initialize the first value in the score matrix
        matrix[i][0] = 0;

        for (size_t j = 1; j < subject.size() + 1; j++){
            if (i == query.size()){
                matrix[i][j] = matrix[i][j-1]; // if we are at the bottom, just slide along with no additional penalties
                                               // there is no penalty for being truncated
            } else {

                // adding a query gap is free if the subject is a gap, otherwise
                // the cost depends on whether the gap is being opened or extended
                int down = matrix[i-1][j] + gap_penalty[ delmat[i-1][j] != 'v' ] * (subject[j-1] != 'Z');
                int over = matrix[i][j-1] + gap_penalty[ delmat[i][j-1] != '>' ];
                int diag = matrix[i-1][j-1] + BLOSUM90[query[i-1] - 65][subject[j-1] - 65];

                if (diag >= down && diag >= over){
                    delmat[i][j] = '.';
                    matrix[i][j] = diag;
                } else if (down >= over){
                    delmat[i][j] = 'v';
                    matrix[i][j] = down;
                } else {
                    delmat[i][j] = '>';
                    matrix[i][j] = over;
                }
            }
        }
    }

    // dump_score_matrix(matrix, query, subject);

    std::string alignment;

    // trace back
    size_t i = query.size();
    size_t j = subject.size();
    int inserted = 0;
    while (i > 0 || j > 0){
        if(i == 0){
             std::cout << "initial gap: " << "(" << i << "," << j << ")" << std::endl;
             alignment.push_back('-');
             j--;
        }
        else if(j == 0){
             // add value to the insert vector
             inserted--;
             std::cout << "insert " << query[i-1] << " " << inserted << "residues from " << j << std::endl;
             // alignment.inserts.push_back(Inserted {query[i], j, inserted});
             i--;
        } else {

            int delete_score = matrix[i-1][j];
            int match_score = matrix[i-1][j-1];
            int insert_score = matrix[i][j-1];
            if (delete_score > match_score && delete_score > insert_score){
                // // add value to the insert vector
                inserted++;
                std::cout << "insert " << query[i-1] << " " << inserted << "residues from " << j << std::endl;
                // alignment.inserts.push_back(Inserted {query[i], j, inserted});
                i--;
            } else {
                if (match_score >= insert_score){
                    std::cout << "match: " << match_score << "(" << i << "," << j << ")" << std::endl;
                    alignment.push_back(query[i-1]);
                    i--;
                    j--;
                    inserted = 0;
                } else {
                    std::cout << "gap: " << match_score << "(" << i << "," << j << ")" << std::endl;
                    alignment.push_back('-');
                    j--;
                    inserted = 0;
                }
            }
        }
    }

    std::cout << alignment << std::endl;
}

#endif
