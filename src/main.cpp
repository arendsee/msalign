#include "needleman_wunsch.cpp"
#include <pybind11/pybind11.h>

std::string align(std::string query, std::string subject){
    NeedlemanWunsch nw = NeedlemanWunsch(query, subject);
    return nw.alignment;
}

namespace py = pybind11;

PYBIND11_MODULE(msalign, m){
    m.doc() = "msalign description"; // module documentation
    m.def( "align"
         , &align
         , "The alignment of a query to a subject"
         , py::arg("query")
         , py::arg("subject"));
}
