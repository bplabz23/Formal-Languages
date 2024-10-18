/*
*           File:               TestDriver.cpp
*
*           Author:             Basil Moledina
*           Date:               10/17/2024
*           Description:        Test program for finite automata and its various pieces
*/



#include "Edge.h"
#include <vector>
#include <string>
#include <iostream>


using namespace std;






// Pass a snapshot to the current function, returns the next state if one can be found
//  Sort of the "control unit" of the transition function, the actual do-er

int search_transitions(char cur_letter, int cur_state, vector<Edge> delta)
{
    // For every rule e in our transition function
    
    for (Edge e: delta)
    {
        // If our snapshot matches with transition rule e
        if(cur_state == e.current_state && cur_letter == e.letter)
        {
            // Return this transition/edge's next state
            return e.next_state;
        }
    } 

    // Otherwise, if no such edge e exists, return "not found"
    return -1;

}











// Passes a word to a DFA and then returns the halting state

int read_word(string word, int cur_state, vector<Edge> delta)
{

    // Base Case 1: If word is empty, return current state
    
    if (word.empty() == true)
    {
        return cur_state;
    }


    // Otherwise, take the first letter of the word and find the next state 

    int next_state = search_transitions(word[0], cur_state, delta);



    // Base Case 2: If the transition to the next state is undefined, return undefined state

    if (next_state == -1)
    {
        return -1;
    }



    // Otherwise, if transition is defined, the next state becomes our current state
    cur_state = next_state; 

    // In the process of transitioning, the first letter in the word also gets consumed,
    //  and the word we are reading becomes a substring of itself. We can make this change
    //  by reading the word at its second letter instead of its first.

    word = word.substr(1, word.size() - 1);


    // General Case: Read the sub-word, get its halting state
    return read_word(word, cur_state, delta);
}












// Passes a word to a DFA and then returns the halting state
//  Note this function outputs to cout (prints sequence)

int read_word_verbose(string word, int cur_state, vector<Edge> delta)
{

    // Base Case 1: If word is empty, return current state
    
    if (word.empty() == true)
    {
        return cur_state;
    }


    // Otherwise, take the first letter of the word and find the next state 

    int next_state = search_transitions(word[0], cur_state, delta);



    // Base Case 2: If the transition to the next state is undefined, return undefined state

    if (next_state == -1)
    {
        return -1;
    }



    // Otherwise, if transition is defined, the next state becomes our current state
    cur_state = next_state; 

    // Print this sequence
    cout << "\t-->\tq" << cur_state;


    // In the process of transitioning, the first letter in the word also gets consumed,
    //  and the word we are reading becomes a substring of itself. We can make this change
    //  by reading the word at its second letter instead of its first.

    word = word.substr(1, word.size() - 1);


    // General Case: Read the sub-word, get its halting state
    return read_word_verbose(word, cur_state, delta);
}




void print_rules(vector<Edge> delta)
{
    // Iterate through transition rule list
    for (Edge e: delta)
    {


    }
}










int main()
{
    // Create transition function/rules
    vector<Edge> delta_function = vector<Edge>();

    delta_function.push_back( Edge(1, '1', 1) );
    delta_function.push_back( Edge(1, '0', 2) );
    delta_function.push_back( Edge(2, '1', 2) );
    delta_function.push_back( Edge(2, '0', 1) );


    // Create a word or two to read
    vector<string> words = vector<string>();
    words.push_back("1001");
    words.push_back("1110");
    words.push_back("1010");


    // print info to user and process each word:
    for(string s: words)
    {
        cout << endl << "Current Word: " << s << endl;
        cout << "Sequence:\tq1";
        read_word_verbose(s, 1, delta_function);
        cout << endl << endl;
    }



    return 0;
}

