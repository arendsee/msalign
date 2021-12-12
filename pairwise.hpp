#ifndef __PAIRWISE_HPP__
#define __PAIRWISE_HPP__

#include <iostream>
#include <vector>
#include <string>

#define GAP_OPEN_PENALTY = -12
#define GAP_CONT_PENALTY = -1

// gap open costs -12
// gap extension costs -2

//    -    H    K    T    -    -    G    V    T    A
// -  0  >-1  >-2  >-3  >-3  >-3  >-4  >-5  >-6  >-7
// H -1    8  >-4  >-5  >-5  >-5  >-6  >-7  >-8  >-9
// E -2   v4    8   >4   -4   -4   -5   -6   -7   -8
// T -3   -5   v4   14   14   14   13   12   11   10
// D -4   -6   -5   12   14   14   13   12   11   10
// R -5   -4   -4    0    0   14   13   12   11   10
// G -6   -8   -6   -7   -7   -7   20    8    7    7
// V -7   -10
// V -8
// T -9
// A -10
//

// > against - is 0 , you agree with the subject gap
// v against - is (-2/-12), you are extending the gap with a new deletion event
// . against - is -1, you are filling the gap



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


void needleman_wunsch(std::string query, std::string subject){

    // initialize the matrix for holding the scores
    std::vector<std::vector<int>> matrix(query.size());

    // initialize the matrix for holding gap initialization states
    // contains '.', 'v', or '>', for ungapped, query gap, and subject gap
    std::vector<std::vector<char>> delmat(query.size());

    int gap_penalty[2];
    gap_penalty[0] = -2;
    gap_penalty[1] = -12;

    // fill score matrix
    //  * initialize the first row of the insertion state matrix with '>'
    std::vector<char> firstRowDelmat(subject.size(), '>');
    delmat[0] = firstRowDelmat;
    //  * initialize the first row to values [0,-1,-2,..]
    std::vector<int> firstRowScores(subject.size());
    for (size_t i = 0; i < subject.size(); i++){
        firstRowScores[i] = -1 * i;
    }
    matrix[0] = firstRowScores;
    for (size_t i = 1; i < query.size(); i++){
        // initialize ith row of the score matrix
        std::vector<int> row(subject.size());
        matrix[i] = row;
        // initialize ith row of the insertion state matrix
        std::vector<char> delrow(subject.size());
        delmat[i] = delrow;
        // initialize the first value in the score matrix
        matrix[i][0] = -1 * i;

        for (size_t j = 1; j < subject.size(); j++){
            // adding a query gap is free if the subject is a gap, otherwise
            // the cost depends on whether the gap is being opened or extended
            int down = matrix[i-1][j] + gap_penalty[ delmat[i-1][j] == 'v' ] * (subject[j] == '-');
            int over = matrix[i][j-1] + gap_penalty[ delmat[i][j-1] == '>' ];
            int diag = matrix[i-1][j-1] + 5; // score[query[i]][subject[j]];

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

    // print the score matrix
    std::cout << ". ";
    for (size_t i = 0; i < subject.size(); i++){
        std::cout << subject[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < query.size(); i++){
        std::cout << query[i] << " ";
        for(size_t j = 0; j < subject.size(); j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // // trace back
    // size_t i = query.size();
    // size_t j = subject.size();
    // size_t inserted = 0;
    // while (j > 0){
    //     int delete_score = matrix[i-1][j];
    //     int match_score = matrix[i-1][i-1];
    //     int insert_score = matrix[i][j-1];
    //     if (delete_score > match_score && delete_score > insert_score){
    //         // add value to the insert vector
    //         inserted++;
    //         alignment.inserts.push_back(Inserted {query[i], j, inserted});
    //         i--;
    //     } else {
    //         if (match_score >= insert_score){
    //             alignment.alignment.push_back(query[i]);
    //             i--;
    //             j--;
    //             inserted = 0;
    //         } else {
    //             alignment.alignment.push_back('-');
    //             j--;
    //             inserted = 0;
    //         }
    //     }
    // }
    //
    // return alignment
}

#endif
