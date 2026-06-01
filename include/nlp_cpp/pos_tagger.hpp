#ifndef POS_TAGGER_HPP
#define POS_TAGGER_HPP

#include <string>
#include <vector>
#include <utility>

namespace nlp_cpp {

    std::vector<
        std::pair<
            std::string,
            std::string
        >
    > pos_tag(
        const std::vector<
            std::string
        >& tokens
    );

}

#endif