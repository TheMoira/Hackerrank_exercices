#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void swap(int& a, int&b)
{
    int c = a;
    a = b;
    b = c;
}

// Complete the minimumBribes function below.
/* void minimumBribes(vector<int> q) {

    int bribe_count = 0;

    for(unsigned int i=0; i < q.size(); i++)
    {
        //thanks to j we will know the original state of the queue
        int j = i+1;

        /* while(q[i] != j)
        {
            if(q[i] > j+2)
            {
                bribe_count = -1;
                break;
            }
            if(q[i-1] > q[i])
            {
                swap(q[i],q[i-1]);
                bribe_count++;
            }
            else if(i != q.size() && q[i] < q[i+1])
            {
                swap(q[i],q[i+1]);
                bribe_count++;
            }
        }
        
        if(bribe_count < 0)
        {
            break;
        } 


        if(q[i] == j && q[i+1] < j)
        {
            bribe_count++;
            cout<<"A"<<endl;
        }
        else if(q[i] != j)
        {
            if(q[i] > j+2)
            {
                bribe_count = -2;
                cout<<"D"<<endl;
                break;
            }
            else if(q[i] == j+1)
            {
                bribe_count++;
                cout<<"B"<<endl;
            }
            else if(q[i] == j+2)
            {
                bribe_count += 2;
                cout<<"C"<<endl;
            }
            else if(i < (q.size() - 1) && q[i] > q[i+1])
            {
                bribe_count++;
                cout<<"D"<<endl;
            }
        }
    }

    //if(q[q.size() - 2] > q[q.size() - 1]) bribe_count++;

    if(bribe_count < 0)
    {
        cout<<"Too chaotic"<<endl;
    }
    else
    {
        cout<<bribe_count<<endl;
    }
} */


//WORKS BUT NOT OPTIMAL ENOUGH
void minimumBribes(vector<int> q) {

    int bribe_count = 0;

    for(int i=q.size()-1; i>=0; i--)
    {
        int j = i+1;

        if(q[i] > j+2)
        {
            cout<<"Too chaotic\n";
            return;
        }

        for(int k=0; k<i; k++)
        {
            if(q[k] > q[i])
            {
                bribe_count++;
            }
        }

    }

    cout<<bribe_count<<endl;

}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
