from setuptools import setup, find_packages

setup(
    name="nlp_cpp",
    version="0.1.0",
    description="High-performance NLP library in C++",
    author="Shubham Gour",
    packages=find_packages(),
    package_data={
        "nlp_cpp":["*.pyd","*.dll"]
    },
    include_package_data=True
)