/*
CSCI 235 
Project 1
Farhana Sultana
Creature.cpp defines the constructors and private and public function implementation of the Creature class
*/

#include "Creature.hpp"

Creature::creature()name_{NAMELESS}, category_{UNKNOWN}, hitpoints_{1}, level_{1}, tame_{false}
 {
 }
 // Parameterized constructor
Creature::Creature(const std::string& name, Category category, int hitpoints, int level, bool tame)
    : category_(category), tame_(tame) {
    if (!setName(name)) {
        name_ = "NAMELESS";
    }
    setHitpoints(hitpoints);
    setLevel(level);
}

// setName
bool Creature::setName(const std::string& name) {
    for (char c : name) {
        if (!isalpha(c))
            return false;
    }
    name_ = name;
    for (char& c : name_) {
        c = toupper(c);
    }
    return true;
}

// getName
std::string Creature::getName() const {
    return name_;
}

// setCategory
void Creature::setCategory(Category category) {
    category_ = category;
}

// getCategory
std::string Creature::getCategory() const {
    switch (category_) {
        case UNKNOWN: return "UNKNOWN";
        case UNDEAD: return "UNDEAD";
        case MYSTICAL: return "MYSTICAL";
        case ALIEN: return "ALIEN";
    }
    return "UNKNOWN";
}

// setHitpoints
bool Creature::setHitpoints(int hitpoints) {
    if (hitpoints >= 0) {
        hitpoints_ = hitpoints;
        return true;
    }
    return false;
}

// getHitpoints
int Creature::getHitpoints() const {
    return hitpoints_;
}

// setLevel
bool Creature::setLevel(int level) {
    if (level >= 0) {
        level_ = level;
        return true;
    }
    return false;
}

// getLevel
int Creature::getLevel() const {
    return level_;
}

// setTame
void Creature::setTame(bool tame) {
    tame_ = tame;
}

// isTame
bool Creature::isTame() const {
    return tame_;
}

// display
void Creature::display() const {
    std::cout << getName() << "\n";
    std::cout << "Category: " << getCategory() << "\n";
    std::cout << "Level: " << getLevel() << "\n";
    std::cout << "Hitpoints: " << getHitpoints() << "\n";
    std::cout << "Tame: " << (isTame() ? "TRUE" : "FALSE") << "\n";
}
