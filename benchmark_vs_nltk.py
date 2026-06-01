import time
import nltk
import nlp_cpp

text = "Hello world I love NLP " * 100000


# -------------------------
# NLTK benchmark
# -------------------------

start = time.perf_counter()

nltk_tokens = nltk.word_tokenize(text)

end = time.perf_counter()

nltk_time = end - start


# -------------------------
# NLP-CPP benchmark
# -------------------------

start = time.perf_counter()

cpp_tokens = nlp_cpp.word_tokenize(text)

end = time.perf_counter()

cpp_time = end - start


# -------------------------
# Results
# -------------------------

speedup = nltk_time / cpp_time

print("===== BENCHMARK =====")
print()

print(f"NLTK time: {nltk_time:.4f} sec")
print(f"NLP-CPP time: {cpp_time:.4f} sec")

print()
print(f"Speedup: {speedup:.2f}x")

print()
print("Token counts:")
print("NLTK:", len(nltk_tokens))
print("NLP-CPP:", len(cpp_tokens))