#ifndef STOPWORDS_HPP
#define STOPWORDS_HPP

#include <string>
#include <vector>

namespace nlp_cpp {

    std::vector<std::string> remove_stopwords(
        const std::vector<std::string>& tokens
    );

}

#endif