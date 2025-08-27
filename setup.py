"""Build Python extension."""

import json
import os
from glob import glob
from pathlib import Path

from setuptools import Extension, setup
from setuptools.command.build_ext import build_ext


def main():
    """Python extension build entrypoint."""
    cwd = Path.cwd()
    #generate_json_schema_header()
    setup_args = {
        "ext_modules": [
            Extension(
                "cbxp._C",
                sources=(
                    glob("cbxp/**/*.cpp")
                    + glob("cbxp/*.cpp")
                    + ["cbxp/python/_cbxp.c"]
                ),
                include_dirs=(
                    glob("cbxp/**/")
                    + [
                        "cbxp",
                        "externals",
                        "/usr/include/zos"
                    ]
                ),
                extra_link_args=[
                    "-m64",
                    "-Wl,-b,edit=no",
                ],
                extra_compile_args=[
                    "-fzos-le-char-mode=ascii",
                    "-Wno-trigraphs"
                ]
            ),
        ],
        "cmdclass": {"build_ext": build_ext},
    }
    setup(**setup_args)


if __name__ == "__main__":
    main()
