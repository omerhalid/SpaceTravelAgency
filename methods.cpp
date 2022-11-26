#include <iostream>
#include <fstream>
#include <stdio.h>
#include "SpaceTravelAgency.h"

using namespace std;

Ship::Ship(int capacity, int needed_fuel) {
  this->capacity = capacity;
  this->needed_fuel;
}

int Ship::getCapacity() {
  return capacity;
}
int Ship::getNeeded_fuel() {
  return needed_fuel;
}

PremiumShip::PremiumShip(int entertainment_fees, int premium_food_fees):Ship(capacity, needed_fuel) {
  PremiumShipCapacity = capacity;
  PremiumShipCapacity = 100;
  this->entertainment_fees = entertainment_fees;
  this->premium_food_fees = premium_food_fees;
}

CheapShip::CheapShip(int basic_food_fees): Ship(capacity, needed_fuel) {
  CheapShipCapacity = capacity;
  CheapShipCapacity = 200;
  this->basic_food_fees = basic_food_fees;
}

//Asking which planet the user wants to go; (Exception handling is implemented here to check if the user selects Pluton as a planet it throws and error message.) 
void Traveler::askThePlanet() {
  cout << "What is your destination planet? " << endl;
  try {
    cin >> desired_planet;
    if (desired_planet == "pluton") {
      throw "Sorry pluton is not considered as a planet"; 
    }
  }
  catch (const char* txtException) {
    cout << "Exception happened: " << txtException << endl;
  }

}
//Check which planet the user has selected and return to its distance as an integer value;
int Traveler:: Desired_planet() {


  if (desired_planet == "merkur") {
    return distance_merkur;
  }
  else if (desired_planet == "venus") {
    return distance_venus;
  }
  else if (desired_planet == "mars") {
    return distance_mars;
  }
  else if (desired_planet == "jupiter") {
    return distance_jupiter;
  }
  else if (desired_planet == "saturn") {
    return distance_saturn;
  }
  else if (desired_planet == "uranus") {
    return distance_uranus;
  }
  else if (desired_planet == "neptun") {
    return distance_jupiter;
  }
  else if (desired_planet == "pluton") {
    return 0;
  }
}

//Calculate the needed fuel for the journey by multiplying constant required fuel value with the distance of the planet which the program has found from the previous function.
int Traveler:: fuel_calculater() {
  int needed_fuel = fuel_for_1 * Desired_planet();
  cout << needed_fuel << endl;
  return needed_fuel;

}
//Calculate the insurance fee with the special point which is calculated uniquely for the traveler multiplies with 100 and divides with the age of the traveler;
int Traveler :: Insurance_fee_calculater(int& a) {
  int age = a;
  char english;
  char diploma;
  int special_point = 0;
  cout << "Do you speak english? Y/N" << endl;
  cin >> english;
  if (english == 'Y' || 'y') {
    special_point++;
  }
  else {
    special_point--;
  }
  cout << "Do you have a university diploma? Y/N" << endl;
  cin >> diploma;
  if (diploma == 'Y' || 'y') {
    special_point++;
  }
  else
    special_point--;


  insurance_fee = (special_point * 100 / age);

  cout << "Your insurance fee is" << " " << insurance_fee << ".000 $" << endl;
  return 0;

}
//Calculate the final fee by adding the insurance fee and the fuel fee which was found earlier. If the ship type is selected for Premium by pressing �Y� from the keyboard, extra prices are added 
int Traveler:: feecalcalculater(char& s) {
  ship_type = s;
  int total_fee = fuel_calculater() + insurance_fee;
  if (ship_type == 'Y' || 'y') {
    total_fee = total_fee + premium_food_fees + entertainment_fees;
    cout << "Premium food fees and entertainment fees are added to the bill. (30.000 $)" << endl;
  }
  else {
    total_fee = total_fee + basic_food_fees;
    cout << "Only basic food fees are added to the bill (5.000 $)" << endl;
  }
  return total_fee;
}
//Check if the parents will be with the traveler if he/she is under 7 years old; 
void TravelerUnder7:: parents_present_check() {
  cout << "Will the parents be a company to the kid through out the journey? Y/N " << endl;
  cin >> parents_check;
  if (parents_check == 'y' || 'Y') {
    parents_present == true;
  }
  else {
    parents_present == false;
  }

  if (parents_present == true) {
    cout << "The kid is with the parents throught the journey" << endl;
  }
  else {
    cout << "Extra assistance needed from the staff to take care of the kid" << endl;
  }
}
