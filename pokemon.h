#ifndef POKEMON
#define POKEMON

#include <string>
#include "attack.h"
#include "ability.h"
#include "item.h"

class Pokemon
{
 public:
  Pokemon(int[] EVs, int[] IVs, std::string name, std::string ability, std::string holding_item, std::string[] attacks);
  ~Pokemon();
  int getHP();
  int getATK();
  int getDEF();
  int getSPATK();
  int getSPDEF();
  int getSPEED();
  Ability*  getAbility();
  Attack**  getAttacks();
  std::string[] getTypes();
  int currentHP, ATK_bonus, DEF_bonus, SPATK_bonus, SPDEF_bonus, SPEED_bonus; //Can be negative
  bool isFainted;    //default is False unless otherwise specified.
  bool isPoisoned;
  bool isParalized;
  bool isAsleep;
  bool isInfatuated;
  bool isToxic;
  bool isBurned;
  bool isFlinched;
  double currentHP;
  std::string gender;

 private:
  int MAX_HP, ATK, DEF, SPATK, SPDEF, SPEED;
  int HP_base, ATK_base, DEF_base, SPATK_base, SPDEF_base, SPEED_base;
  int HP_EV, ATK_EV, DEF_EV, SPATK_EV, SPDEF_EV, SPEED_EV;
  int HP_IV, ATK_IV, DEF_IV, SPATK_IV, SPDEF_IV, SPEED_IV;
  int level; // for the moment, it should always be 100
  Attack*   attacks[4];  
  Ability*  ability;
  Item* holding_item;
  std::string name;
  std::string type1, type2; //type2 can be empty if the pokemon is a monotype
  
  
}

struct Attack
{
  std::string name; 
  std::string type;
  std::string category;
  int power; 
  int accuracy
  int pp;
  std::string effect;
  std::string effect_description;
  int effect_probability;
}

struct Ability
{
  std::string name;
  std::string effect;
  std::string effect_description;
  bool repeat;
}

struct Item
{
  std::string name;
  std::string effect;
  std::string effect_description;
  int effect_probability;
}

#endif
