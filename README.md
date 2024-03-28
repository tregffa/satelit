# satelit

conan install . -s build_type=Debug --build=missing --output-folder=./cmake  \
rm CMakeUserPresets.json   \
cmake  -DCMAKE_TOOLCHAIN_FILE=cmake/build/Debug/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug   \
cmake --build .  \