#include <string>

using namespace std;

class BlockReader {
    // Constructs a reader that will read the file specified by filepath
    BlockReader(string filepath);

    // Populates buffer with the next block of data from the file.  A block is
    // 4098 bytes long unless we have reached the end of the file.
    //
    // Returns: number of bytes that have been populated.    
    size_t getBlock(char* buffer);
}

// A wrapper for BlockReader that allows the user to specify the number
// of bytes to read at one time.
class StreamReader {
public:
    // Constructs a reader that will read the file specified by filepath
    StreamReader(string filepath) : block_reader(filepath) { }

    // Populates buffer with the next n_bytes of data from the file unless we
    // have reached the end of the file.
    //
    // Returns: number of bytes that have been populated.    
    size_t getBytes(char* buffer, size_t n_bytes) {
        // Challenge: implement this function
        // You may modify the class as necessary (e.g. adding member variables)
    }

private:
    BlockReader block_reader;
}
