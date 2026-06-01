#include "../include/nlp_cpp/stemmer.hpp"

namespace nlp_cpp {

std::string stem(
    const std::string& word
) {

    std::string result = word;

    // -----------------------
    // STEP 1A
    // -----------------------

    // sses -> ss
    if (result.length() > 4 &&
        result.substr(
            result.length() - 4
        ) == "sses") {

        result =
            result.substr(
                0,
                result.length() - 2
            );
    }

    // ies -> i
    else if (result.length() > 3 &&
             result.substr(
                 result.length() - 3
             ) == "ies") {

        result =
            result.substr(
                0,
                result.length() - 3
            ) + "i";
    }

    // ss -> keep
    else if (result.length() > 2 &&
             result.substr(
                 result.length() - 2
             ) == "ss") {

        return result;
    }

    // s -> remove
    else if (result.length() > 1 &&
             result.back() == 's') {

        result.pop_back();
    }

    // -----------------------
    // STEP 1B
    // -----------------------

    bool removed_suffix = false;

    // ing
    if (result.length() > 4 &&
        result.substr(
            result.length() - 3
        ) == "ing") {

        result =
            result.substr(
                0,
                result.length() - 3
            );

        removed_suffix = true;
    }

    // ed
    else if (result.length() > 3 &&
             result.substr(
                 result.length() - 2
             ) == "ed") {

        result =
            result.substr(
                0,
                result.length() - 2
            );

        removed_suffix = true;
    }

    // remove double consonant
    if (removed_suffix &&
        result.length() >= 2 &&
        result.back() ==
        result[result.length() - 2]) {

        result.pop_back();
    }

    return result;
}

}