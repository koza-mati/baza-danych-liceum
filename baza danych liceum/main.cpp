#include "classes.hpp"

int main() {
   int choice2 = 0;

   cout << "===============\nChoose option:\n =============== \n";
   cout << "1. Add assassment for students " << endl;
   cout << "2. Change students list" << endl;

   cin >> choice2;



   if(choice2 == 1) {

       int choice = 0;
       student s;
       for (int i = 1; i++; i = choice) {

           cout << "===============\nChoose option:\n ===============\n";
           cout << "1. Display saved students " << endl;
           cout << "2. Remove saved student" << endl;
           cout << "3. Add student to data" << endl;
           cout << "4. EXIT" << endl;

           cout << "Choice: ";
           cin >> choice;

           switch (choice) {
           case 1:
           {
               s.display_data();
           }break;
           case 2:
           {
               s.remove_data();
           }break;
           case 3:
           {
               s.add_student();
           }break;
           case 4:
           {
               return 0;
           }break;
           default:
               cout << "Nieprawid³owy wybór!\n";
           }
       }
   }
   else {





   }

}
