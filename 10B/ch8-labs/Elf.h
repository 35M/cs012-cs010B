#include <string>
#include "Character.h"

using namespace std;

#ifndef __ELF_H__
#define __ELF_H__

class Elf : public Character {
    private:
        string family;

    public:
        Elf(const string &, double, double, const string &);
        void attack(Character &);
};

#endif