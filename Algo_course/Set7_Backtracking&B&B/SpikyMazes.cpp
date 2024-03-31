#include <iostream>

using namespace std;


void map_traverse(char** map, int i, int j, int &s, int &is_possible, int n, int m)
{
    if (is_possible) { return; }
    if (map[i][j] == 'x' && s >= 0)
    {
        is_possible = 1;
        return;
    }

    char original_space = map[i][j];
    map[i][j] = '#';

    if (original_space == 's')
    {
        s -= 2;
    }

    if (s >= 0){
        if (i - 1 >= 0 && map[i - 1][j] != '#') {
            map_traverse(map, i-1, j, s, is_possible, n, m);
        }
        if (i + 1 < n && map[i + 1][j] != '#') {
            map_traverse(map, i+1, j, s, is_possible, n, m);
        }
        if (j - 1 >= 0 && map[i][j - 1] != '#') {
            map_traverse(map, i, j-1, s, is_possible, n, m);
        }
        if (j + 1 < m && map[i][j + 1] != '#') {
            map_traverse(map, i, j+1, s, is_possible, n, m);
        }
    }

    if (original_space == 's')
    {
        s += 2;
    }

    map[i][j] = original_space;
}


int main()
{
    int n, m, s;
    int start_i, start_j;
    int is_possible = 0;

    cin >> n >> m >> s;

    char** map = (char**) malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++)
    {
        map[i] = (char*) malloc(m * sizeof(char));

        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == '@')
            {
                start_i = i;
                start_j = j;
            }
        }
    }

    map_traverse(map, start_i, start_j, s, is_possible, n, m);

    if (is_possible)
    {
        cout << "SUCCESS";
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
