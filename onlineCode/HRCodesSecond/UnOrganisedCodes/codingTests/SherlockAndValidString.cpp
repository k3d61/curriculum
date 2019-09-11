#include <bits/stdc++.h>

using namespace std;
#include <set>
// Complete the isValid function below.
string isValid(string s) {
    
    int arr[26] = {0};
    for(int i=0 ; i < s.length() ; i++ ){
        int index = s[i]-'a';
        arr[ index ] ++;
    }
    set<int> output;
    for(int i=0 ; i < 26 ;i++){
        cout << arr[i] << endl;
        output.insert( arr[i] );
    }
    output.erase(0);
    int outputSize = output.size();
    cout << "size = " << outputSize << endl;
    
    string ret = "";
    if( outputSize > 2 ){
        ret = "NO";
        cout << ret << endl;
        return ret;
    }
    int a=0, b=0;
    auto it = output.begin();
    advance(it, 0);
    int one =  *it;
    advance(it, 1);
    int two = *it;
    cout << "one = " << one << " two = " << two << endl;
    
    for(int i=0 ; i < 26 ;i++){
        if( arr[i] == one ){
            a++;
        }
        else if (arr[i] == two)
            b++;
    }
    cout << "a = " << a << " b = " << b << endl;
    if(  a != 1 && b != 1   )
        ret = "NO";
    else if( ( a != 1 || b != 1 ) && abs(one-two) < 2 )
        ret = "YES";
    else if( ( a == 1 || b == 1 ) && ( one == 1 || two == 1  ) )
        ret = "YES";
    else
        ret = "NO";

    cout << ret << endl;
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
