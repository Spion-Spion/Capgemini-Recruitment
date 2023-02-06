#include "shop.h"

using namespace std;

int Shop::add_phone_from_file(string path)
{
    fstream file(path.c_str());
    Phone temp;
    int quantity = 0;

    if (file.is_open())
    {
        string brand_name, model_name, form_factor, year_of_issue, screen_size, price;
        while (file >> brand_name >> model_name >> form_factor >> year_of_issue >> screen_size >> price)
        {
            temp.brand_name = brand_name;
            temp.model_name = model_name;
            temp.form_factor = form_factor;
            temp.year_of_issue = stoi(year_of_issue);
            temp.screen_size = stof(screen_size);
            temp.price = stof(price);

            phone.push_back(temp);
            quantity++;
        }

        file.close();
    }

    return quantity;
}

int Shop::save_to_file(string path)
{
    fstream file(path.c_str(), ios_base::in | ios_base::out);
    int quantity = 0;

    if (file.is_open())
    {
        for (int i = 0; i < phone.size(); i++)
        {
            file
                << phone[i].brand_name << " "
                << phone[i].model_name << " "
                << phone[i].form_factor << " "
                << phone[i].year_of_issue << " "
                << phone[i].screen_size << " "
                << to_string(phone[i].price)
                << endl;
            quantity++;
        }

        file.close();
    }

    return quantity;
}

void Shop::add_phone(Phone& x)
{
    phone.push_back(x);
}

void Shop::delete_phone(int x)
{
    phone.erase(phone.begin() + x);
}

void Shop::report_same_name(string name)
{
    for (int i = 0; i < phone.size(); i++)
    {
        if (phone[i].brand_name == name)
        {
            cout << "No." << i + 1 << "\t" <<
                "Brand: " << phone[i].brand_name << "\t" <<
                "Model: " << phone[i].model_name << "\t" <<
                "Form_factor: " << phone[i].form_factor << "\t" <<
                "Screen Size: " << phone[i].screen_size << "\t" <<
                "Year of issue: " << phone[i].year_of_issue << "\t" <<
                "Price: " << phone[i].price << "\t"
                << endl;
        }
    }
}

void Shop::report_factor_screen(string name, float size)
{
    for (int i = 0; i < phone.size(); i++)
    {
        if (phone[i].form_factor == name && phone[i].screen_size == size)
        {
            cout << "No." << i + 1 << "\t" <<
                "Brand: " << phone[i].brand_name << "\t" <<
                "Model: " << phone[i].model_name << "\t" <<
                "Form_factor: " << phone[i].form_factor << "\t" <<
                "Screen Size: " << phone[i].screen_size << "\t" <<
                "Year of issue: " << phone[i].year_of_issue << "\t" <<
                "Price: " << phone[i].price << "\t"
                << endl;
        }
    }
}

void Shop::report_max_amount()
{
    vector<string> name;
    vector<int> how_many;
    bool repeat = false;

    if (phone.size() > 0)
    {
        name.push_back(phone[0].brand_name);
        how_many.push_back(1);

        for (int i = 1; i < phone.size(); i++)
        {
            repeat = false;

            for (int x = 0; x < name.size(); x++)
            {
                if (name[x] == phone[i].brand_name)
                {
                    how_many[x]++;
                    repeat = true;
                    break;
                }
            }

            if (repeat == false)
            {
                name.push_back(phone[i].brand_name);
                how_many.push_back(1);
            }
        }
    }

    int max = 0;
    string brand;

    max = how_many[0];
    for (int i = 1; i < name.size(); i++)
    {
        if (how_many[i] > max)
        {
            max = how_many[i];
            brand = name[i];
        }
    }

    cout << "brand = " << brand << "   max quantity = " << max << endl;
}

void Shop::top_3()
{
    vector<float> screen;
    vector<int> how_many;
    bool repeat = false;

    if (phone.size() > 0)
    {
        screen.push_back(phone[0].screen_size);
        how_many.push_back(1);

        for (int i = 1; i < phone.size(); i++)
        {
            repeat = false;

            for (int x = 0; x < screen.size(); x++)
            {
                if (screen[x] == phone[i].screen_size)
                {
                    how_many[x]++;
                    repeat = true;
                    break;
                }
            }

            if (repeat == false)
            {
                screen.push_back(phone[i].screen_size);
                how_many.push_back(1);
            }
        }
    }


    int max;
    float result;
    int index;

    for (int x = 0; x < 3; x++)
    {
        result = screen[0];
        max = how_many[0];
        index = 0;

        for (int i = 0; i < screen.size(); i++)
        {
            if (how_many[i] > max)
            {
                max = how_many[i];
                result = screen[i];
                index = i;
            }
        }

        cout << "screen size = " << result << "  how many = " << max << endl;
        screen.erase(screen.begin() + index);
        how_many.erase(how_many.begin() + index);
    }
}
