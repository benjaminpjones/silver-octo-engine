#ifndef STREAM_READER_HPP
#define STREAM_READER_HPP

#include <string>

class BlockReader {
public:
    // Constructs a reader that will read the file specified by filepath
    BlockReader(std::string filepath);

    ~BlockReader();

    // Populates buffer with the next block of data from the file.  A block is
    // 4098 bytes long unless we have reached the end of the file.
    //
    // Returns: number of bytes that have been populated.    
    size_t getBlock(char* buffer);

private:
    // Private implementation
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};

// A wrapper for BlockReader that allows the user to specify the number
// of bytes to read at one time.
class StreamReader {
public:
    // Constructs a reader that will read the file specified by filepath
    StreamReader(std::string filepath) : block_reader(filepath) { }

    // Populates buffer with the next n_bytes of data from the file unless we
    // have reached the end of the file.
    //
    // Returns: number of bytes that have been populated.    
    size_t getBytes(char* buffer, size_t n_bytes) {
        // Challenge: implement this function
        // You may modify the class as necessary (e.g. adding member variables)
        return 0;
    }

private:
    BlockReader block_reader;
};

#endif  // STREAM_READER_HPP
