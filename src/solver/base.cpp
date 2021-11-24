#include "solver/base.hpp"

// constructor
SolverBase::SolverBase() {
    // initialize 
    rules = vector<RuleBase*>();
}

// destructor
SolverBase::~SolverBase() {
    for (RuleBase* rule : rules) {
        delete rule;
    }
}