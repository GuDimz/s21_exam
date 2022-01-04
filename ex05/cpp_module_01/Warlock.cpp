#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : name(name), title(title) {
	std::cout << name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock() {
	std::cout << name << ": My job here is done!" << std::endl;
}

void Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

const std::string& Warlock::getName() const {
	return this->name;
}

const std::string& Warlock::getTitle() const {
	return this->title;
}

void Warlock::setTitle(const std::string& title) {
	this->title = title;
}

void Warlock::learnSpell(ASpell* spell) {
	this->spells[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(const std::string& name) {
	std::map<std::string, ASpell*>::iterator it;
	it = spells.find(name);
	if (it != spells.end()) {
		delete it->second;
		spells.erase(it);
	}
}

void Warlock::launchSpell(const std::string& name, const ATarget& target) {
	std::map<std::string, ASpell*>::iterator it;
	it = spells.find(name);
	if (it != spells.end()) {
		target.getHitBySpell(*spells[name]);
	}
}

