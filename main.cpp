#include "header.h"
#include "14_tutorials.h"
#include "15_tutorials.h"

int main(){
    char choice;

    do
    {
        cout << "Number of New People Added right now Is : " << num_of_new_people_added << '\n';
        cout << "Number of People Loaded from the DB Is : " << num_of_people_loaded << '\n';
        cout << "Menu :\n";
        cout << "1. Insert People in the DB.\n";
        cout << "2. Show new People added right now.\n";
        cout << "3. Save People in The DB.\n";
        cout << "4. Load and Show People in DB.\n";
        cout << "5. Search about Person in the DB.\n";
        cout << "6. Remove a Person from the DB.\n";
        cout << "7. Remove New Person Added.\n";
        cout << "8. Update a Person in DB.\n";
        cout << "9. Update New Person Added.\n";

        choice = getch();

        switch(choice)
        {
            case '1':
                insert_in_dataBase();
                break;

            case '2':
                show_temporary_elements();
                break;

            case '3':
                save_in_DB();
                break;

            case '4':
                load_from_DB();
                break;
            
            case '5':
                search_in_DB();
                break;
            
            case '6':
                remove_a_person_in_DB();
                break;

            case '7':
                remove_new_person_added();
                break;

            case '8':
                Update_a_person_in_DB();
                break;
            
            case '9':
                Update_new_person_added();
                break;
        }

        require_pressing_enter();
    } while (choice != 27);  // 27 in ASCII Table equal (ESC Button)
}