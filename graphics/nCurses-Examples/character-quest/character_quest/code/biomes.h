#ifndef _FILE_BIOMES_
#define _FILE_BIOMES_

#include "biome.h"

#include <string>

using namespace std;

// --------------------------- Biomes ---------------------------

map <string, Biome*> biome;

void initBiomeForest();
void initBiomeHome();

void initBiomes()
{
    // Init biomes

    // Forest
    initBiomeForest();

    // Home
    initBiomeHome();
}

void initBiomeForest()
{
    // --------------------------- Forest ---------------------------

    // --------------------------- Static categories ---------------------------

    // Nature

    // Map
    map<string, BObj*> natureSCatMap =
                                                    {
                                                        {
                                                        "grass", new BObj(95.0f, 'm' | COLOR_PAIR(COLOR_GREEN))
                                                        },
                                                        {
                                                        "flower", new BObj(5.0f, 'l' | COLOR_PAIR(COLOR_CYAN))
                                                        }
                                                    }; // Objects

    // Category
    BObjCat *natureSCat = new BObjCat
                                                    (
                                                        100.0f,
                                                        natureSCatMap
                                                    ); // Static nature category

    // Map categories
    map<string, BObjCat*> sCatMap =
                                                    {
                                                        {
                                                        "nature", natureSCat
                                                        }
                                                    }; // Static categories

    // --------------------------- Dynamic categories ---------------------------

    // Nature

    // Map
    map<string, BObj*> natureDCatMap =
                                                   {
                                                        {
                                                        "stone", new BObj(100.0f, 'O')
                                                        }
                                                    }; // Objects


    // Category
    BObjCat *natureDCat = new BObjCat
                                                    (
                                                        100.0f,
                                                        natureDCatMap
                                                    ); // Dynamic nature category

    // Homes

    // Map
    map<string, BObj*> homesDCatMap =
                                                   {
                                                       {
                                                       "home", new BObj(2.0f, 'H')
                                                        }
                                                   }; // Objects

    // Category
    BObjCat *homesDCat = new BObjCat
                                                    (
                                                        10.0f,
                                                        homesDCatMap
                                                    ); // Dynamic homes category

    // Map categories
    map<string, BObjCat*> dCatMap =
                                                    {
                                                        {
                                                            "nature", natureDCat
                                                        },
                                                        {
                                                            "homes", homesDCat
                                                        }
                                                    }; // Dynamic categories

    // --------------------------- Biome ---------------------------

    biome["forest"] = new Biome
                                                (
                                                10.0f,
                                                sCatMap,
                                                dCatMap
                                                ); // Forest
}

void initBiomeHome()
{
    // --------------------------- Home ---------------------------

    // --------------------------- Static categories ---------------------------

    // Floor

    // Map
    map<string, BObj*> floorSCatMap =
                                                    {
                                                        {
                                                        "floor", new BObj(100.0f, ACS_CKBOARD)
                                                        }
                                                    }; // Objects

    // Category
    BObjCat *floorSCat = new BObjCat
                                                    (
                                                        100.0f,
                                                        floorSCatMap
                                                    ); // Static nature category

    // Map categories
    map<string, BObjCat*> sCatMap =
                                                    {
                                                        {
                                                        "floor", floorSCat
                                                        }
                                                    }; // Static categories

    // --------------------------- Dynamic categories ---------------------------

    // Furniture

    // Map
    map<string, BObj*> furnitureDCatMap =
                                                   {
                                                        {
                                                        "table", new BObj(50.0f, 'H')
                                                        },
                                                        {
                                                        "chair", new BObj(50.0f, 'Y')
                                                        }
                                                    }; // Objects


    // Category
    BObjCat *furnitureDCat = new BObjCat
                                                    (
                                                        100.0f,
                                                        furnitureDCatMap
                                                    ); // Dynamic furniture category

    // Map categories
    map<string, BObjCat*> dCatMap =
                                                    {
                                                        {
                                                            "furniture", furnitureDCat
                                                        }
                                                    }; // Dynamic categories

    // --------------------------- Biome ---------------------------

    biome["home"] = new Biome
                                                (
                                                10.0f,
                                                sCatMap,
                                                dCatMap
                                                ); // Forest
}

#endif // _FILE_BIOMES_
