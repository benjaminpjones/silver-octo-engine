#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "stream_reader.hpp"

TEST_CASE("BlockReader") {
    BlockReader reader("jack6400");

    char buffer[4096];

    REQUIRE(4096 == reader.getBlock(buffer));
    REQUIRE(2304 == reader.getBlock(buffer));

    REQUIRE(buffer[2303] == '\n');

    REQUIRE_THAT(buffer, Catch::StartsWith("0x0040 All work and no play"));
}

// This case tests the simple case where the requests all align with
// 4096
TEST_CASE("StreamReader 6400/1024") {
    StreamReader reader("jack6400");
    char buffer[1024];
    
    REQUIRE(1024 == reader.getBytes(buffer, 1024));
    REQUIRE(1024 == reader.getBytes(buffer, 1024));

    REQUIRE_THAT(buffer, Catch::StartsWith("0x0010 All work and no play"));

    REQUIRE(1024 == reader.getBytes(buffer, 1024));
    REQUIRE(1024 == reader.getBytes(buffer, 1024));

    REQUIRE_THAT(buffer, Catch::StartsWith("0x0030 All work and no play"));

    REQUIRE(1024 == reader.getBytes(buffer, 1024));
    REQUIRE(1024 == reader.getBytes(buffer, 1024));

    REQUIRE_THAT(buffer, Catch::StartsWith("0x0050 All work and no play"));

    REQUIRE(256 == reader.getBytes(buffer, 1024)); // EOF

    REQUIRE_THAT(buffer, Catch::StartsWith("0x0060"));
    REQUIRE_THAT(buffer + 192, Catch::StartsWith("0x0063"));
}

// Covers the case where requests are not aligned with blocks
TEST_CASE("StreamReader 6400/3000") {
    StreamReader reader("jack6400");
    char buffer[3000];

    REQUIRE(3000 == reader.getBytes(buffer, 3000));
    REQUIRE(3000 == reader.getBytes(buffer, 3000));
    REQUIRE_THAT(buffer, Catch::StartsWith("       \n0x002f"));

    REQUIRE(400 == reader.getBytes(buffer, 3000)); // EOF
    REQUIRE_THAT(buffer, Catch::StartsWith("y.             \n0x005e"));
}

// Covers the case where requests are larger than one block
TEST_CASE("StreamReader 16000 / 9000") {
    StreamReader reader("jack16000");
    char buffer[9000];

    REQUIRE(9000 == reader.getBytes(buffer, 9000));
    REQUIRE_THAT(buffer + 4096, Catch::StartsWith("0x0040"));
    REQUIRE_THAT(buffer + 8192, Catch::StartsWith("0x0080"));

    REQUIRE(7000 == reader.getBytes(buffer, 9000)); // EOF

    REQUIRE_THAT(buffer, Catch::StartsWith(" dull boy."));
    REQUIRE_THAT(buffer + 7000 - 64, Catch::StartsWith("0x00f9"));
}
