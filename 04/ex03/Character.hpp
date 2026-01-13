#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>
#include <vector>

class AMateria;

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria* _inv[4];
	std::vector<AMateria*> _floor;

public:
	Character() = delete;
	explicit Character(std::string const& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	std::string const& getName() const override;
	void equip(AMateria* m) override;
	void unequip(int idx) override;
	void use(int idx, ICharacter& target) override;
};

#endif
