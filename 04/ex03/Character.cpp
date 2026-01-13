#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const& name) :
	_name(name)
{
	for (int i = 0; i < 4; ++i)
		_inv[i] = nullptr;
}

Character::Character(const Character& other) :
	_name(other.getName())
{
	for (int i = 0; i < 4; ++i)
	{
		_inv[i] = other._inv[i] ? other._inv[i]->clone() : nullptr;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; ++i)
		{
			delete _inv[i];
			_inv[i] = nullptr;
		}
		for (AMateria* m : _floor)
			delete m;
		_floor.clear();

		for (int i = 0; i < 4; ++i)
		{
			_inv[i] = other._inv[i] ? other._inv[i]->clone() : nullptr;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		delete _inv[i];
	for (AMateria* m : _floor)
		delete m;
}

std::string const& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{

	if (!m)
		return;

	for (int i = 0; i < 4; ++i)
		if (_inv[i] == m)
			return;

	for (int i = 0; i < 4; ++i)
	{
		if (_inv[i] == nullptr)
		{
			_inv[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || _inv[idx] == nullptr)
		return;
	_floor.push_back(_inv[idx]);
	_inv[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || _inv[idx] == nullptr)
		return;
	_inv[idx]->use(target);
}
