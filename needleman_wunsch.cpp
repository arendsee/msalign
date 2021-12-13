#include "needleman_wunsch.hpp"
#include "substitution_matrix.hpp"

std::vector<std::vector<int>> needleman_wunsch_matrix(std::string query, std::string subject);

std::string cleanSeq(std::string x, bool is_query);

std::tuple<std::string, std::vector<std::tuple<char, size_t, int>>>
needleman_wunsch_traceback
  ( std::vector<std::vector<int>> matrix
  , std::string query
  , std::string subject
  );



NeedlemanWunsch::NeedlemanWunsch(std::string queryIn, std::string subjectIn){
    query = queryIn;
    subject = subjectIn;

    // build the dynamic programming score matrix
    matrix = needleman_wunsch_matrix(query, subject);

    // find the traceback alignment and the insertion vector
    std::tuple<std::string, std::vector<std::tuple<char, size_t, int>>> traceback = needleman_wunsch_traceback(matrix, query, subject);
    alignment = std::get<0>(traceback);
    insertions = std::get<1>(traceback);
}



std::vector<std::vector<int>> needleman_wunsch_matrix(std::string query, std::string subject){

    // cleanSeq is defined in substitution_matrix.hpp. It transforms the
    // strings for efficient use in substitution matrix lookup.
    std::string queryClean = cleanSeq(query, true);
    std::string subjectClean = cleanSeq(subject, false);

    // initialize the matrix for holding the scores
    std::vector<std::vector<int>> matrix(queryClean.size() + 1);

    // initialize the matrix for holding gap initialization states
    // contains '.', 'v', or '>', for ungapped, query gap, and subject gap
    std::vector<std::vector<char>> delmat(queryClean.size() + 1);

    int gap_penalty[2];
    gap_penalty[0] = GAP_EXTEND_PENALTY;
    gap_penalty[1] = GAP_OPEN_PENALTY;

    // fill score matrix
    //  * initialize the first row of the insertion state matrix with '>'
    //    > against - is 0 , you agree with the subject gap
    //    v against - is (-2/-12), you are extending the gap with a new deletion event
    std::vector<char> firstRowDelmat(subjectClean.size()+1, '>');
    delmat[0] = firstRowDelmat;
    //  * initialize the first row to values [0,-1,-2,..]
    std::vector<int> firstRowScores(subjectClean.size() + 1, 0);
    matrix[0] = firstRowScores;
    for (size_t i = 1; i < queryClean.size() + 1; i++){
        // initialize ith row of the score matrix
        std::vector<int> row(subjectClean.size() + 1, 0);
        matrix[i] = row;
        // initialize ith row of the insertion state matrix
        std::vector<char> delrow(subjectClean.size() + 1, '.');
        delmat[i] = delrow;
        // initialize the first value in the score matrix
        matrix[i][0] = 0;

        for (size_t j = 1; j < subjectClean.size() + 1; j++){
            if (i == queryClean.size()){
                matrix[i][j] = matrix[i][j-1]; // if we are at the bottom, just slide along with no additional penalties
                                               // there is no penalty for being truncated
            } else {

                // adding a query gap is free if the subject is a gap, otherwise
                // the cost depends on whether the gap is being opened or extended
                int down = matrix[i-1][j] + gap_penalty[ delmat[i-1][j] != 'v' ] * !isGap(subjectClean[j-1]);
                int over = matrix[i][j-1] + gap_penalty[ delmat[i][j-1] != '>' ];
                int diag = matrix[i-1][j-1] + substitution_score(queryClean[i-1], subjectClean[j-1]);

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

    return matrix;
}



std::tuple<std::string, std::vector<std::tuple<char, size_t, int>>>
needleman_wunsch_traceback
  ( std::vector<std::vector<int>> matrix
  , std::string query
  , std::string subject
  )
{
    std::string alignment;

    std::vector<std::tuple<char, size_t, int>> inserts;

    // trace back
    size_t i = query.size();
    size_t j = subject.size();
    int insert_offset = 0;
    while (i > 0 || j > 0){
        if(i == 0){
             alignment.push_back('-');
             j--;
        }
        else if(j == 0){
             // add value to the insert vector
             insert_offset--;
             inserts.push_back(std::make_tuple(query[i-1], j, insert_offset));
             i--;
        } else {

            int delete_score = matrix[i-1][j];
            int match_score = matrix[i-1][j-1];
            int insert_score = matrix[i][j-1];
            if (delete_score > match_score && delete_score > insert_score){
                // add value to the insert vector
                insert_offset++;
                inserts.push_back(std::make_tuple(query[i-1], j, insert_offset));
                i--;
            } else {
                if (match_score >= insert_score){
                    alignment.push_back(query[i-1]);
                    i--;
                    j--;
                    insert_offset = 0;
                } else {
                    alignment.push_back('-');
                    j--;
                    insert_offset = 0;
                }
            }
        }
    }

    std::reverse(alignment.begin(), alignment.end());

    return std::make_tuple(alignment, inserts);
}



void NeedlemanWunsch::print_matrix(){
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

void NeedlemanWunsch::print_insertions(){
    for(size_t i = 0; i < insertions.size(); i++){
        char c = std::get<0>(insertions[i]);
        size_t pos = std::get<1>(insertions[i]);
        int offset = std::get<2>(insertions[i]);
        std::cout << c << "\t" << pos << "\t" << offset << std::endl;
    }
}
