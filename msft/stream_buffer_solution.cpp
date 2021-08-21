#include <string>
#include <algorithm>

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
        size_t n_left = n_bytes;

        while (n_left) {
            if (n_left >= data_sz) {
                copy(data, data + data_sz, buffer)

                // Refill the internal buffer and increment relevant vars
                n_left -= data_sz;
                buffer += data_sz;

                data_sz = block_reader.getBlock(internal_buffer);

                // handle EOF
                if (!data_sz) {
                    return n_bytes - n_left;
                }

                data = internal_buffer;
            } else {
                copy(data, data + n_left, buffer);
                data += n_left;
                data_sz -= n_left;
                return n_bytes;
            }
        }
    }

private:
    BlockReader block_reader;
    char internal_buffer[4098];
    char* data;
    size_t data_sz = 0;
}
