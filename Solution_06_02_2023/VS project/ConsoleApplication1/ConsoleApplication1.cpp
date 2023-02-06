//Solution by Kacper Dziembek https://github.com/Spion-Spion
//
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "shop.h"

using namespace std;

int main()
{
    Shop shop;
    Phone phone = { "Samsung", "Galaxy", "yes", 2010, 6.8, 999.99f };

    //self-testing

    shop.add_phone(phone);
    phone = { "Samsung", "Space", "noq", 2012, 5.8, 1000.99f };
    shop.add_phone(phone);
    phone = { "Samsung", "Jupiter", "xcv", 2018, 7.8, 1000.99f };
    shop.add_phone(phone);
    phone = { "LG", "L5", "yes", 2010, 6.8, 1000.99f };
    shop.add_phone(phone);
    phone = { "LG", "HEYA", "qwerty", 2022, 2.8, 678.99f };
    shop.add_phone(phone);
    phone = { "Realme", "X21", "yes", 2020, 7.8, 500.99f };
    shop.add_phone(phone);
    phone = { "Realme", "X21", "yes", 2020, 7.8, 500.99f };
    shop.add_phone(phone);
    phone = { "Realme", "X22", "yes", 2020, 3.8, 500.99f };
    shop.add_phone(phone);
    phone = { "Realme", "X23", "yes", 2022, 6.8, 450.99f };
    shop.add_phone(phone);
    phone = { "Huawei", "Hello", "xaw", 2022, 2.8, 450.99f };
    shop.add_phone(phone);
    phone = { "Realme", "X241", "yes", 2021, 7.8, 980.99f };
    shop.add_phone(phone);

    shop.report_same_name("Samsung");
    shop.report_same_name("LG");

    cout << endl;
    shop.report_factor_screen("yes", 6.8f);

    cout << endl;
    shop.report_max_amount();

    cout << endl;
    shop.top_3();

    cout << endl;
    cout << "added phones: " << shop.add_phone_from_file("phones.txt") << endl;

    cout << endl;
    shop.report_same_name("Samsung");

    cout << endl;
    cout << "saved phones to file: " << shop.save_to_file("backup.txt") << endl;
    
}

