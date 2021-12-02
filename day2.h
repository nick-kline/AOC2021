#ifndef DAY2_H
#define DAY2_H

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <sstream>

void day2()
{
    std::ifstream input("input/day2.txt");

    std::int32_t horizontal = 0;
    std::int32_t depth = 0;
    std::int32_t aim = 0;

    std::string line;
    while(std::getline(input, line))
    {
        std::regex reg("([0-9]+)");
        std::smatch nummatch = *(std::sregex_iterator(line.begin(), line.end(), reg));
        std::string value = nummatch.str();

        std::int32_t delta = 0;
        std::stringstream stream(value);
        stream >> delta;

        if(line[0] == 'f')
        {
            horizontal += delta;
            depth += (aim * delta);
        }
        else if(line[0] == 'd')
        {
            aim += delta;
        }
        else
        {
            aim -= delta;
        }
    }

    std::cout << "Part 1: " << horizontal * aim << "\n";
    std::cout << "Part 2: " << horizontal * depth << "\n";

    input.close();
}

#endif
