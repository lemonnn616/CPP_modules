#ifndef WEAPON_CPP
# define WEAPON_CPP

# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon();

		const std::string& getType() const; // тильда потому что указатель на существующий обьект
		void setType(std::string type);
};

#endif