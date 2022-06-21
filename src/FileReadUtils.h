#ifndef FILEREADUTILS_H
#define FILEREADUTILS_H
#include "common.h"
class FileReadUtils {
    private:
    std::string m_fileName;
    std::vector<char> charStream;
    public:
    FileReadUtils(const std::string& fileName);
    std::vector<std::vector<std::string>> parseWords(char linedelm, char worddelm);
};
#endif