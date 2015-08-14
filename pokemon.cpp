#include "pokemon.h"
#include <string>

Pokemon::Pokemon(int[] EVs, int[] IVs, std::string name, std::string ability, std::string holding_item, std::string[] attacks)
{ 

}


Pokemon::~Pokemon()
{

}

int Pokemon::getHP()
{
  return MAX_HP;
}

int Pokemon::getATK()
{
  return ATK;
}

int Pokemon::getDEF()
{
  return DEF;
}

int Pokemon::getSPATK()
{
  return SPATK;
}

int Pokemon::getSPDEF()
{
  return SPDEF
}

int Pokemon::getSPEED()
{
  return SPEED;
}
