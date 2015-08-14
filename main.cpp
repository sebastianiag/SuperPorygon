#include <string>
#include <stdlib>
#include <time>
#include "pokemon.h"
#include "mechanics.h"


/**
enum actions = {FIGHT, SWITCH, RUN};
enum weather = {CLEAR, RAIN, SUNNY, SANDSTORM, HAIL, EXTREME_RAIN, EXTREME_SUNNY};


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
} field;
**/

void main_loop(Player &player1, Player &player2);

//void switchin_abilities(std::string name);
//void switchin_abilities(std::string name1, std::string name2);
//void Switch(Pokemon* &pokemon, Pokemon* &switchTo);

void parseActions(Player &player);
int compareSpeed(Pokemon* pokemon1, Pokemon* pokemon2);
//void checkIsFaint(Pokemon* &pokemon);

int main()
{
  Player player1, player2;
  // initialize players here
  main_loop(player1, player2);
}



void main_loop(Player &player1, Player &player2)
{
  
  srand (time(NULL));
  int random_num;
  std::string weather;
  player1.active = player1.pokemons[0];
  player2.active = player2.pokemons[0];
  
  player1.active_ability = player1.active->getAbility();
  player2.active_ability = player2.active->getAbility();
  field = {false, false, false, false, CLEAR};

  switchin_abilities(player1.active_ability->name);
  switchin_abilitiies(player2.active_ability->name);

  Attack* attack1, attack2;
  int turn;
  bool bypass = false;
  while(!player1.forfeit || !player2.forfeit) //change this conditional to faints instead
    {
      //getPlayers actions here
      parseActions(player1);
      parseActions(player2);
     

      if(player1.action == SWITCH)
	{
	  bypass = false;
	  if(player2.action == FIGHT && player2.using_attack->name == "Pursuit")
	    {
	      applyDamage(player2.active, player1.active, player2.using_attack);
	      bypass = true;
	    }
	  Switch(player1.active, player1.switchTo);
	  active_ability1 = player1.active->getAbility();
	  switching_abilities(player1.active_ability->name);
	  if(bypass)
	    {
	      //skip to next turn
	      continue;
	    }
	}
      if(player2.action == SWITCH)
	{
	  bypass = false;
	  if(player1.action == FIGHT && player1.using_attack->name == "Pursuit")
	    {	       
	      applyDamage(player1.active, player2.active, player1.using_attack);
	      bypass = true;
	    }
	  Switch(player2.active, player2.switchTo);
	  active_ability2 = player2.active->getAbility();
	  switching_abilities(player2.active_ability->name);
	  // REMEMBER to apply spikes damages and shit
	  if(bypass)
	    {
	      //skip to next turn
	      continue;
	    }
	}
      
      //apply damages
      turn = compareSpeed(player1.active, player2.active);
      switch(turn)
      {
      case -1:
	applyDamage(player2.active, player1.active, player2.using_attack);
	checkIsFaint(player1);
	applyDamage(player1.active, player2.active, player1.using_attack);
	checkIsFaint(player2);
	break;

      case 1:
	applyDamage(player1.active, player2.active, player1.using_attack);
	checkIsFaint(player2);
	applyDamage(player2.active, player1.active, player2.using_attack);
	checkIsFaint(player1);
	break;

      case 0:
	random_num = rand()%101;
	if(random_num < 50)
	  {
	    applyDamage(player1.active, player2.active, player1.using_attack);
	    checkIsFaint(player2);
	    applyDamage(player2.active, player1.active, player2.using_attack);
	    checkIsFaint(player1);
	  }
	else
	  {
	    applyDamage(player1.active, player2.active, player1.using_attack);
	    checkIsFaint(player2);
	    applyDamage(player2.active, player1.active, player2.using_attack);
	    checkIsFaint(player1);
	  }
	break;
      }
      
      afterBattleAbility(player1.active_ability->name);
      checkIsFaint(player1);
      checkIsFaint(player2);
      afterBattleAbility(player2.active_ability->name);
      checkIsFaint(player1);
      checkIsFaint(player2);
    }
}

void checkIsFaint(Player &player)
{
  if(player.active->isFainted)
    {
      //get list of pokemon and value of switchTo
      Switch(player.active, player.switchTo);
      player.active_ability = player.active->getAbility();
      switching_abilities(player.active_ability->name);
      //REMEMBER to apply spikes damages and shit
      //skip to next turn
      return;
    }
  else:
    return;
}

int compareSpeed(Pokemon* pokemon1, Pokemon* pokemon2)
{
  int speed1 = pokemon1->getSPEED();
  int speed2 = pokemon2->getSPEED();
  if(speed1 < speed2)
    {
      return -1;
    }
  if(speed1 > speed2)
    {
      return 1;
    }
  if(speed1 == speed2)
    {
      return 0;
    }
}

void parseActions(Player player)
{
  switch(player.action)
	{
	case FIGHT:
	  //pull out the using attack variable somehow from GUI
	  player.using_attack =  getAttack();
	  break;

        case SWITCH:
	  player.switchTo = showPokemons(player1);
	  break;
	
        case RUN:
	  player1.forfeit = true;
	  //exit battle and report results somehow
	  break;
	}
}




