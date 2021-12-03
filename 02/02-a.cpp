#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    std::string s;
    std::vector<std::string> lines;
    while( getline(std::cin, s) ) {
        lines.push_back(s);
    }


    int bitsPerRow = lines.at(0).length();

    std::vector<int> heatMap(bitsPerRow, 0);

    for (const std::string& line : lines)
    {
        int i = 0;
        for (char c : line)
        {
            if (c == '1')
            {
                heatMap[i]++;
            }
            i++;
        }
    }

    std::string gamma(bitsPerRow, '0');
    std::string epsilon(bitsPerRow, '1');
    int halfInputLength = lines.size() / 2;
    int i = 0;
    for (int bitCount : heatMap)
    {
        if (bitCount > halfInputLength)
        {
            gamma.at(i) = '1';
            epsilon.at(i) = '0';
        }
        i++;
    }
    std::cout << "gamma: " << gamma << std::endl;
    std::cout << "epsilon: " << epsilon << std::endl;
    std::cout << "result: " << std::stoi(gamma, nullptr, 2) * std::stoi(epsilon, nullptr, 2) << std::endl;

    return EXIT_SUCCESS;
}
