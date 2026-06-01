#ifndef NER_HPP
#define NER_HPP

#include <string>
#include <vector>
#include <utility>

namespace nlp_cpp {

    std::vector<
        std::pair<
            std::string,
            std::string
        >
    > ner(
        const std::vector<
            std::string
        >& tokens
    );

}

#endif