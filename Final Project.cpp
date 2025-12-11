// Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//============================================================================
// Name        : game_sim.cpp
// Author      : Jonathan Handy
// Description : Simple game simulation
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>
#include "unitlist.h"
using namespace std;

// ******************** Function Defs ******************** //
static void decideTurnOrder(Unit* knight, Unit* wizard);
static bool isAllDead(vector<Unit*>& team);
static int sortInitiative(vector<Unit*>& unitGroup);

// ******************** Global Variables ***************** //
uid distAction(0, 1);
vector<Unit*> unitOrder; // vector storing the Unit class

int main()
{
	cout << fixed << setprecision(2);
	hybridRandomShuffle(); // don't worry about this
	Knight knight(1);
	Knight knight2(2);
	Knight knight3(3);
	Knight knight4(4);
	Knight knight5(5);
	Knight knight6(6);
	Knight knight7(7);
	Knight knight8(8);
	Knight knight9(9);
	Knight knight10(10);
	Wizard wizard(1);
	Wizard wizard2(2);
	Wizard wizard3(3);
	Wizard wizard4(4);
	Wizard wizard5(5);
	Wizard wizard6(6);
	Wizard wizard7(7);
	Wizard wizard8(8);
	Wizard wizard9(9);
	Wizard wizard10(10);
	int roundCount = 0;

	// The following is for 1v1
	cout << "Knight 1 begins with " << knight.getHealth() << " HP" << endl;
	cout << "Knight 2 begins with " << knight2.getHealth() << " HP" << endl;
	cout << "Knight 3 begins with " << knight3.getHealth() << " HP" << endl;
	cout << "Knight 4 begins with " << knight4.getHealth() << " HP" << endl;
	cout << "Knight 5 begins with " << knight5.getHealth() << " HP" << endl;
	cout << "Knight 6 begins with " << knight6.getHealth() << " HP" << endl;
	cout << "Knight 7 begins with " << knight7.getHealth() << " HP" << endl;
	cout << "Knight 8 begins with " << knight8.getHealth() << " HP" << endl;
	cout << "Knight 9 begins with " << knight9.getHealth() << " HP" << endl;
	cout << "Knight 10 begins with " << knight10.getHealth() << " HP" << endl;
	cout << "Wizard 1 begins with " << wizard.getHealth() << " HP" << endl;
	cout << "Wizard 2 begins with " << wizard2.getHealth() << " HP" << endl;
	cout << "Wizard 3 begins with " << wizard3.getHealth() << " HP" << endl;
	cout << "Wizard 4 begins with " << wizard4.getHealth() << " HP" << endl;
	cout << "Wizard 5 begins with " << wizard5.getHealth() << " HP" << endl;
	cout << "Wizard 6 begins with " << wizard6.getHealth() << " HP" << endl;
	cout << "Wizard 7 begins with " << wizard7.getHealth() << " HP" << endl;
	cout << "Wizard 8 begins with " << wizard8.getHealth() << " HP" << endl;
	cout << "Wizard 9 begins with " << wizard9.getHealth() << " HP" << endl;
	cout << "Wizard 10 begins with " << wizard10.getHealth() << " HP" << endl;
	cout << "Checking Initiative ... " << endl;
	cout << "1st Knight's Initiative " << knight.initiative << endl;
	cout << "2nd Knight's Initiative " << knight2.initiative << endl;
	cout << "3rd Knight's Initiative " << knight3.initiative << endl;
	cout << "4th Knight's Initiative " << knight4.initiative << endl;
	cout << "5th Knight's Initiative " << knight5.initiative << endl;
	cout << "6th Knight's Initiative " << knight6.initiative << endl;
	cout << "7th Knight's Initiative " << knight7.initiative << endl;
	cout << "8th Knight's Initiative " << knight8.initiative << endl;
	cout << "9th Knight's Initiative " << knight9.initiative << endl;
	cout << "10th Knight's Initiative " << knight10.initiative << endl;
	cout << "1st Wizard's Initiative " << wizard.initiative << endl;
	cout << "2nd Wizard's Initiative " << wizard2.initiative << endl;
	cout << "3rd Wizard's Initiative " << wizard3.initiative << endl;
	cout << "4th Wizard's Initiative " << wizard4.initiative << endl;
	cout << "5th Wizard's Initiative " << wizard5.initiative << endl;
	cout << "6th Wizard's Initiative " << wizard6.initiative << endl;
	cout << "7th Wizard's Initiative " << wizard7.initiative << endl;
	cout << "8th Wizard's Initiative " << wizard8.initiative << endl;
	cout << "9th Wizard's Initiative " << wizard9.initiative << endl;
	cout << "10th Wizard's Initiative " << wizard10.initiative << endl;
	// Arrange turn order based in initiative (only for 1v1)
	//decideTurnOrder(&knight, &wizard); // use unitOrder to initiate attack

	// For multiple v. multiple
	// Use loop to display each unit's stats

	// For multiple units, sort based on initiative value (ascending)
	// First push the objects in unit order
	unitOrder.push_back(&knight);
	unitOrder.push_back(&knight2);
	unitOrder.push_back(&knight3);
	unitOrder.push_back(&knight4);
	unitOrder.push_back(&knight5);
	unitOrder.push_back(&knight6);
	unitOrder.push_back(&knight7);
	unitOrder.push_back(&knight8);
	unitOrder.push_back(&knight9);
	unitOrder.push_back(&knight10);
	unitOrder.push_back(&wizard);
	unitOrder.push_back(&wizard2);
	unitOrder.push_back(&wizard3);
	unitOrder.push_back(&wizard4);
	unitOrder.push_back(&wizard5);
	unitOrder.push_back(&wizard6);
	unitOrder.push_back(&wizard7);
	unitOrder.push_back(&wizard8);
	unitOrder.push_back(&wizard9);
	unitOrder.push_back(&wizard10);
	int first = sortInitiative(unitOrder);

	cout << unitOrder[0]->name << "#" << first << " (Initiative: " << unitOrder[0]->initiative << ") will act first" << endl;

	// Create teams
	vector<Unit*> teamKnights;
	vector<Unit*> teamWizards;
	for (int i = 0; i < 20; i++)
	{
		if (unitOrder[i]->name == "Knight")
		{
			teamKnights.push_back(unitOrder[i]);
		}
		else
		{
			teamWizards.push_back(unitOrder[i]);
		}
	};

	for (int i = 0; i < 10; i++)
	{
		//cout << unitOrder[i]->name << " # " << unitOrder[i]->unitID << " Initiative is " << unitOrder[i] ->initiative << endl;
		cout << teamKnights[i]->name << " # " << teamKnights[i]->unitID << " Initiative is " << teamKnights[i]->initiative << endl;

	}

	for (int i = 0; i < 10; i++)
	{
		//cout << unitOrder[i]->name << " # " << unitOrder[i]->unitID << " Initiative is " << unitOrder[i] ->initiative << endl;
		cout << teamWizards[i]->name << " # " << teamWizards[i]->unitID << " Initiative is " << teamWizards[i]->initiative << endl;

	}

	// For multiple units in each team, have to loop and push_back() multiple times for each team

	// Create empty targets
	vector<Unit*> targets;

	// battle continue until last unit standing
	// Check for team exclusivity for mutliple units vs multiple units
	while (true) // while non of the teams are empty
	{
		roundCount++;
		cout << endl;
		cout << "=========== Start of Round " << roundCount << " ===========" << endl;
		cout << "Knight #" << teamKnights[0]->unitID << ":" << teamKnights[0]->getHealth() << " HP " << endl;
		cout << "Wizard #" << teamWizards[0]->unitID << ":" << teamWizards[0]->getHealth() << " HP " << endl;
		cout << "Begin >>>>>5>>>>>>>>>>>>>>>>>>" << endl;

		// for(short i : unitOrder) OR
		for (size_t i = 0; i < unitOrder.size(); i++) // use size_t from <vector> to avoid type cast warning
		{
			Unit* thisUnit = unitOrder[i]; // the current acting unit

			// Check if this unit is already dead
			// checkIfAlive return 1 for alive and 0 for dead
			// The logic !thisUnit->checkIfAlive() (! is NOT operator) return 1 for dead and 0 for alive
			if (!thisUnit->checkIfAlive()) //
			{
				continue; // Skip if unit is dead
			}

			string thisUnitName = thisUnit->name; // check the name of current acting unit
			targets = thisUnitName == "Knight" ? teamWizards : teamKnights; // identify targets

			// Get live targets only
			vector<Unit*> liveTargets;
			for (Unit* t : targets)
			{
				if (t->checkIfAlive())
				{
					liveTargets.push_back(t);
				}
			}

			if (liveTargets.empty()) // check if all live targets are dead
			{
				continue; // nothing to attack
			}

			// Pick a random target from live targets
			uid distTarget(0, liveTargets.size() - 1);
			// generate random integer representing target in the opposing team
			short targetIdx = distTarget(genRand);
			// store selected target in current target (thisTarget)
			Unit* thisTarget = liveTargets[targetIdx];

			// Random Action
			short thisAction = distAction(genRand);
			if (thisAction == 0)
			{
				thisUnit->heal();
			}
			else
			{
				thisUnit->attack(*thisTarget);
			}

			// Remove dead units from unitOrder stack
			for (size_t i = unitOrder.size(); i-- > 0;) // reverse iteration C++ syntax that works with size_t
				// OR for(int i = unitOrder.size()-1; i >= 0; i--) // triggers warning cuz size_t is unsigned
			{
				if (!unitOrder[i]->checkIfAlive())
				{
					unitOrder.erase(unitOrder.begin() + i);
				}
			}

			//Remove dead units from teamKnights and teamWizards stacks
			for (size_t i = teamKnights.size(); i-- > 0;)
			{
				if (!teamKnights[i]->checkIfAlive())
				{
					teamKnights.erase(teamKnights.begin() + i);
				}
			}

			for (size_t i = teamWizards.size(); i-- > 0;)
			{
				if (!teamWizards[i]->checkIfAlive())
				{
					teamWizards.erase(teamWizards.begin() + i);
				}
			}

			/* //OR using function handle (more complicated but more C++-ish)
			// Remove dead units from unitOrder stack (alternate: using remove_if())
			unitOrder.erase(
				remove_if(unitOrder.begin(), unitOrder.end(),
						  [](Unit* u){ return !u->checkIfAlive(); }),
				unitOrder.end()
			);
			*/
		}
		cout << "=========== End of Round " << roundCount << " ===========" << endl;

		if (isAllDead(teamKnights))
		{
			cout << "Team Wizard WON!" << endl;
			break;
		}
		if (isAllDead(teamWizards))
		{
			cout << "Team Knight WON!" << endl;
			break;
		}
	}

	cout << endl;


	return 0;
}


static void decideTurnOrder(Unit* knight, Unit* wizard)
{
	if (knight->initiative > wizard->initiative)
	{
		cout << "Knight has higher initiative (" << knight->initiative << "), will act first" << endl;
		// push_back() method creates stack by adding element at the end
		unitOrder.push_back(knight); // push_back knight first
		unitOrder.push_back(wizard); // push_back wizard second
	}
	else if (knight->initiative < wizard->initiative)
	{
		cout << "Wizard has higher initiative (" << wizard->initiative << "), will act first" << endl;
		unitOrder.push_back(wizard);
		unitOrder.push_back(knight);
	}
	else
	{
		cout << "Equal Initiative. Unit with lower health will act first" << endl;
		if (knight->health < wizard->health)
		{
			cout << "Knight will act first" << endl;
			unitOrder.push_back(knight); // push_back knight first
			unitOrder.push_back(wizard); // push_back wizard second
		}
		else
		{
			cout << "Wizard will act first" << endl;
			unitOrder.push_back(wizard); // push_back wizard first
			unitOrder.push_back(knight); // push_back knight second
		}
	}
}

static bool isAllDead(vector<Unit*>& team)
{
	for (Unit* i : team)
	{
		if (i->checkIfAlive())
		{
			return false;
		}
	}
	return true;
}

static int sortInitiative(vector<Unit*>& unitGroup)
{
	// Sort unit based on initiative and return the ID of the one with highest initiative
	sort(unitGroup.begin(), unitGroup.end(),
		[](Unit* a, Unit* b) { return a->initiative > b->initiative; });
	return unitGroup[0]->unitID;
}