#include "student.h"
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin;
bool initialized=false;
    student::student() {

  Grade = '0';
  Percentage = 0;
}
void student::Read() {
    if(!initialized)
     fin.open("Students.txt");
  cout << "\nEnter the student's roll number\n";
  fin >> Roll_Number; fin.ignore();
  cout << "\nEnter the student's name\n";
  getline(fin,Name);
  cout << "\nEnter the student's department\n";
  getline(fin,Department);
  cout << "\nEnter the city\n";
  getline(fin,s.City);
  cout << "\nEnter the residential area\n";
  getline(fin,s.Residential_Area);
  cout << "\nEnter the zip code\n";
  fin >> s.Zip_Code; fin.ignore();
  cout << "\nEnter the number of subjects\n";
  fin >> Number_Subjects; fin.ignore();
  for (int i = 0; i < Number_Subjects; i++)
  { cout << "\nEnter score of subject " << i + 1 << endl;
    fin >> Marks[i];
    cout << "\nEnter the full mark of subject " << i + 1 << endl;
    fin >> Full_Marks[i];

  } fin.ignore();
initialized=true;}

void student::Display() {
  cout << "\n\tName: " << Name;
  cout << "\n\tRoll no: " << Roll_Number;
  cout << "\n     ______________________________________\n";
  for (int i = 0; i < Number_Subjects; i++)
    cout << "\tSubject " << i + 1 << "\t|\t" << Marks[i]
    << " / " << Full_Marks[i] << endl;
  cout << "     ______________________________________\n";
  cout << "\tPercentage\t|\t" << Percentage << " %" << endl;
  cout << "\tGrade\t\t|\t" << Grade;
  cout << "\n     ______________________________________\n\n";
}

void student::Modify() {
  cout << "1. Department\n";
  cout << "2. Address\n";
  cout << "3. Marks, grade and percentage\n";
  cout << "\n\nChoose a feature from <1-3> to modify\n";
  int choice;
  cin >> choice;
  while (choice < 1 || choice > 3)
  { cout << "\nInvalid input! please enter a number between 1-3\n";
    cin >> choice;
  } cin.ignore();
  switch (choice) {
    case 1:  {
        cout << "\n\n Enter the new department \n";
        cin >> Department; cin.ignore();
      } break;
    case 2: {
        cout << "\n\n Enter the new city:\n";
        getline(cin, s.City);
        cout << "\n\nEnter the new residential area:\n";
        getline(cin, s.Residential_Area);
        cout << "\n\nEnter the new zip code\n";
        cin >> s.Zip_Code; cin.ignore();
      } break;
    case 3: {
        cout << "\n\nEnter the new number of subjects\n";
        cin >> Number_Subjects; cin.ignore();
        for (int i = 0; i < Number_Subjects; i++)
        { cout << "\nEnter the score of subject " << i + 1 << endl;
          cin >> Marks[i];
          cout << "\nEnter the full mark of subject " << i + 1 << endl;
          cin >> Full_Marks[i];
        } cin.ignore();
        Calculate();
      } break;
  }
}

void student::Calculate() {
  Total_Score = 0; Total_Full_Marks = 0;
  for (int i = 0; i < Number_Subjects; i++)
  { Total_Score += Marks[i];
    Total_Full_Marks += Full_Marks[i];
  }
  Percentage = (Total_Score / Total_Full_Marks) * 100;
  if (Percentage < 50) Grade = 'F';
  else if (Percentage >= 50 && Percentage < 65) Grade = 'D';
  else if (Percentage >= 65 && Percentage < 75) Grade = 'C';
  else if (Percentage >= 75 && Percentage < 85) Grade = 'B';
  else Grade = 'A';
}

int student::Search_Number (int Target_Number, int Index ) {
  if (Roll_Number == Target_Number) return Index;
  else return -1;
}

int student::Search_Name(string Target_Name, int Index) {
  if (Name == Target_Name) return Index;
  else return -1;
}
