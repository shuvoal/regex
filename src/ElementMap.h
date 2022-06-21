#ifndef ELEMENTMAP_H
#define ELEMENTMAP_H
#include "common.h"

class ElementMap {
    public:
    static std::string programPath;
    private:
    std::unordered_map<char, std::vector<int>> elementmap;
    std::vector<std::string> elements;
    bool isDefaultMapUpdated;
    int index;
    public:
    ElementMap();
    int addAnElement(std::string);
    void addAnElementalMap(char, int);
    void printElementMap(); 
    private:
    void readDefaultMap(); 
};
#endif