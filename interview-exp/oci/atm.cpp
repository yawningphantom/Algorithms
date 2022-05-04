#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
    100 50 20 10


    530
    400
    4 notes of 100

    350

    3 100
    1 50


    530

    5 notes of 100
    1 note of 20
    1 of note
    = { 10 , 20 , 50 , 100 }
try to use https://www.javatpoint.com/chain-of-responsibility-pattern#:~:text=A%20Chain%20of%20Responsibility%20Pattern,pattern%20in%20money%20giving%20process.
*/

class ATM
{
    vector<int> Notes;
    int minimumNote = INT32_MAX;

public:
    ATM(vector<int> A)
    {
        Notes = A;
        for (auto a : A)
        {
            minimumNote = min(a, minimumNote);
        }
    }

    void getAmountWithNotes(int amount)
    {

        if (amount % minimumNote != 0)
        {
            cout << "the amount cannot be widthdrawn, make sure to put appropriate amount" << endl;
            return;
        }

        unordered_map<int, int> M;

        for (auto note : Notes)
        {
            if (amount < note)
                continue;

            int numberOfNotes = amount / note;
            M[note] = numberOfNotes;
            amount = amount % note;
        }

        for (auto m : M)
        {
            cout << m.second << " note of " << m.first << endl;
        }
        cout << endl;
    }
};

int main()
{
    vector<int> Notes = {100, 50, 20, 10};
    ATM *atm = new ATM(Notes);
    atm->getAmountWithNotes(1885);
    // 1800 -> 100 , 80 , 50 , 20 , 10
    // atm->getAmountWithNotes(430);

    return 0;
}