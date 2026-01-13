#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon& _weapon; // vsegda est oruzhie poetomu ssilka

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();

		void attack() const;
};

#endif
