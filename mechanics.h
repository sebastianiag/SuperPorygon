#include <string>
#include <map>
#include "pokemon.h"

class Mechanics 
{
 public:
  Mechanics();
  ~Mechanics();
  static enum actions  {FIGHT, SWITCH, RUN};
  static enum weather  {CLEAR, RAIN, SUNNY, SANDSTORM, HAIL, EXTREME_RAIN, EXTREME_SUNNY};
  static map<types, map<types, double>> type_matrix;

  struct Player
  {
    Pokemon* pokemons[6];
    Pokemon* active;
    bool forfeit;
    actions action;
    Attack* using_attack;
    Pokemon* switchTo;
    Ability* active_ability;
  };

  struct Field
  {
    bool spikes;
    bool toxic_spikes;
    bool trick_room;
    bool stealth_rocks;
    weather current_weather;
  };

  
  void switchin_abilities(std::string name);
  void afterBattleAbility(std::string name);
  void Switch(Pokemon* pokemon, Pokemon* pokemon2);
  void checkIsFaint(Pokemon* pokemon);
  void applyDamage(Pokemon* pokemon1, Pokemon* pokemon2, Attack* attack, double rand_modifier);
}
