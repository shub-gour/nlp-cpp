cmake_minimum_required(VERSION 3.10)

project(nlp_cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

# Main demo app
add_executable(app
    src/main.cpp
    src/tokenizer.cpp
    src/stopwords.cpp
    src/freqdist.cpp
    src/stemmer.cpp
)

# Tests
add_executable(test_app
    tests/nlp_cpp_test.cpp
    src/tokenizer.cpp
    src/stopwords.cpp
    src/freqdist.cpp
    src/stemmer.cpp
)

# Benchmark
add_executable(benchmark_tokenizer
    benchmarks/benchmark_tokenizer.cpp
    src/tokenizer.cpp
)