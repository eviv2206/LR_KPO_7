#include <iostream>
using namespace std;

// reverse function which takes the pointer to starting
// and ending character
void reverse(char* start, char* end)
{
    // loop over the word until the start meets end
    // in the middle
    for (; start < end ; start++)
    {
        char temp;
        temp = *start;
        *start = *end;
        *end = temp;
        // move to the previous letter
        end--;
    }

}

int main() {
    string str;
    getline(cin, str);
    // pointers to starting characters of the string
    char* ind = &str[0];
    char* new_word = &str[0];

    // while there exists a character
    while(*ind)
    {
        // if a space is found, call reverse on the word
        // before the space
        if (*ind == ' ')
        {
            reverse(new_word, ind-1);

            // set the marking of a new word i.e right after
            // the space
            new_word = ind+1;
        }
        ind++;
    }

    // reverse the letters in the last word
    // the last word is not catered in the loop above
    reverse(new_word,--ind);

    // reverse the whole string
    reverse(&str[0], ind);


    cout << str;
    return 0;
}