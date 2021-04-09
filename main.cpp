#include <iostream>
#include"student.h"
using namespace std;
const int Num_Students = 10;

int main() {
  int Counter = -1;//Acts as an index for controlling the objects of the class
  student objects[Num_Students];
  while (1)
  { cout << "\n1. Insert a new student's record into the system\n";
    cout << "2. Search for a student via their roll number or via their name\n";
    cout << "3. Modify student's details\n";
    cout << "4. calculate the total score and grade of the student and add it to his record\n";
    cout << "5. print student information\n";
    cout << "6. Exit\n";
    cout << "\n\tPlease choose an option from <1-6>:\n\n";
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 6)
    { cout << "Invalid input! please enter a number between <1-6>\n\n";
      cin >> choice;
    } cin.ignore();
    switch (choice) {
      case 1:  {Counter++;
      if(Counter>=Num_Students)
        {cout<<"The database has reached the maximum number of students"<<endl;
        cout<<"No more information can be inserted"<<endl;
      break;}
          objects[Counter].Read();
          cout<<"\n\n A new record has been created successfully!\n\n";
        } break;
      case 2:  {
          cout << "\nChoose 1 OR 2:\n";
          cout << "1. Search by name\n";
          cout << "2. Search by roll number\n";
          int AA; cin >> AA; cin.ignore();
          while (AA>2 || AA<1)
          {
              cout<<"Invalid input! Please enter a number between <1-2>\n\n";
              cin>>AA;
          }
          if (AA == 1) {
            string Target_Name;
            cout << "\nEnter the name you're searching for\n";
            getline(cin, Target_Name);
            int k;
            for (int Index = 0; Index <= Counter; Index++)
            { k = objects[Index].Search_Name(Target_Name, Index);
              if (k >= 0) {
                cout << "\nStudent found!\n\n";
                cout<<"1. Display student's record\n";
                cout<<"2. Modify student's record\n";
                cout<<"\n\tSelect an option from <1-2>\n";
                int BB; cin>>BB; cin.ignore();
                while (BB <1 || BB>2)
                {cout<<"\nInvalid input! Please enter a number between <1-2>\n";
                cin>>BB;}
                if (BB==1) objects[k].Display();
                else if(BB==2) {objects[k].Modify();
                cout << "\nRecord updated\n";}
                break;
              }
            }
            if (k <0 || k>Num_Students-1)
              cout << "\nTarget was not found! the name you're searching for has no record\n\n";

          }
          else if (AA == 2) {
            int Target_Number;
            cout << "\nEnter the number of the student you're searching for\n";
            cin >> Target_Number; cin.ignore();
            int k;
            for (int Index = 0; Index <= Counter; Index++)
            { k = objects[Index].Search_Number(Target_Number, Index);
              if (k >= 0)
              {

                cout << "\nStudent found!\n\n";
                cout<<"1. Display student's record\n";
                cout<<"2. Modify student's record\n";
                cout<<"\n\tSelect an option from <1-2>\n";
                int CC; cin>>CC; cin.ignore();
                while (CC <1 || CC>2)
                {cout<<"\nInvalid input! Please enter a number between <1-2>\n";
                cin>>CC;}
                if (CC==1) objects[k].Display();
                else if(CC==2) {objects[k].Modify();
                cout << "\nRecord updated\n";}
                break;
              }
            }
            if (k <0 || k>Num_Students-1)
              cout << "\nTarget was not found! the name you're searching for has no record\n\n";
          }
        } break;
      case 3:  {
          int Target_Number;
          cout << "Enter the roll number of the student you want to modify his data\n";
          cin >> Target_Number; cin.ignore();
          int k;
          for (int Index = 0; Index <= Counter; Index++)
          { k = objects[Index].Search_Number(Target_Number, Index);
            if (k >= 0) {
              objects[k].Modify();
              cout << "\nRecord updated\n";
              break;
            }
          }
          if (k <0 || k>Num_Students-1)
            cout << "\nRecord not found\n\n";
        } break;
      case 4: {
          string Target_Name;
          cout << "Enter the name of the student you want to calculate his marks\n";
          getline(cin, Target_Name);
          int k;
          for (int Index = 0; Index <= Counter; Index++)
          { k = objects[Index].Search_Name(Target_Name, Index);
            if (k >= 0) {
              objects[k].Calculate();
              cout << "\nstudent found! grade and percentage have been added to his record successfully!\n\n";
              break;
            }
          }
          if (k <0 || k>Num_Students-1)
            cout << "\nTarget was not found! no records were updated\n\n";
        } break;
      case 5: {
          string Target_Name;
          cout << "Enter the name of the student you want to display his record\n";
          getline(cin, Target_Name);
          int k;
          for (int Index = 0; Index <= Counter; Index++)
          { k = objects[Index].Search_Name(Target_Name, Index);
            if (k >= 0) {
              objects[k].Display();
              break;
            }
          }
          if (k <0 || k>Num_Students-1)
            cout << "\nTarget was not found!\n\n";

        }  break;
        case 6: {
        return 0;}

    }

  }

}
