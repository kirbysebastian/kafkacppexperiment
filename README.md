# Installation of Dependencies
- sudo apt-get install librdkafka-dev -y
- sudo apt-get install libboost-all-dev

## C++ Library on top of librdkafka
https://github.com/mfontanini/cppkafka
- Create build folder
- Go to build dir
- cmake -DRDKAFKA_ROOT=/some/other/dir -DCPPKAFKA_BUILD_SHARED=OFF ...
- make
- make install
