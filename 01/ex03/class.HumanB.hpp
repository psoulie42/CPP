#ifndef HUMAN_B_CLASS
# define HUMAN_B_CLASS

# include "class.Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon;
	public:
		void	attack();
		void	setWeapon(Weapon& weapon);

	HumanB(std::string name);
	~HumanB();
};

#endif
