from setuptools import setup

from msalign.version import __version__

with open("README.md", "r") as fh:
    long_description = fh.read()

setup(
    name="msalign",
    version=__version__,
    description="Align novel sequences against a reference multiple sequence alignment",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/arendsee/msalign",
    author="Zebulun Arendsee",
    author_email="zebulun.arendsee@usda.gov",
    packages=["msalign"],
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    entry_points={"console_scripts": ["flutile=flutile.ui:main"]},
    py_modules=["msalign"],
    zip_safe=False,
    include_package_data=True,
)
