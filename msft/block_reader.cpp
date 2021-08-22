#include "stream_reader.hpp"

#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <memory>

using namespace std;

constexpr char JACK_STR[64] = "All work and no play makes Jack a dull boy."
                              "             \n";

struct BlockReader::Impl {
    size_t n_left=0;
    bool jack = false;
    size_t line_no = 0;
};

BlockReader::~BlockReader() {};

BlockReader::BlockReader(string filename) : pImpl(new Impl) {
    // Passing a file named jackXXXXX (e.g. jack4096.txt) will emulate a file
    // where each line is "All work and no play..."
    // Each line is padded so that it is 64 bytes long.
    // XXX must contain a number that is a multiple of 64.
    if (equal(filename.begin(), filename.begin() + 4, "jack")) {
        pImpl->jack = true;
        pImpl->n_left = std::stol(filename.substr(4));
    }
}

size_t BlockReader::getBlock(char* buffer) {
    if (pImpl->jack) {
        size_t result = 0;
        while (pImpl->n_left >= 64 && result < 4096) {
            stringstream stream;
            stream << "0x";
            stream << setfill('0') << setw(4)<< hex << pImpl->line_no;
            stream << ' ' << JACK_STR;
            std::string str( stream.str() );

            copy(str.begin(), str.begin() + 64, buffer);

            buffer += 64;
            pImpl->line_no += 1;
            result += 64;
            pImpl->n_left -= 64;
        }

        return result;
    }

    return 0;
}
