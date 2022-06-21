#ifndef STATE_H
#define STATE_H
#include "common.h"
#include "ElementMap.h"

class State {
    public:
    static ElementMap elementMap;
    private:
    std::unordered_map<char, State*> transition;
    bool isFinal;
    bool isGhostInit;
    public:
    State();
    State* makeAMove(char);
    void addATransition(char, State*);
    void setItFinal();
    void setItGhost();
};
#endif