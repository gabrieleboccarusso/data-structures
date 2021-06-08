// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures?

// To determine if a string has unique characters we could just use
// an hash table that store every character and that when a character
// is already stored return false: time complexity: O(n) - space complexity: O(n)

// becasue we can't use other data structures the only solution
// is a nested for loop trough the string that checks if there is a similar character
// time complexity: O(1) -  space complexity: O(n*2)

#include <iostream>
#include <string>

using std:: cout;
using std::cin;
using std::string;

bool is_unique(string word);

int main()
{
    string word;

    cout << "enter string: ";
    cin >> word;

    if(!is_unique(word)) 
    {
        cout << "the word isn't unique";
    }
    else 
    {
        cout << "the word is unique";
    }

    return 0;
}

bool is_unique(string word)
{
    int i, j; // first and second loop iterators
    bool uniqueness = true;

    for (i = 0; i < word.length(); i++)
    {
        for(j = 0; j < word.length(); j++)
        {
            // of we have the same char
            if (word[i] == word[j]) 
            {
                // if it isn't at the same position
                if (i != j) 
                {
                    uniqueness= false;
                    break; // spaghetti code
                }
            }
        }
    }

    return uniqueness;
}