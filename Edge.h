/*
*           File:               Edge.cpp
*
*           Author:             Basil Moledina
*           Date:               10/17/2024
*           Description:        A 3-tuple representation of a state transition
*/



struct Edge
{
    int current_state;
    int next_state;
    char letter;
    
    Edge(int cur_state = -1, char letter = '\0', int next_state = -1)
    {
        this->current_state = cur_state;
        this->next_state = next_state;
        this->letter = letter;
    }


};

