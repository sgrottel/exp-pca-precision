# ex(p) p(ca) p(recision)
# Temporary experiment about numeric precision of my PCA implementation.
#
cmake_minimum_required(VERSION 3.2)

project("expp")

include_directories("extern/precision")

# Add source to this project's executable.
add_executable(expp "expp.cpp" "testdata.h" "testdata.cpp" "evaluator.h" "printHelper.h" "printHelper.cpp" "myIter.h")

# TODO: Add tests and install targets if needed.
