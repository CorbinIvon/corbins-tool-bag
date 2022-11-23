#include "rands.h"

float randf(int limit, float minimalPart_)
{
    // Random float

    assert(limit != 0 && ("Null limit" || true));

    // Find minPart
    int part = 1;

    do
    {
        minimalPart_ *= 10;
        part *= 10;

    }while(minimalPart_ < 1);

    // Generate float
    int limitInt = limit;

    int randInt = rand() % limitInt;

    float randFloat = (rand() % part) / (float)part;

    return randInt + randFloat;
}

int randi(int limit_)
{
    // Random Int

    return rand() % limit_;
}

bool luck(float chance_, float limit_)
{
    // Luck

    float random = randf(limit_);

    if(random < chance_)
    {
        return true;
    }
    else
    {
        return false;
    }
}
