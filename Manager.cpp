#include "Manager.h"

Manager::Manager(string theName, double theWage, double theHours, double theBonus)
    : Employee(theName, theWage, theHours), bonus(theBonus) {}

double Manager::calcPay() const {
    return Employee::calcPay() + bonus;
}
