#ifndef DAY1_H
#define DAY1_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <sstream>
#include <vector>

void part1(const std::vector<std::uint32_t>& adepths)
{
    std::uint32_t increase = 0;
    for(std::size_t i = 1; i < adepths.size(); ++i)
    {
        increase += static_cast<std::uint32_t>(adepths[i] > adepths[i-1]);
    }
    std::cout << "Number of increases: " << increase << std::endl;
}

void part2(const std::vector<std::uint32_t>& adepths)
{
    std::vector<std::uint32_t> threesum;
    for(std::size_t i = 0; i < adepths.size() - 2; ++i)
    {
        std::uint32_t sum = adepths[i] + adepths[i+1] + adepths[i+2];
        threesum.push_back(sum);
    }

    part1(threesum);
}

void day1()
{
    std::ifstream input("input/day1.txt");
    std::vector<std::uint32_t> depths;

    std::string line;
    while(std::getline(input, line))
    {
        std::stringstream stream(line);
        std::uint32_t depth = 0;
        stream >> depth;
        depths.push_back(depth);
    }

    std::cout << "Part 1\n";
    part1(depths);
    std::cout << "Part 2\n";
    part2(depths);

    input.close();
}

#endif
