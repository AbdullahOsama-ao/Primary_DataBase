#ifndef Header_H
#define Header_H

#include <iostream>
#include <conio.h>  // getch()
#include <cstdlib>  // system("cls")
#include <fstream>
#include <string>  // required for funcs. in remove people

#define PATH1 "D://a SourceFile//CPP//I_O Files//3. (Arkadiusz Woldarczyk)_YGH Official_youtube channel//Practising//14_15_in_tutorials//myFile.txt"
#define ARR_SIZE 20

using namespace std;

struct person
{
    string name;
    string tele;
    float age;
}p[ARR_SIZE], p_new[ARR_SIZE], for_search[ARR_SIZE], 
for_update[ARR_SIZE] = {{"NULL", "NULL" , 0}}, for_non_update[ARR_SIZE] = {{"NULL", "NULL", 0}};
int num_of_new_people_added = 0;
int num_of_people_loaded = 0;

void require_pressing_enter()
{
    cout << "\n\nPress Enter to continue ...\n";
    while (getch() != 13); // 13 in ASCII Table is equal (ENTER BUTTON);
    system("cls");
}

bool is_there_file_data()
{
    ifstream file(PATH1);

    if(file.is_open())
    {
        file.seekg(0, ios::end);

        if(file.tellg() > 0)
            return true;
        
        else
            return false;     
    }
    else
    {
        return false;
    }
}

void show_file_data_elements()
{
        cout << "\nName\t\t\tAge\t\t\tTelephone\n";
        for(int i=0; i<num_of_people_loaded; i++)
        {
            cout << p_new[i].name << "\t\t\t";
            cout << p_new[i].age << "\t\t\t";
            cout << p_new[i].tele << '\n';
        }
}

int num_of_file_lines()
{
    ifstream file(PATH1);

    if(file.is_open())
    {
        int i = 0;
        string line;

        do
        {
            getline(file, line);
            i++;
        }while(!file.eof());

        file.close();
        return i;
    }
    else
        return -1;   
}

void num_of_chars_per_line()                     // isn't used (you can change it when you need).
{
    ifstream file(PATH1);

    if(file.is_open())
    {
        string line;

        while (getline(file, line));           // while stop (defaultly) when (eof) is true.
            cout << (int)file.tellg()-1 << '\n';    // minus 1 because (getline) extracts the '\n'.
    }
    else
        cout << "Can't open the file to count num of chars per a line!\n";
}

void show_found_in_file_search(int counter)
{
    if(counter > 0)
    {
        cout << "\nName\t\t\tAge\t\t\tTelephone\n";
        for(int i=0; i<counter; i++)
        {
            cout << for_search[i].name << "\t\t\t";
            cout << for_search[i].age << "\t\t\t";
            cout << for_search[i].tele << '\n';
        }
    }
    else
        cout << "No Such This Name be found in the DB!\n";        
}

void save_after_delete()
{
    ofstream file(PATH1, ios::out);

    if (file.is_open())
    {
        for (int i = 0; i<num_of_people_loaded; i++)
        {
            file << p_new[i].name << "\t\t\t";
            file << p_new[i].age << "\t\t\t";
            file << p_new[i].tele << '\n';
        }
        cout << "Deleted Successfully ..!\n";
            
        file.close();
    }
    else
        cout << "Can't open the file to applicate deletion!\n";
}

void load_from_DB_without_showing()
{
    ifstream file(PATH1);

    if (file.is_open())
    {
        if (num_of_file_lines() < 0)
        {
            cout << "There is a proplem happend during estimate file lines to remove an element!\n";
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
        }
    }
    else
    {
        cout << "There is a proplem happend during opening the file to remove an element!\n";
    }
}

void show_found_repeated_name_during_update(int counter) // related to Update a Person In DB (coming soon)
{
    cout << "\nName\t\t\tAge\t\t\tTelephone\n";
        for(int i=0; i<counter; i++)
        {
            if(for_update[i].age != 0)
            {
                cout << i << ". " << for_update[i].name << "\t\t\t";
                cout << for_update[i].age << "\t\t\t";
                cout << for_update[i].tele << '\n';
            }
        }
}

void save_after_update()                                 // related to Update a Person In DB (coming soon)
{
    ofstream file(PATH1, ios::out);

    if (file.is_open())
    {
        for (int i = 0; i<num_of_people_loaded; i++)
        {
            if(for_update[i].name != "NULL")
            {
                file << for_update[i].name << "\t\t\t";
                file << for_update[i].age << "\t\t\t";
                file << for_update[i].tele << '\n';
            }
            else
            {
                file << for_non_update[i].name << "\t\t\t";
                file << for_non_update[i].age << "\t\t\t";
                file << for_non_update[i].tele << '\n';
            }
        }
        cout << "Updated Successfully ..!\n";
            
        file.close();
    }
    else
        cout << "Can't open the file to applicate Saving Updating!\n";
}

#endif