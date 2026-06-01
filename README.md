# NLP-CPP 🚀

A high-performance, NLTK-inspired NLP toolkit implemented in **C++** with **Python bindings** for faster classical NLP workflows.

NLP-CPP is designed to bring the performance of native C++ to common Natural Language Processing (NLP) tasks while remaining easy to use from Python.

## Features

* ✅ Word Tokenization
* ✅ Sentence Tokenization
* ✅ Stopword Removal
* ✅ Frequency Distribution
* ✅ Porter-Inspired Stemmer
* ✅ Lemmatizer
* ✅ Rule-Based POS Tagging
* ✅ Named Entity Recognition (NER)
* ✅ Python Bindings (pybind11)
* ✅ pip-installable Package
* ✅ Benchmarking vs NLTK
* ✅ Unit Tests

---

## Why NLP-CPP?

Many classical NLP workflows rely on Python implementations that are easy to use but slower for large-scale text processing.

NLP-CPP aims to provide:

* Faster execution through native C++ implementation
* Python interoperability via pybind11
* Familiar NLP workflow components
* Clean modular architecture
* Benchmark-driven optimization

---

## Project Architecture

```text
Text
 ↓
Tokenizer
 ↓
Stopword Removal
 ↓
Stemmer / Lemmatizer
 ↓
POS Tagger
 ↓
Named Entity Recognition
```

---

## Benchmark

### Tokenization Benchmark

Benchmark performed on identical input (~500,000 tokens).

| Library | Time       |
| ------- | ---------- |
| NLTK    | 1.8797 sec |
| NLP-CPP | 0.1975 sec |

### Result

**~9.5× faster than NLTK in tested workload**

Benchmark command:

```bash
python benchmark_vs_nltk.py
```

> Note: Performance varies depending on dataset, hardware, workload, and tokenizer complexity.

---

## Project Structure

```text
nlp-cpp/
│
├── benchmarks/
│   └── benchmark_tokenizer.cpp
│
├── include/
│   └── nlp_cpp/
│       ├── tokenizer.hpp
│       ├── stopwords.hpp
│       ├── freqdist.hpp
│       ├── stemmer.hpp
│       ├── lemmatizer.hpp
│       ├── pos_tagger.hpp
│       └── ner.hpp
│
├── nlp_cpp/
│   └── __init__.py
│
├── src/
│   ├── bindings.cpp
│   ├── tokenizer.cpp
│   ├── stopwords.cpp
│   ├── freqdist.cpp
│   ├── stemmer.cpp
│   ├── lemmatizer.cpp
│   ├── pos_tagger.cpp
│   ├── ner.cpp
│   └── main.cpp
│
├── tests/
│   └── nlp_cpp_test.cpp
│
├── benchmark_vs_nltk.py
├── CMakeLists.txt
├── pyproject.toml
├── setup.py
├── README.md
└── .gitignore
```

---

## Installation

### Clone Repository

```bash
git clone https://github.com/shub-gour/nlp-cpp.git
cd nlp-cpp
```

### Install Python Package

```bash
pip install .
```

---

## Build From Source (C++)

### Create Build Folder

```bash
mkdir build
cd build
```

### Configure

#### Windows (MinGW)

```bash
cmake .. -G "MinGW Makefiles"
```

#### Linux / macOS

```bash
cmake ..
```

### Build

```bash
cmake --build .
```

---

## Usage Examples

### Tokenization

```python
import nlp_cpp

tokens = nlp_cpp.word_tokenize(
    "I love NLP in C++"
)

print(tokens)
```

Output:

```python
['I', 'love', 'NLP', 'in', 'C++']
```

---

### Sentence Tokenization

```python
import nlp_cpp

sentences = nlp_cpp.sent_tokenize(
    "Hello world. NLP is fun."
)

print(sentences)
```

Output:

```python
[
    'Hello world',
    'NLP is fun'
]
```

---

### Stopword Removal

```python
import nlp_cpp

tokens = [
    "this",
    "is",
    "an",
    "example"
]

print(
    nlp_cpp.remove_stopwords(tokens)
)
```

---

### Frequency Distribution

```python
import nlp_cpp

tokens = [
    "apple",
    "banana",
    "apple"
]

print(
    nlp_cpp.freq_dist(tokens)
)
```

---

### Stemming

```python
import nlp_cpp

print(
    nlp_cpp.stem("running")
)

print(
    nlp_cpp.stem("hopping")
)
```

Output:

```python
run
hop
```

---

### Lemmatization

```python
import nlp_cpp

print(
    nlp_cpp.lemmatize("mice")
)

print(
    nlp_cpp.lemmatize("children")
)
```

Output:

```python
mouse
child
```

---

### POS Tagging

```python
import nlp_cpp

tokens = [
    "I",
    "love",
    "coding",
    "quickly"
]

print(
    nlp_cpp.pos_tag(tokens)
)
```

Output:

```python
[
    ('I', 'PRON'),
    ('love', 'VERB'),
    ('coding', 'VERB'),
    ('quickly', 'ADV')
]
```

---

### Named Entity Recognition (NER)

```python
import nlp_cpp

tokens = [
    "Elon",
    "Musk",
    "works",
    "at",
    "Tesla",
    "in",
    "New",
    "York"
]

print(
    nlp_cpp.ner(tokens)
)
```

Output:

```python
[
    ('Elon Musk', 'PERSON'),
    ('works', 'O'),
    ('at', 'O'),
    ('Tesla', 'ORG'),
    ('in', 'O'),
    ('New York', 'LOCATION')
]
```

---

## Running Tests

Build project first:

```bash
cmake --build .
```

Run tests:

### Windows

```bash
./test_app.exe
```

### Linux / macOS

```bash
./test_app
```

---

## Running Benchmark

```bash
python benchmark_vs_nltk.py
```

---

## Roadmap

* [ ] Smarter tokenizer (contractions, punctuation, decimals)
* [ ] Better POS tagging
* [ ] Improved NER
* [ ] More stemming rules
* [ ] Better lemmatization
* [ ] SIMD optimization
* [ ] Multithreading support
* [ ] Additional benchmarks
* [ ] PyPI release

---

## Contributing

Contributions are welcome.

Feel free to:

* Open issues
* Suggest improvements
* Submit pull requests

Areas where contributions are especially welcome:

* NLP improvements
* Performance optimization
* Benchmarking
* Testing
* Python packaging
* Documentation

---

## Tech Stack

* C++17
* pybind11
* CMake
* Python
* MinGW (Windows build)
* Benchmarking and unit testing

---

## Disclaimer

NLP-CPP is currently an educational and engineering-focused project inspired by classical NLP tooling. It is **not a full replacement for NLTK** and is under active development.

---

## Author

**Shubham Gour**

If you found this project interesting, consider starring the repository ⭐
