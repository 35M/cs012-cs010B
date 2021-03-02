#include <iostream>
#include <string>

#include "Character.h"
#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int rank) 
    : Character(WIZARD, name, health, attackStrength), rank(rank) {
}

void Wizard::attack(Character &opponent) {
    double damage = 0.0;
    
    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        damage = attackStrength * (static_cast<double>(rank) / static_cast<double>(opp.rank));
    
        opponent.damage(damage);

        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    } 
    else {
        damage = attackStrength;
        opponent.damage(damage);

        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
        return;
    }
}