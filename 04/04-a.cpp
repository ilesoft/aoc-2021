#include <iostream>
#include <string>

int main()
{
    std::string s;
    // Let's assume there are maximum of 256 vents per point => uint8_t
    uint8_t seaFloor[1000][1000] = {0};
    uint16_t position;
    int count = 0;

    while( getline(std::cin, s) )
    {
        std::string::size_type pos1 = s.find(",");
        std::string::size_type pos2 = s.find(" -> ");
        std::string::size_type pos3 = s.find_last_of(",");
        uint16_t startX = std::stoul(s);
        uint16_t startY = std::stoul(s.substr(pos1+1));
        uint16_t endX   = std::stoul(s.substr(pos2+4));
        uint16_t endY   = std::stoul(s.substr(pos3+1));

        if (startX != endX && startY != endY) continue;

        // adapt to the direction on line
        bool incr = true;

        if (startX == endX)
        {
            if (startY > endY) incr = false;

            position = startY;
            while (true)
            {
                if (++seaFloor[startX][position] == 2) ++count;

                if (position == endY) break;

                if(incr) ++position;
                else --position;
            }
        }
        else if (startY == endY)
        {
            if (startX > endX) incr=false;

            position = startX;
            while (true)
            {
                if (++seaFloor[position][startY] == 2) ++count;

                if (position == endX) break;

                if(incr) ++position;
                else --position;
            }
        }
    }

    std::cout << count << std::endl;

    return EXIT_SUCCESS;
}
