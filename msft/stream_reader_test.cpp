#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "stream_reader.hpp"

TEST_CASE("BlockReader") {
    BlockReader reader("jack6400");

    char buffer[4096];

    REQUIRE(4096 == reader.getBlock(buffer));
    REQUIRE(2304 == reader.getBlock(buffer));

    REQUIRE_THAT(buffer, Catch::StartsWith("0x0040 All work and no play makes Jack a dull boy."));
}
