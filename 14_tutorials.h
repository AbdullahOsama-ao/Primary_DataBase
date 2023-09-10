#include "header.h"

void insert_in_dataBase()
{
    int num, i=0;
    cout << "How many People would you like to insert? : ";
    cin >> num;

    while(num--){
        cout << "\nName : ";    cin >> p[num_of_new_people_added].name;
        cout << "Age : ";       cin >> p[num_of_new_people_added].age;
        cout << "Telephone : "; cin >> p[num_of_new_people_added].tele;

        num_of_new_people_added++;
    }

}

void show_temporary_elements()
{
    if(num_of_new_people_added > 0)
    {
        cout << "\nName\t\t\tAge\t\t\tTelephone\n";
        for(int i=0; i<num_of_new_people_added; i++)
        {
            cout << p[i].name << "\t\t\t";
            cout << p[i].age << "\t\t\t";
            cout << p[i].tele << '\n';
        }
    }
    else 
        cout << "There isn't any new person added to show,\ntry to load People data from the DB.\n";
}

void remove_new_person_added()
{
    if (num_of_new_people_added == 0)
    {
        cout << "No New People Added to be Deleted!\n";
        return ;
    }
    
    string name;
    int temp;
    bool flag = false;

    cout << "The Name to delete : ";
    cin >> name;
    temp = num_of_new_people_added;

    for(int i=0; i<temp; i++)
    {
        if(p[i].name == name)
        {
            flag = true;
            for(int j=i; j<num_of_new_people_added-1; j++)
            {
                p[j].name = p[j+1].name;  
                p[j].age = p[j+1].age;
                p[j].tele = p[j+1].tele;
            }
            num_of_new_people_added--; 
        } 
    }

    if(flag == true)
        cout << "Deleted Successfully ..!\n";
    else
        cout << "There isn't like this Name to be deleted!\n";
}

void Update_new_person_added()
{
    cout << "Coming Soon ..!\n";
    /* 
        if (num_of_new_people_added == 0)
        {
            cout << "No New People Added to be Updated!\n";
            return ;
        }

        string name;
        int check_repeating = 0, choice, j, catch_index;
        bool flag = false;

        cout << "The Name to Update : ";
        cin  >> name;

        for(int i=0; i<num_of_new_people_added; i++)
        {
            if(p[i].name == name)
            {
                if(flag == false)     
                    catch_index = i;    // this line for catching first index that achive first enter in this if.
                flag = true;
                
                for_update[i].name = p[i+1].name;  
                for_update[i].age = p[i+1].age;
                for_update[i].tele = p[i+1].tele;

                check_repeating++;
            }
        }

        if(flag == true)
        {
            if(check_repeating > 1)
            {
                cout << "There is more one Person with same Name, Choose Number of person you want to update bellow :\n";
                show_found_repeated_name_during_update(num_of_new_people_added);
                cin >> choice;
                
                cout << "New Name : ";
                cin >> for_update[choice].name;
                cout << "New Age : ";
                cin >> for_update[choice].age;
                cout << "New Telephone : ";
                cin >> for_update[choice].tele;

                cout << "Updated Successfully !\n";
            }
            else
            {
                show_found_repeated_name_during_update(num_of_new_people_added);
                cout << "New Name : ";
                cin >> for_update[catch_index].name;
                cout << "New Age : ";
                cin >> for_update[catch_index].age;
                cout << "New Telephone : ";
                cin >> for_update[catch_index].tele;

                cout << "Updated Successfully !\n";
            }
        }
        else
        {
            cout << "There isn't any Person has like Name to be Updated!\n";
        }
    */
}