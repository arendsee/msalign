#include <needleman_wunsch.cpp>
#include <pybind11/pybind11.h>

std::string align(std::string query, std::string subject){
    NeedlemanWunsch nw = NeedlemanWunsch(query, subject);
    return nw.alignment;
}

PYBIND11_MODULE(msalign_cpp, m){
    m.doc() = "msalign description"; // module documentation
    m.def("align", &align, "The alignment of a query to a subject");
}
