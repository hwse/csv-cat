# Building with CMake

    git clone https://github.com/hwse/csv-cat.git
    cd csv-cat
    git submodule update --init --recursive
    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release ..
    cmake --build .