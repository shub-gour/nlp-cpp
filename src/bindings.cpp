#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../include/nlp_cpp/tokenizer.hpp"
#include "../include/nlp_cpp/stopwords.hpp"
#include "../include/nlp_cpp/freqdist.hpp"
#include "../include/nlp_cpp/stemmer.hpp"
#include "../include/nlp_cpp/lemmatizer.hpp"
#include "../include/nlp_cpp/pos_tagger.hpp"

namespace py = pybind11;

PYBIND11_MODULE(nlp_cpp, m) {

    m.doc() =
        "High-performance NLP library in C++";

    m.def(
        "word_tokenize",
        &nlp_cpp::word_tokenize
    );

    m.def(
        "sent_tokenize",
        &nlp_cpp::sent_tokenize
    );

    m.def(
        "remove_stopwords",
        &nlp_cpp::remove_stopwords
    );

    m.def(
        "freq_dist",
        &nlp_cpp::freq_dist
    );

    m.def(
        "stem",
        &nlp_cpp::stem
    );

    m.def(
        "lemmatize",
        &nlp_cpp::lemmatize
    );

    m.def(
        "pos_tag",
        &nlp_cpp::pos_tag
    );
    
}