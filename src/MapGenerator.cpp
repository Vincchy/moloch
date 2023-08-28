#include "MapGenerator.h"
#include <cstdlib>
#include <iostream>

MapGenerator::MapGenerator(int width, int height, unsigned int fillPercent)
{
    m_Width = width;
    m_Height = height;
    m_FillPercent = fillPercent;
    m_RandomSeed = true;
    m_Map = nullptr;

    InitMap();
}

void MapGenerator::SetSeed(unsigned int seed)
{
    m_RandomSeed = false;
    m_Seed = seed;
}

void MapGenerator::RandomizeMap()
{
    // Set the seed value
    if (m_RandomSeed)
        srand(time(NULL));
    else
        srand(m_Seed);

    // Initialize the map with values from 0 to 99
    for (int x=0; x<m_Width; x++)
    {
        for (int y=0; y<m_Height; y++)
        {
            m_Map[x][y] = (rand() % 100) >= m_FillPercent ? 0 : 1;
        }
    }
}

void MapGenerator::InitMap()
{
    m_Map = new int*[m_Width];
    for (int x=0; x<m_Width; x++)
    {
        m_Map[x] = new int[m_Height];
    }
}

void MapGenerator::PrintMap()
{
    if (m_Map != nullptr)
    {
        for (int y=0; y<m_Height; y++)
        {
            for (int x=0; x<m_Width; x++)
            {
                std::cout << m_Map[x][y];
            }
            std::cout << std::endl;
        }
    }
    else
        std::cout << "Failed to print uninitialized map.\n";
}

unsigned int MapGenerator::GetSurroundingWallCount(int x, int y)
{
    unsigned int neighbourCount = 0;
    for (int neighbourX=x-1; neighbourX<=x+1; neighbourX++)
    {
        for (int neighbourY=y-1; neighbourY<=y+1; neighbourY++)
        {
            // Skip the tile we're checking for
            if (neighbourX!=x || neighbourY!=y)
            {
                if (neighbourX>=0 && neighbourX<m_Width && neighbourY>=0 && neighbourY<m_Height)
                {
                    // If the neighbouring tile is a wall increase the count
                    if (m_Map[neighbourX][neighbourY] == 1)
                        neighbourCount++;
                }
                // If the tile lies on the outskirts of the map encourage the development of walls
                else
                    neighbourCount++;
            }

        }
    }
    return neighbourCount;
}

void MapGenerator::SmoothenMap()
{
    for (int x=0; x<m_Width; x++)
    {
        for (int y=0; y<m_Height; y++)
        {
            unsigned int neighbourCount = GetSurroundingWallCount(x, y);
            if (neighbourCount > 4)
                m_Map[x][y] = 1;
            if (neighbourCount < 4)
                m_Map[x][y] = 0;
        }
    }
}

void MapGenerator::GenerateMap()
{
    RandomizeMap();

    for (int i=0; i<6; i++)
        SmoothenMap();
}

int** MapGenerator::GetMap()
{
    return m_Map;
}


int MapGenerator::GetHeight()
{
    return m_Height;
}

int MapGenerator::GetWidth()
{
    return m_Width;
}
