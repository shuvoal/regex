#include "FileReadUtils.h"
FileReadUtils::FileReadUtils(const std::string& fileName) {
    m_fileName = fileName;
    std::fstream fin(m_fileName, std::ios_base::in);
    char x;
    fin >> std::noskipws >> x;
    while (!fin.eof()) {
        charStream.push_back(x);
        fin >> std::noskipws >> x;
    }
}
std::vector<std::vector<std::string>> FileReadUtils::parseWords(char linedelm, char worddelm) {
    std::vector<std::vector<std::string>> lines;
    std::vector<std::string> line;
    std::string word;
    char prevChar;
    for (char ch: charStream) {
        if (ch == linedelm) {
            if (prevChar != worddelm && prevChar != linedelm) {
                line.push_back(word);
                word = "";
            }
            if (prevChar != linedelm) {
                lines.push_back(line);
                line.clear();
            }
            prevChar = ch;
            continue;
        }
        if (ch == worddelm) {
            if (prevChar != worddelm && prevChar != linedelm) {
                //std::cout << word << std::endl;
                line.push_back(word);
                word = "";
            }
            prevChar = ch;
            continue;
        }
        word.push_back(ch);
        prevChar = ch;
    }
    return lines;
}