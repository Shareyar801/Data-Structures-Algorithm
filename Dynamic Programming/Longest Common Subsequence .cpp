//video: https://www.youtube.com/watch?v=p09b1IzQa_A&ab_channel=AnujBhaiya
//viusalization:  https://www.cs.usfca.edu/~galles/visualization/DPLCS.html
//thoery + source code: https://www.programiz.com/dsa/longest-common-subsequence#:~:text=The%20longest%20common%20subsequence%20(LCS,positions%20within%20the%20original%20sequences.

#include <iostream>
#include <string>
using namespace std;

const int max_size = 50;

void LCS_Algo(char str1[], char str2[], int len1, int len2)
{
    //making a table for lcs solution.
    int LCS[max_size][max_size];
    
    //now using bottom-up approach by help of matrix.
    for (size_t i = 0; i <= len1; i++)
    {
        for (size_t j = 0; j <= len2; j++)
        {
            //now there are 2 rules.
            
            if (i == 0 || j == 0)
                //making entire row of i=0 and j=0.
                LCS[i][j] = 0;

            else if (str1[i - 1] == str2[j - 1])
                //rule 1: if row == column then adding 1 in conner value.
                LCS[i][j] = LCS[i - 1][j - 1] + 1;

            else
                //rule 2: if they dont then check which value is max in its neighbourhood,
                //and then putting that max value in i j position.
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j-1]);
        }
    }
    //now solution has been created.

    //printing the how long is common subsequence.
    cout << "\nLength of common subsequence = " << LCS[len1][len2];

    //now going back into solution to find common strings.
    int len = LCS[len1][len2];
    //making an array to store substring.
    char Substr_arr[max_size];
    Substr_arr[len] = '\0';
    // '\0' = NULL

    int i = len1, j = len2;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            //if both string are matched from both strings then we will put that value into sub string array.
            //thats why the order of both strings should be alphabetical.
            Substr_arr[len - 1] = str1[i - 1];
            i--;
            j--;
            len--;
        }

        //or otherwise if left value is greater than top value then we will move towards left.
        else if (LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        
        //or otherwise if left value is greater less top value then we will move towards up.
        else
            j--;
    }

    //printing details:
    cout << "\nSubstring: " << Substr_arr;
}

int main() 
{
    char S1[] = "adsjpilbmcernjs";
    char S2[] = "mahuhuacz";

    int len_S1 = strlen(S1);
    int len_S2 = strlen(S2);

    cout << "LONGEST COMMON SUBSEQUENCE:\n";
    cout << "\nstring 01: " << S1;
    cout << "\nstring 02: " << S2;
    LCS_Algo(S1, S2, len_S1, len_S2);
    cout << endl;
}
