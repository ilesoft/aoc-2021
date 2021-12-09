#include <iostream>
#include <string>

int main()
{
    std::string s;
    // Let's assume there are maximum of 256 vents per point => uint8_t
    uint8_t seaFloor[1000][1000] = {0};
    int position;
    int pointsWithMoreThanOneVent = 0;

    while( getline(std::cin, s) )
    {
        std::string::size_type pos1 = s.find(",");
        std::string::size_type pos2 = s.find(" -> ");
        std::string::size_type pos3 = s.find_last_of(",");
        int startX = std::stoul(s);
        int startY = std::stoul(s.substr(pos1+1));
        int endX   = std::stoul(s.substr(pos2+4));
        int endY   = std::stoul(s.substr(pos3+1));

        if (startX != endX && startY != endY) continue;

        // adapt to the direction on line
        bool incr = true;

        if (startX == endX)
        {
            if (startY > endY) incr = false;

            position = startY;
            while (true)
            {
                if (++seaFloor[startX][position] == 2) ++pointsWithMoreThanOneVent;

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
                if (++seaFloor[position][startY] == 2) ++pointsWithMoreThanOneVent;

                if (position == endX) break;

                if(incr) ++position;
                else --position;
            }
        }
    }

    std::cout << pointsWithMoreThanOneVent << std::endl;

    return EXIT_SUCCESS;
}
