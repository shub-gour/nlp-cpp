#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>

namespace nlp_cpp {

    std::vector<std::string> word_tokenize(
        const std::string& text
    );

    std::vector<std::string> sent_tokenize(
        const std::string& text
    );

}

#endif