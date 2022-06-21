#include "ElementMap.h" 
#include "FileReadUtils.h"

ElementMap::ElementMap(){
    index = -1;
    isDefaultMapUpdated = false;
    readDefaultMap();
}

void ElementMap::addAnElementalMap(char ch, int index) {
    if (elementmap.find(ch)==elementmap.end()) {
        elementmap.insert(std::pair<char, std::vector<int>>(ch,std::vector<int>()));
    }
    elementmap[ch].push_back(index);
}

int ElementMap::addAnElement(std::string element) {
    elements.push_back(element);
    index++;
    return index;
}

void ElementMap::readDefaultMap() {
    if (isDefaultMapUpdated) {return;}
    boost::filesystem::path programpath(programPath);
    std::string elementfilepath = programpath.parent_path().parent_path().string() + "/res/elements.txt";
    FileReadUtils elementfile = FileReadUtils(elementfilepath);
    std::vector<std::vector<std::string>> lines = elementfile.parseWords('\n', ' ');
    for (auto line: lines) {
        int index = addAnElement(line[0]);
        for (size_t i = 1; i < line.size(); i++ ) {
            addAnElementalMap(line[i][0], index);
        }
    }
    isDefaultMapUpdated = true;
}

void ElementMap::printElementMap() {
    for (auto item : elementmap) {
        std::cout << item.first;
        for (auto i:item.second) {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}