#include <string>
#include "Character.h"

using namespace std;

#ifndef __WIZARD_H__
#define __WIZARD_H__

class Wizard : public Character {
    private:
        int rank;

    public:
        Wizard(const string &, double, double, int);
        void attack(Character &);
};

#endif