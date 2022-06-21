#include "ElementMap.h"
#include "State.h"

std::string ElementMap::programPath = "";
int main (int argc, char** argv) {
    ElementMap::programPath = argv[0];
    ElementMap emap;
    emap.printElementMap();
    State::elementMap = emap;
    return 0;
}