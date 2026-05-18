#include "classHumanA.hpp"
#include "classHumanB.hpp"
#include "classWeapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon maul = Weapon("Maul of the Wild");
		HumanB ragnar("Ragnar");

		ragnar.setWeapon(maul);
		ragnar.attack();
		maul.setType("huge ass warhammer");
		ragnar.attack();
	}
}
