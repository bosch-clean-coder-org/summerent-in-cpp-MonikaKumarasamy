#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}
TEST_CASE("infers the breach according to limits1") {
  REQUIRE(inferBreach(32, 20, 30) == TOO_HIGH);
}
TEST_CASE("infers the breach according to limits2") {
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}
TEST_CASE("Return value depends on type of cooling") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 12) == inferBreach(12,0,35));
}

