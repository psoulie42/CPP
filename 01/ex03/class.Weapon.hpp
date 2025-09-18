#ifndef WEAPON_CLASS
# define WEAPON_CLASS

# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string _type;
	public:
		std::string& getType(void);
		void		setType(std::string type);

		Weapon(std::string type);
		~Weapon();
};

#endif
