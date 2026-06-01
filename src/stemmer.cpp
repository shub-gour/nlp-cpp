#include "../include/nlp_cpp/stemmer.hpp"

namespace nlp_cpp
{

    std::string stem(
        const std::string &word)
    {

        std::string result = word;

        // -----------------------
        // STEP 1A
        // -----------------------

        if (result.length() > 4 &&
            result.substr(
                result.length() - 4) == "sses")
        {

            result =
                result.substr(
                    0,
                    result.length() - 2);
        }

        else if (result.length() > 3 &&
                 result.substr(
                     result.length() - 3) == "ies")
        {

            result =
                result.substr(
                    0,
                    result.length() - 3) +
                "i";
        }

        else if (result.length() > 2 &&
                 result.substr(
                     result.length() - 2) == "ss")
        {

            return result;
        }

        else if (result.length() > 1 &&
                 result.back() == 's')
        {

            result.pop_back();
        }

        // -----------------------
        // STEP 1B
        // -----------------------

        bool removed_suffix = false;

        if (result.length() > 4 &&
            result.substr(
                result.length() - 3) == "ing")
        {

            result =
                result.substr(
                    0,
                    result.length() - 3);

            removed_suffix = true;
        }

        else if (result.length() > 3 &&
                 result.substr(
                     result.length() - 2) == "ed")
        {

            result =
                result.substr(
                    0,
                    result.length() - 2);

            removed_suffix = true;
        }

        // -----------------------
        // POST PROCESSING
        // -----------------------


        if (removed_suffix)
        {

            // at -> ate
            if (result.length() >= 2 &&
                result.substr(
                    result.length() - 2) == "at")
            {

                result += "e";
            }

            // bl -> ble
            else if (result.length() >= 2 &&
                     result.substr(
                         result.length() - 2) == "bl")
            {

                result += "e";
            }

            // iz -> ize
            else if (result.length() >= 2 &&
                     result.substr(
                         result.length() - 2) == "iz")
            {

                result += "e";
            }

            // double consonant
            else if (result.length() >= 2 &&
                     result.back() ==
                         result[result.length() - 2])
            {

                result.pop_back();
            }

            // special case: filing -> file
            else if (result == "fil")
            {

                result = "file";
            }
        }

        return result;
    }

}