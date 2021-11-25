#include "solver/base.hpp"

// constructor
SolverBase::SolverBase(const int num_of_solutions) {
    // initialize 
    rules = vector<RuleBase*>();
    this->num_of_solutions = num_of_solutions;
    this->num_of_solutions_found = 0;
}

// destructor
SolverBase::~SolverBase() {
    for (RuleBase* rule : rules) {
        delete rule;
    }

    delete &rules;
    delete &num_of_solutions;
}

void SolverBase::addRule(RuleBase& rule) {
    rules.push_back(&rule);
}