#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H


class MapGenerator
{
    public:
        MapGenerator(int width, int height, unsigned int fillPercent);
        void SetSeed(unsigned int seed);
        void GenerateMap();

        // Debug function
        void PrintMap();
        int** GetMap();
        int GetWidth();
        int GetHeight();

    private:
        int** m_Map;
        int m_Width;
        int m_Height;
        unsigned int m_Seed;
        bool m_RandomSeed;

        unsigned int m_FillPercent;

        void RandomizeMap();
        void InitMap();
        unsigned int GetSurroundingWallCount(int x, int y);
        void SmoothenMap();
};

#endif // MAPGENERATOR_H
