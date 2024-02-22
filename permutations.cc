#pragma once

#include <vector>
#include <string>

using namespace std;

/**
 @param r the list of permutations
 @param fixed the substr that no longer needs to be permuted
 @param remaining the substr that still needs to be permuted
*/
void recursive(vector<string> & r, string fixed, string remaining)
{
    //no char left to permute, add the current permutation to the list
    if (remaining.empty())
    {
        r.push_back(fixed);
    }
    else
    {
        for (int i = 0; i < remaining.size(); i++)
        {
            /*
            recursively call this function again, except this time by 'extracting' the current char
             from the remaining string, and adding it onto the fixed string
            what causes the 'swapping' effect is the fact that
             i is being incremented as you exit recursive calls
             so  char in the middle of the str
             have a chance to get added onto the empty str
             but the rest of the string gets reconstructed in order
            */
            recursive(r, fixed + remaining.at(i), remaining.substr(0, i) + remaining.substr(i + 1, remaining.size()));
        }
        
    }
}

vector<string> permutations(string const & s)
{
    vector<string> results;
    recursive(results, "", s);
    return results;
}
