#include "../string_distance.h"

#include "../test.h"

int main() { TEST(util::string_distance("black", "back"), 1); }