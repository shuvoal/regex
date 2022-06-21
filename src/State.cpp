#include "State.h"

State::State() {
    isFinal = false;
    isGhostInit = false;
}

void State::addATransition(char ch, State* pstate) {
    transition[ch] = pstate;
}

State* State::makeAMove(char ch) {
    State* pstate = nullptr;
    if (transition.find(ch) != transition.end()) {
        pstate = transition[ch];
    }
    return pstate;
}

void State::setItFinal() {
    isFinal = true;
}

void State::setItGhost() {
    isGhostInit = true;
}