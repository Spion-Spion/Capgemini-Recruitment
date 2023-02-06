#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

struct Phone
{
    std::string brand_name;
    std::string model_name;
    std::string form_factor; //some kind of architecture( I made them up for example: "yes", "noq" etc )
    int year_of_issue;
    float screen_size; //inches 
    float price;
};

class Shop
{
private:
    std::vector<Phone> phone;

public:

    Shop(){}

    void add_phone(Phone& x);

    int add_phone_from_file(std::string); //return numbers of read phones
    int save_to_file(std::string);//return numbers of saved phones

    void delete_phone(int x); //give index to delete (start from 0 index)

    void report_same_name(std::string name); //return all parameters of phones with the same name
    void report_factor_screen(std::string name, float size);
    void report_max_amount(); //return the name the most stored brand
    void top_3(); //return 3 most popular models
};