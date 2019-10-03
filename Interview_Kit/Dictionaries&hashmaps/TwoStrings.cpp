#include <bits/stdc++.h>

using namespace std;


// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    int k = 0;

    //going through the first sorted string
    for(int i=0; i<s1.length(); i++)
    {

        //if s1 letter is ASCII bigger than/equal to s2 letter, move on to the next s1 letter
        while(int(s1[i]) >= int(s2[k]) )
        {
            //comparing letters
            if(s2[k] == s1[i])
            {
                return "YES";
            }

            //if s1 letter is ASCII smaller than s2 letter, move on to the next s2 letter
            k++;

            //keep an eye on range
            if(k>=s2.length()) return "NO";
        }
    }

    return "NO";

}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
    }

    //fout.close();

    return 0;
}
