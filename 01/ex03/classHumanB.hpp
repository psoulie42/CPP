#ifndef HUMAN_B_CLASS
# define HUMAN_B_CLASS

# include "classWeapon.hpp"

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
