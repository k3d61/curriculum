#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    long long T;
    cin >> T;
    for(long long i = 0; i < T; ++i)
    {
        int P;
        long long Q, X_east[100001], X_west[100001], Y_north[100001], Y_south[100001];
        cin >> P >> Q;
        for(long long j = 0; j < Q; ++j)
        {
            X_east[j] = 0;
            X_west[j] = 0;
            Y_north[j] = 0;
            Y_south[j] = 0;
        }

        long long x, y;
        char dir;
        for(long long j = 0; j < P; ++j)
        {
            cin >> x >> y >> dir;
            switch (dir)
            {
                case 'N':
                    Y_north[y + 1]++;
                    break;
                case 'S':
                    Y_south[y - 1]++;
                    break;  
                case 'E':
                    X_east[x + 1]++;
                    break;  
                case 'W':
                    X_west[x - 1]++;
                    break;        
            }
        }

        long long x_e = 0, x_w = 0, y_n = 0, y_s = 0;
        for(long long j = 0; j < Q; ++j)
        {
            x_e = x_e + X_east[j]; X_east[j] = x_e;
            x_w = x_w + X_west[Q - 1 - j]; X_west[Q - 1 - j] = x_w;
            y_n = y_n + Y_north[j]; Y_north[j] = y_n;
            y_s = y_s + Y_south[Q - 1 - j]; Y_south[Q - 1 - j] = y_s;
        }

        long long min_x = 0, min_x_value = X_east[0] + X_west[0], min_y = 0, min_y_value = Y_north[0] + Y_south[0];
        for(long long j = 0; j < Q; ++j)
        {
            if(X_east[j] + X_west[j] > min_x_value)
            {
                min_x = j;
                min_x_value = X_east[j] + X_west[j];
            }

            if(Y_north[j] + Y_south[j] > min_y_value)
            {
                min_y = j;
                min_y_value = Y_north[j] + Y_south[j];
            }
        }

        cout << "Case #" << i + 1 << ": " << min_x <<  " " << min_y << endl; 
    }
    return 0;
}
