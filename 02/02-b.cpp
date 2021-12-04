#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    std::string s;
    std::vector<std::string> OLines;
    while( getline(std::cin, s) ) {
        OLines.push_back(s);
    }

    // At the start they are the same
    std::vector<std::string> Co2Lines = OLines;


    int bitsPerRow = OLines.at(0).length();
    std::vector<std::string> ones;
    std::vector<std::string> zeroes;


    for (int i = 0; i < bitsPerRow; i++)
    {
        if (OLines.size() == 1)
        {
            break;
        }

        for (const std::string& line : OLines)
        {
            if (line.at(i) == '1')
            {
                ones.push_back(line);
            }
            else
            {
                zeroes.push_back(line);
            }
        }

        if (ones.size() >= zeroes.size())
        {
            OLines = ones;
        }
        else
        {
            OLines = zeroes;
        }

        ones.clear();
        zeroes.clear();
    }

    // Same thing for CO2 lines
    for (int i = 0; i < bitsPerRow; i++)
    {
        if (Co2Lines.size() == 1)
        {
            break;
        }

        for (const std::string& line : Co2Lines)
        {
            if (line.at(i) == '1')
            {
                ones.push_back(line);
            }
            else
            {
                zeroes.push_back(line);
            }
        }

        if (ones.size() < zeroes.size())
        {
            Co2Lines = ones;
        }
        else
        {
            Co2Lines = zeroes;
        }

        ones.clear();
        zeroes.clear();
    }

    std::cout << "O: " << OLines.at(0) << std::endl;
    std::cout << "CO2: " << Co2Lines.at(0) << std::endl;
    std::cout << "result: " << std::stoi(OLines.at(0), nullptr, 2) * std::stoi(Co2Lines.at(0), nullptr, 2) << std::endl;

    return EXIT_SUCCESS;
}
