
#include "doctest.h"
#include "Notebook.hpp"
#include <iostream>
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

Notebook notebook;

TEST_CASE("write") {
	CHECK(notebook.write(9, 7, 6, Direction::Horizontal, "abc") == 0);
    CHECK(notebook.write(5, 7, 3, Direction::Horizontal, "hey") == 0);
    CHECK(notebook.write(1, 2, 6, Direction::Horizontal, "going") == 0);
    CHECK(notebook.write(3, 8, 3, Direction::Horizontal, "back") == 0);
    CHECK(notebook.write(2, 2, 2, Direction::Horizontal, "front") == 0);
}

TEST_CASE("erase") {
	CHECK(notebook.erase(9, 7, 6, Direction::Horizontal, 2) == 0);
    CHECK(notebook.erase(9, 7, 6, Direction::Horizontal, 4) == 0);
    CHECK(notebook.erase(9, 7, 6, Direction::Horizontal, 6) == 0);
    CHECK(notebook.erase(9, 7, 6, Direction::Horizontal, 8) == 0);
    CHECK(notebook.erase(9, 7, 6, Direction::Horizontal, 11) == 0);
}

TEST_CASE("Bad input for write") {
    CHECK_THROWS(notebook.write(-1, 7, 6, Direction::Horizontal, "xsa"));
    CHECK_THROWS(notebook.write(2, -3, 4, Direction::Horizontal, "xsa"));
    CHECK_THROWS(notebook.write(22, 3, -11, Direction::Horizontal, ""));
    CHECK_THROWS(notebook.write(-6, -9, 14, Direction::Horizontal, "xsa"));
    CHECK_THROWS(notebook.write(-1, 3, -75, Direction::Horizontal, "xsa"));
    CHECK_THROWS(notebook.write(1, -20, -100, Direction::Horizontal, "xsa"));
    CHECK_THROWS(notebook.write(-23, -34, -16, Direction::Horizontal, "xsa"));
    CHECK_THROWS(notebook.write(0, -1, 3, Direction::Horizontal, "xsa"));
    CHECK_THROWS(notebook.write(4, 0, 2, Direction::Horizontal, "xsa"));
    CHECK_THROWS(notebook.write(17, -19, 25, Direction::Horizontal, "xsa"));
}

TEST_CASE("Bad input for read") {
    CHECK_THROWS(notebook.read(-1, 7, 6, Direction::Horizontal, 0));
    CHECK_THROWS(notebook.read(2, -3, 4, Direction::Horizontal, 0));
    CHECK_THROWS(notebook.read(22, 3, -11, Direction::Horizontal, 0));
    CHECK_THROWS(notebook.read(-6, -9, 14, Direction::Horizontal, 2));
    CHECK_THROWS(notebook.read(-1, 3, -75, Direction::Horizontal, 3));
    CHECK_THROWS(notebook.read(1, -20, -100, Direction::Horizontal, 1));
    CHECK_THROWS(notebook.read(-23, -34, -16, Direction::Horizontal, 0));
    CHECK_THROWS(notebook.read(0, -1, 3, Direction::Horizontal, 6));
    CHECK_THROWS(notebook.read(4, 0, 2, Direction::Horizontal, 2));
    CHECK_THROWS(notebook.read(17, -19, 25, Direction::Horizontal, 1));
}

TEST_CASE("Bad input for erase") {
    CHECK_THROWS(notebook.erase(-1, 7, 6, Direction::Horizontal, 0));
    CHECK_THROWS(notebook.erase(2, -3, 4, Direction::Horizontal, 0));
    CHECK_THROWS(notebook.erase(22, 3, -11, Direction::Horizontal, 1));
    CHECK_THROWS(notebook.erase(-6, -9, 14, Direction::Horizontal, 8));
    CHECK_THROWS(notebook.erase(-1, 3, -75, Direction::Horizontal, 0));
    CHECK_THROWS(notebook.erase(1, -20, -100, Direction::Horizontal, 0));
    CHECK_THROWS(notebook.erase(-23, -34, -16, Direction::Horizontal, 0));
    CHECK_THROWS(notebook.erase(0, -1, 3, Direction::Horizontal, 0));
    CHECK_THROWS(notebook.erase(4, 0, 2, Direction::Horizontal, 0));
    CHECK_THROWS(notebook.erase(17, -19, 25, Direction::Horizontal, 2));
}