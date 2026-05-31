#include "../include/nlp_cpp/stemmer.hpp"

namespace nlp_cpp {

    std::string stem(
        const std::string& word
    ) {

        std::string result = word;

        if (result.length() > 4 &&
            result.substr(
                result.length() - 3
            ) == "ing") {

            result =
                result.substr(
                    0,
                    result.length() - 3
                );
        }

        else if (result.length() > 3 &&
                 result.substr(
                     result.length() - 2
                 ) == "ed") {

            result =
                result.substr(
                    0,
                    result.length() - 2
                );
        }

        else if (result.length() > 2 &&
                 result.back() == 's') {

            result.pop_back();
        }

        if (result.length() >= 2 &&
            result.back() ==
            result[result.length() - 2]) {

            result.pop_back();
        }

        return result;
    }

}