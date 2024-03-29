#include <iostream>
#include <vector>
#include <fstream>

#include "flight.hpp"
#include "file.hpp"

void place(std::vector<std::string> &v, std::string s)
{
    v.push_back(s);
}

std::string readFile(std::string filename)
{
    std::ifstream file;
    std::string line;
    // std::stringstream ss;
    char x;
    file.open(filename);
    std::string str = "";
    for (std::string line; getline(file, line);)
    {
        std::cout << line;
    }
    return str;
}

int main(int argc, char *argv[])
{
    std::vector<flight> flights;
    flight a1("s1");
    flight a2("s2");
    flight a3("s3");

    flights.push_back(a1);
    flights.push_back(a2);
    flights.push_back(a3);

    flights[0].append({"Raja", "Mohan", "Phalguni", "Mahima"});
    flights[0].remove("Raja");
    
    flights[1].append({"Raja", "Mohan", "Phalguni"});
    flights[1].remove("Mohan");

    // flights[0].remove({"Raja", "Mahima"});

    std::cout << (flights[0].print());
    std::cout << (flights[1].print());

    // while (true)
    // {
    //     char ch;
    //     std::cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         std::cout << "Enter Passenger Number:";
    //         int x;
    //         std::cin >> x;
    //         for (size_t i = 0; i < x; i++)
    //         {
    //             std::vector<std::string> v;
    //             for (auto &&i : v)
    //             {
    //                 std::cin >> v;
    //             }
                
    //             /* code */
    //         }
            
    //     case 2:
    //     case 3:
    //     }
        /* code */
    // }

    // std::cout << k[0];
    // std::string str((std::istreambuf_iterator<char>(t)),
    //                 std::istreambuf_iterator<char>());

    // std::string delimiter = "\n";

    // size_t pos = 0;
    // std::string token;
    // int flag = 0;
    // std::vector<std::string> vec;
    // while ((pos = str.find(delimiter)) != std::string::npos)
    // {
    //     token = str.substr(0, pos);

    //     vec.push_back(std::string(token));
    //     // lib::print(vec[0]);
    //     // std::cout << token << std::endl;
    //     str.erase(0, pos + delimiter.length());
    //     if (!(pos = str.find(delimiter)) != std::string::npos)
    //     {
    //         for (size_t i = 0; i < vec.size(); i++)
    //         {
    //             lib::print(vec[i]);
    //         }
    //     }
    // }

    // std::cout << str << std::endl;
    // int count = 0;
    // std::string temp = "";
    // std::vector<std::string> vec;
    // vec.reserve(10);
    // for (size_t i = 0; i < str.size(); i++)
    // {
    //     if (str[i] == '\n')
    //     {
    //         vec[count]=temp;
    //         count++;
    //         temp="";
    //         continue;
    //     }
    //     temp += str[i];
    // }

    // for (size_t i = 0; i < vec.size(); i++)
    // {
    //     std::cout << vec[i];
    // }

    return 0;
}