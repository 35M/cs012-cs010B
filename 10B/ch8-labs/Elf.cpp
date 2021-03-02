#include <iostream>
#include <string>

#include "Elf.h"
#include "Character.h"

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string &family) 
    : Character(ELF, name, health, attackStrength), family(family) {    
}

void Elf::attack(Character &opponent) {
    double damage = 0.0;
    
    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);

        if (opp.family == family) {    
            cout << "Elf " << name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
            return;
        }
    }
    
    damage = (health / MAX_HEALTH) * attackStrength;
    opponent.damage(damage);

    cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
    cout << opponent.getName() << " takes " << damage << " damage." << endl;
    return;
}