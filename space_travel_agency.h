#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

const int distance_merkur = 176;
const int distance_venus = 132;
const int distance_mars = 258;
const int distance_jupiter = 862;
const int distance_saturn = 1542;
const int distance_uranus = 3000;
const int distance_neptun = 4600;

const int fuel_for_1 = 5;
const int basic_food_fees = 5;
const int premium_food_fees = 25;
const int entertainment_fees = 5;

class Ship {
protected:
  int capacity;
  int needed_fuel;
  Ship(int, int);


  int getCapacity();
  int getNeeded_fuel();
};

class PremiumShip :public Ship {
  int entertainment_fees;
  int premium_food_fees;
  int PremiumShipCapacity;
  PremiumShip(int, int);
};

class CheapShip :public Ship {
  int basic_food_fees;
  int CheapShipCapacity;

  CheapShip(int);



};

class Traveler {
public:
  int age;
  string nationality;
  string name;
  string desired_planet;
  float insurance_fee;
  char ship_type;

  void askThePlanet();


  int Desired_planet();

  int fuel_calculater();

  int Insurance_fee_calculater(int& a);


  int feecalcalculater(char& s);

};

class TravelerUnder7 :public Traveler {
  bool parents_present;
  char parents_check;
public:
  void parents_present_check();

};
