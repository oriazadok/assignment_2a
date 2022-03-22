#include <iostream>
#include <string>
#include "Direction.hpp"
using namespace ariel;
using namespace std;

namespace ariel {
    class Notebook {
        public:

            Notebook();

            int write(int page, int row, int column, Direction dir, string content);
            string read(int page, int row, int column, Direction dir, int length);
            int erase(int page, int row, int column, Direction dir, int length);
            int show(int size);
    };
}