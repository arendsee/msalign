from setuptools import setup
from pybind11 import get_cmake_dir
# Available at setup time due to pyproject.toml
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [Pybind11Extension("rpalign", ["src/main.cpp"])]

with open("README.md", "r") as fh:
    long_description = fh.read()

setup(
    name="rpalign",
    version="0.1.0",
    description="Align novel sequences against a reference multiple sequence alignment",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/arendsee/rpalign",
    author="Zebulun Arendsee",
    author_email="zebulun.arendsee@usda.gov",
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    ext_modules=ext_modules,
    python_requires=">=3.6",
)
