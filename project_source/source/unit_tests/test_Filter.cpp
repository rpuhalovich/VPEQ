#include <Catch2/catch.hpp>
#include "Filter.hpp"

Filter filter;

TEST_CASE("testing sum") {
    REQUIRE(filter.sum(1, 1) == 2); // pass
    REQUIRE(filter.sum(1, 2) == 2); // fail
}