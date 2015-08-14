#include <string>
#include <map>
#include "mechanics.h"
#include "pokemon.h"


Mechanics::Mechanics()
{ 
  type_matrix = {{"NORMAL":{{"NORMAL": 1} , {"FIGIHTING": 1} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"FIGHTING":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"FLYING":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"POISON":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"GROUND":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"ROCK":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"BUG":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"GHOST":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"STEEL":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"FIRE":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"WATER":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"GRASS":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"ELECTRIC":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"PSYCHIC":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"ICE":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"DRAGON":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"DARK":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}},
		 {"FAIRY":{{"NORMAL":} , {"FIGIHTING":} , {"FLYING": }, {"POISON": }, {"GROUND": }, {"ROCK": },
			   {"BUG": }, {"GHOST":}, {"STEEL":}, {"FIRE":}, {"WATER":}, {"GRASS":}, {"ELECTRIC":},
			    {"PSYCHIC":}, {"ICE":}, {"DRAGON":}, {"DARK":}, {"FAIRY":}}}
  };
}


void Mechanics::initialize_player(Player &player)
{

}


void Mechanics::switchin_abilities(std::string name)
{
  switch(name)
    {
    case "Intimidate":
      
      break;
      
    case "Drought":

      break;

    case "Drizzle":


    }
}

void Mechanics::applyDamage(Pokemon* pokemon1, Pokemon* pokemon2, Attack* attack, double rand_modifier)
{
    double ATK, DEF;
    double type_effect = type_matrix[attack->type][pokemon2->type]*type_matrix[attack->type][pokemon2->type];
    double critical_hit; //determine this
    //check for in battle abilities
    double random_mod = (rand_modifier % 101)/100.0;
    int modifier = STAB*type_effect*random_mod;
    double STAB;
    
    if(attack->type == pokemon1->type1 || attack->type == pokemon1->type2)
	{
	  STAB = 1.5;
	}
      else
	{
	  STAB = 1.0;
        }
  switch(attack->category)
    {
    case "Physical":
    

     }

double damage = ((2*pokemon1->level +10)/250)*(pokemon1->ATK/pokemon2->DEF)*attack->power*modifier;
    
}
