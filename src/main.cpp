#include "needleman_wunsch.cpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(msalign, m){
    m.doc() = "msalign description"; // module documentation

    py::class_<NeedlemanWunsch>(m, "NeedlemanWunsch")
        .def(py::init<std::string, std::string>())
        .def("get_query", &NeedlemanWunsch::get_query)
        .def("get_subject", &NeedlemanWunsch::get_subject)
        .def("get_alignment", &NeedlemanWunsch::get_alignment)
        .def("get_insertions", &NeedlemanWunsch::get_insertions)
        .def("get_matrix", &NeedlemanWunsch::get_matrix);
}
