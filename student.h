#include<iostream>
using namespace std;
class student {
  private:
    int Roll_Number;
    string Name;
    string Department;
    struct Address {
      string City;
      string Residential_Area;
      int Zip_Code;
    } s;
    int Number_Subjects;
    float Marks[10];
    int Full_Marks[10];
    float Total_Score;
    int Total_Full_Marks;
    char Grade;
    float Percentage;
  public:
    student();
    void Read();
    void Display();
    void Modify();
    void Calculate();
    int Search_Number (int Target_Number, int Index );
    int Search_Name(string Target_Name, int Index);
};
