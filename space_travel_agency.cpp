#include <iostream>
#include <fstream>
#include <stdio.h>
#include "SpaceTravelAgency.h"

using namespace std;

//Print the final bill incase of multiple tickets has been bought with using file handling
void fee_summary_print_family(int* t, string passed_family[],int passed_family_age[],string passed_family_nationality[], int& PRICE) {

  ofstream myfile;
  int price_family = PRICE;

  myfile.open("summary.txt", fstream::out | fstream::app);

  int ticket_Counter = *t;

  for (int k = 0;k < ticket_Counter;k++) {
    myfile << "Name: " << " " << passed_family[k] << endl;
    myfile << endl;

  }
  for (int k = 0;k < ticket_Counter;k++) {
    myfile << "Age: " << " " << passed_family_age[k] << endl;
    myfile << endl;

  }
  for (int k = 0;k < ticket_Counter;k++) {
    myfile << "Nationality: " << " " << passed_family_nationality[k] << endl;
    myfile << endl;

  }
  myfile << "Total bill is " << price_family << "$" << endl;

}
//Print the final bill in the case of 1 ticket with using file handling
void single_fee_summary_print(string &NAME,int &AGE,string &NATIONALITY,int&PRICE) {

  ofstream myfile;
  int final_Price = PRICE;

  

  myfile.open("summary.txt", fstream::out| fstream::app);

  string name = NAME;
  int age = AGE;
  string nationality = NATIONALITY;

  myfile << "Name: " << " " << name;
  myfile << endl;

  myfile << "Age: " << " " << age;
  myfile << endl;

  myfile << "Nationality " << " " << nationality;
  myfile << endl;

  myfile << "Total bill is " << final_Price<<"$" << endl;

}



int main()
{
  int i;
  int ask_age;
  string ask_name;
  string ask_nationality;

  char ship_type;
  int family_ticket;

  ofstream myfile;

  myfile.open("summary.txt", fstream::out);

  


  Traveler A;
  cout << "How many tickets would you like to buy?" << endl;
  cin >> family_ticket;

  string* family = new string[family_ticket];
  int* family_age = new int[family_ticket];
  string* family_nationality = new string[family_ticket];


  // In the case of a more than 1 tickets, the program uses dynamic memory allocation in order to assign the required information from the user to the corresponding keywords.
  if (family_ticket > 1) {
    for (i=0;i<family_ticket;i++){
      cout << "What is the name? " << endl;
      cin >> ask_name;
      family[i] = ask_name;
    }
    for (i = 0;i < family_ticket;i++){
      cout << "What are the ages of the travellers? " << endl;
      cin >> ask_age;
      family_age[i] = ask_age;
    }
    for (i = 0;i < family_ticket;i++) {
      cout << "What is are the nationalities of the travellers?" << endl;
      cin >> ask_nationality;
      family_nationality[i] = ask_nationality;
    }
    for (i = 0;i < family_ticket;i++) {
      cout << "Would you like to get a premium ship? Y/N" << endl;
      cin >> ship_type;
    }
    

      A.askThePlanet();
      A.fuel_calculater();
      A.Insurance_fee_calculater(ask_age);

      int FINAL_PRICE_FAMILY=A.feecalcalculater(ship_type);

      fee_summary_print_family(&family_ticket, family, family_age, family_nationality, FINAL_PRICE_FAMILY);
      
      
      TravelerUnder7 B;
      B.parents_present_check();


     
      myfile.close();
      delete[]family;
      return 0;



  }
  //if the user would like to buy 1 ticket, else statement gets called.
  else 
 
  
  cout << "What is your name? " << endl;
  cin >> ask_name;
  A.name = ask_name;

  cout << "What is your age? " << endl;
  cin >> ask_age;
  A.age = ask_age;

  cout << "What is your nationality?" << endl;
  cin >> ask_nationality;
  A.nationality = ask_nationality;

  cout << "Would you like to get a premium ship? Y/N" << endl;
  cin >> ship_type;

  A.askThePlanet();
  A.fuel_calculater();
  A.Insurance_fee_calculater(ask_age);

  TravelerUnder7 B;
  B.parents_present_check();
  int FINAL_PRICE = A.feecalcalculater(ship_type);

  single_fee_summary_print(ask_name, ask_age, ask_nationality, FINAL_PRICE);
  myfile << "Total bill is " << A.feecalcalculater(ship_type)<<"$" << endl;
  myfile.close();

  return 0;

}

