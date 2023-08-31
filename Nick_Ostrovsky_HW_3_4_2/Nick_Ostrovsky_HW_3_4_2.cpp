

#include <iostream>
#include <fstream>
#include <string>
class Flat
{
private:
    std::string city;
    std::string street;
    int house;
    int flat_number;
public:
    Flat() : city("Kostroma"), street("Lovestreet"), house(1), flat_number(1)
    {};
    void set_city(std::string c) { city = c; };
    void set_street(std::string s) { street = s; };
    void set_house(int h) { house = h; };
    void set_flat_number(int fn) { flat_number = fn; };
    std::string get_city() { return city; };
    std::string get_street() { return street; };
    int get_house() { return house; };
    int get_flat_number() { return flat_number; };

};
int main()
{
    int list = 5;
    
    std::ifstream city_list("in.txt");
    if (city_list.is_open())
    {
        std::cout << " is_open() value: \t" << city_list.is_open() << std::endl;
    }
    else
    {

        std::cout << " File not found \t" << city_list.is_open() << std::endl;
        return (-1);
    }
    city_list >> list;
    Flat* location = new Flat[list];
    for (int i = 0; i < list; i++)

    {
        std::string c;
        city_list >> c;
        location[i].set_city(c);
        std::string s;
        city_list >> s;
        location[i].set_street(s);
        int h;
        city_list >> h;
        location[i].set_house(h);
        int fn;
        city_list >> fn;
        location[i].set_flat_number(fn);


    }
    Flat temp;

    for (int j = 0; j < list; j++)
    {
        for (int i = 0; i < list-1; i++)
        {
            std::string a = location[i].get_city();
            std::string b = location[i + 1].get_city();
           
            //std::cout << a << b << std::endl;
            if (b < a)
            {
                /*std::cout << a[0] << b[0] << std::endl;
                temp.set_city(((location[i + 1].get_city())));
                location[i + 1].set_city((location[i].get_city()));
                location[i].set_city((temp.get_city()));

                temp.set_street(location[i + 1].get_street());
                location[i + 1].set_street(location[i].get_street());
                location[i].set_street(temp.get_street());

                temp.set_house(location[i + 1].get_house());
                location[i + 1].set_house(location[i].get_house());
                location[i].set_house(temp.get_house());
                
                temp.set_flat_number(location[i + 1].get_flat_number());
                location[i + 1].set_flat_number(location[i].get_flat_number());
                location[i].set_flat_number(temp.get_flat_number());*/

                temp = location[i + 1];
                location[i + 1] = location[i];
                location[i] = temp;
            }
        }
    }
    std::ofstream new_city_list("out.txt");
    new_city_list << list;
   
    
        for (int i = 0; i < list; i++)

        {
           std::cout << "\n\t" << location[i].get_city() << ", " << location[i].get_street() << ", " << location[i].get_house() << ", " << location[i].get_flat_number() << std::endl;

            
            new_city_list << "\n\t" << location[i].get_city() << ", " << location[i].get_street() << ", " << location[i].get_house() << ", " << location[i].get_flat_number() << std::endl;



        }
    
    delete[] location;
    city_list.close();
    new_city_list.close();
    return 0;
}


