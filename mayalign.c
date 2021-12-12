#define MAX_POS = 3

// * check to ensure the msa is of the same length
// * translate from AA to 0-22, fail if any characters are invalid
char** prepareMSA(char** msa);

// convert from input aa sequence to 0-22 values (fail if an internal stop is observed)
char* aa2idx(char*);
  // this will be a big case-switch statement that should accept lowercase and irregular gaps like '.' or '_'

// calculate the length of char array
char* length(char*);


// build a suffix tree containing all the reference sequences, these can be piped through one at a time
SuffixTree* make_suffix_tree(char**, size_t n, bool direction);

// 0  STOP   -- yes, this conflicts with the string terminator, but it is also the translation terminator, if the alignment contains a stop, an error should be raised
// 1  A
// 2  C
// 3  D
// 4  E
// 5  F
// 6  G
// 7  H
// 8  I
// 9  K
// 10 L
// 11 M
// 12 N
// 13 P
// 14 Q
// 15 R
// 16 S
// 17 T
// 18 V
// 19 W
// 20 Y
// 21 Unk
// 22 Gap

typedef struct Node{
    char* str;
    Hit pos[MAX_POS];
    size_t npos; // total number of columns with this suffix
    Node* kids[23] // this requires extra memory, but allows
} Node;

typedef struct Hit{
    size_t pos;
    size_t 
} Hit;

typedef struct Anchor{
    size_t a;
    size_t b;
    double score;
} Anchor;

typedef struct Anchors{
    Anchor* anchors;
    size_t n;
} Anchors;

// Find regions with high conservation. Return the sorted anchors, best anchor first.
Anchors findAnchors(char**);

// These are positions in the query that are insertions, the are removed.
// Adding them back in would require inserting a gap across the entire reference MSA
typedef struct Insert{
    char insert_value;
    size_t insert_pos;
} Insert;

typedef struct Inserts{
    Insert* inserts;
    size_t n;
} Inserts;

typedef struct RelativeAlignment{
    char* alignment;
    Inserts inserts; 
} RelativeAlignment;

RelativeAlignment align(char* query, Anchors, SuffixTree* st);

// algorithm - divide and conquer around anchor points
// take the anchor with the highest score
// split the query at the anchor midpoint, search forwards with the forward suffix tree and backwards with the backwargs suffix tree
// join the two results


/* // starting from the longest match, extend forward and backwards           */
/* extend(Matches)                                                            */
/*  [> ((MMM*[^-]|MMM*-+)*MMM) match <]                                       */
/*                                                                            */
/* // find the global longest sequence, split on it, recurse into either side */

/*
A/swine/Iowa/A0 SSWPNHDTNRGVTAACPHAGTNSFYRNLIWLVKKGNLYPKINKSYINNKEKEVLVLWAIH
A/swine/Illinoi SSWLNHDTNKGVTAACPHAGTNSFYRNLVWLVKKGNSYPKINKSYTNNKEKEVLVLWAIH
A/swine/Manitob SSWPNHKT--GVTASCPYAGASSFYRNLMWLVKKDDSYPRLNISYVNNKRKEVLVLWGIH
A/swine/Manitob SSWPNHKT--GVTASCPYAGASSFYRNLMWLVKKGDSYPRLNISYVNNKRKEVLVLWGIH
A/swine/Iowa/A0 SSWPNHDSNKGVTAACPHAGAKSFYKNLIWLVKKGNSYPKLSNSYINDKGKEVLVLWGIH
A/swine/North_C SSWPNHKT--GVTASCPDAGARSFYRNLMWLVKKGDSYPRLNISYVNNKRKEVLVIWGIH
A/swine/Mexico/ SSWPSHETDRGVTAACPHDGASSFYRNLIWLVKKGNSYPKLRKSYINNKGKEVLVLWGIH
A/swine/Manitob SSWPNHKT--GVTASCPYAGASSFYRNLIWLVKKDDSYPMLNISYVNNKRKEVLVLWGIH
A/swine/Ontario SSWPNHETNRGTTAACPYAGANSFYRNLIWLVKKGNSYPKLNKSYVNNKGKEVLVLWGIH
A/swine/Wiscons SSWPNHETNRGVTAACPYAGANSFYRNLIWLVKKGNSYPKLSKSYVNNKGKEVLVLWGIH
A/swine/Iowa/19 SSWPNHETTRGVTAACPYAGASSFYRNLLWLVKKGNSYPKLSKSYVNNKGKEVLVLWGVH
A/swine/Saskatc SSWPNHET--GVTASCPYAGKSSFYRNLMWLVKKDNSYPRLNISYVNNKGKEVLVLWGIH
A/swine/Iowa/A0 SSWPNHDTNRGVTAACPHAGTNSFYRNLIWLVKKGNSYPKINKSYINNKEKEVLVLWAIH
                 **  :.   * : :*.  *  .**.* :*:.::
----------------------------------------------------------------------------
query           NSWPNHDTNKGVTAACPYAGANSFYRNLIWLVKKENSYPKLSKSYINNKKREVLVIWGIH
*/
