#include "header.h"

void save_in_DB()
{
    ofstream file(PATH1, ios::app);

    if (file.is_open())
    {
        if (num_of_new_people_added > 0)
        {
            for (int i = 0; i < num_of_new_people_added; i++)
            {
                file << p[i].name << "\t\t\t";
                file << p[i].age << "\t\t\t";
                file << p[i].tele << '\n';
            }
            cout << "Added Successfully ..!\n";
            num_of_new_people_added = 0;
        }
        else
        {
            cout << "there isn't any new person to save to the DB.\n";
        }

        file.close();
    }
    else
    {
        cout << "Can't open the file.\n";
    }
}

void load_from_DB()
{
    ifstream file(PATH1);

    if (file.is_open())
    {
        if (is_there_file_data())
        {
            if (num_of_file_lines() > ARR_SIZE)
            {
                cout << "File is too big to show its data!\n";
                return;
            }

            else if (num_of_file_lines() < 0)
            {
                cout << "can't open the file to estimate data inside!\n";
                return;
            }
            else
            {
                int i = 0;

                do
                {
                    file >> p_new[i].name;
                    file >> p_new[i].age;
                    file >> p_new[i].tele;
                    i++;

                } while (!file.eof());
                num_of_people_loaded = i - 1;

                cout << "Loaded Successfully ..!\n\n";
                show_file_data_elements();
            }
        }
        else
        {
            cout << "There is no data to be loaded!\n";
        }
    }
    else
    {
        cout << "the file can't be opened !\n";
    }
}

void search_in_DB()
{
    ifstream file(PATH1);

    if (file.is_open())
    {
        if (is_there_file_data())
        {
            string name;
            int counter = 0;

            cout << "The Name to search : ";
            cin >> name;

            do
            {
                file >> for_search[counter].name;

                if (name == for_search[counter].name)
                {
                    file >> for_search[counter].age;
                    file >> for_search[counter].tele;
                    counter++;
                }
                else
                    file.ignore(100, '\n');
            } while (!file.eof());

            file.close();
            show_found_in_file_search(counter);
        }
        else
            cout << "There is no data in the file to search in.\n";
    }
    else
    {
        cout << "Can't open the file to search.\n";
    }
}

void remove_a_person_in_DB()
{
    ifstream file(PATH1);

    if (file.is_open())
    {
        if(is_there_file_data())
        {
            load_from_DB_without_showing();
            string name;
            bool flag = false;

            cout << "The Name to Delete : ";
            cin >> name;

            for(int i=0; i<num_of_file_lines(); i++)
            {
                if(p_new[i].name == name)
                {
                    flag = true;
                    for(int j=i; j<num_of_people_loaded-1; j++)
                    {
                        p_new[j].name = p_new[j+1].name;  
                        p_new[j].age = p_new[j+1].age;
                        p_new[j].tele = p_new[j+1].tele;
                    }
                    num_of_people_loaded--; 
                } 
            }

            if(flag == true)
                save_after_delete();
            else    
                cout << "There isn't any Person has this Name to be removed!\n";   
        }
        else
            cout << "There is no data in DB to be deleted!\n";
    }
    else
        cout << "Can't open the file to remove !\n";
}

void Update_a_person_in_DB()      
{
    cout << "Coming Soon ... !\n";
    /*

        ifstream file(PATH1);

        if(file.is_open())
        {
            if(is_there_file_data())
            {
                load_from_DB_without_showing();
                string name;
                int check_repeating = 0;
                int choice;
                bool flag = false;

                cout << "The Name to Update : ";
                cin >> name;

                for(int i=0; i<num_of_file_lines(); i++)
                {
                    if(p_new[i].name == name)
                    {
                        flag = true;
                        for_update[i].name = p_new[i+1].name;  
                        for_update[i].age = p_new[i+1].age;
                        for_update[i].tele = p_new[i+1].tele;

                        check_repeating++;
                    }
                    else
                    {
                        for_non_update[i].name = p_new[i+1].name;  
                        for_non_update[i].age = p_new[i+1].age;
                        for_non_update[i].tele = p_new[i+1].tele;
                    }
                }

                if(flag == true)
                {
                    if(check_repeating > 1)
                    {
                        cout << "There is more one Person with same Name, Choose Number of person you want to update bellow :\n";
                        show_found_repeated_name_during_update(check_repeating);
                        cin >> choice;
                        cout << "New Name : ";
                        cin >> for_update[choice-1].name;
                        cout << "New Age : ";
                        cin >> for_update[choice-1].age;
                        cout << "New Telephone : ";
                        cin >> for_update[choice-1].tele;

                        save_after_update();
                    }

                    else
                    {
                        show_found_repeated_name_during_update(check_repeating);
                        cout << "New Name : ";
                        cin >> for_update[0].name;
                        cout << "New Age : ";
                        cin >> for_update[0].age;
                        cout << "New Telephone : ";
                        cin >> for_update[0].tele;

                        save_after_update();
                    }
                }
                else
                {
                    cout << "There isn't any Person has like Name to be Updated!\n";
                }
            }
            else
            {
                cout << "File has No Data to be Updated!\n";
            }
        }
        else
            cout << "File Can't be opened for Updating!\n";
    
    */
}