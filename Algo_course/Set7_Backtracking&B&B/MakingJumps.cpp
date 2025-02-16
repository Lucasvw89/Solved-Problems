#include <iostream>

using namespace std;


void horse_traverse(int board[10][10], int i, int j, int &current_result, int &result)
{
    if (i - 1 >= 0 && j - 2 >= 0 && board[i - 1][j - 2]){
        board[i - 1][j - 2] = 0;
        current_result -= 1;

        if (current_result < result) { result = current_result; }

        horse_traverse(board, i - 1, j - 2, current_result, result);
        board[i - 1][j - 2] = 1;
        current_result += 1;
    }
    if (i - 2 >= 0 && j - 1 >= 0 && board[i - 2][j - 1]){
        board[i - 2][j - 1] = 0;
        current_result -= 1;

        if (current_result < result) { result = current_result; }

        horse_traverse(board, i - 2, j - 1, current_result, result);
        board[i - 2][j - 1] = 1;
        current_result += 1;
    }
    if (i - 2 >= 0 && j + 1 <= 9 && board[i - 2][j + 1]){
        board[i - 2][j + 1] = 0;
        current_result -= 1;

        if (current_result < result) { result = current_result; }

        horse_traverse(board, i - 2, j + 1, current_result, result);
        board[i - 2][j + 1] = 1;
        current_result += 1;
    }
    if (i - 1 >= 0 && j + 2 <= 9 && board[i - 1][j + 2]){
        board[i - 1][j + 2] = 0;
        current_result -= 1;

        if (current_result < result) { result = current_result; }

        horse_traverse(board, i - 1, j + 2, current_result, result);
        board[i - 1][j + 2] = 1;
        current_result += 1;
    }
    if (i + 1 <= 9 && j - 2 >= 0 && board[i + 1][j - 2]){
        board[i + 1][j - 2] = 0;
        current_result -= 1;

        if (current_result < result) { result = current_result; }

        horse_traverse(board, i + 1, j - 2, current_result, result);
        board[i + 1][j - 2] = 1;
        current_result += 1;
    }
    if (i + 2 <= 9 && j - 1 >= 0 && board[i + 2][j - 1]){
        board[i + 2][j - 1] = 0;
        current_result -= 1;

        if (current_result < result) { result = current_result; }

        horse_traverse(board, i + 2, j - 1, current_result, result);
        board[i + 2][j - 1] = 1;
        current_result += 1;
    }
    if (i + 2 <= 9 && j + 1 <= 9 && board[i + 2][j + 1]){
        board[i + 2][j + 1] = 0;
        current_result -= 1;

        if (current_result < result) { result = current_result; }

        horse_traverse(board, i + 2, j + 1, current_result, result);
        board[i + 2][j + 1] = 1;
        current_result += 1;
    }
    if (i + 1 <= 9 && j + 2 <= 9 && board[i + 1][j + 2]){
        board[i + 1][j + 2] = 0;
        current_result -= 1;

        if (current_result < result) { result = current_result; }

        horse_traverse(board, i + 1, j + 2, current_result, result);
        board[i + 1][j + 2] = 1;
        current_result += 1;
    }
}


int main()
{
    int N, X, Y;
    int count = 1;
    int total_squares = 0;

    while (1)
    {
        cin >> N;
        if (N == 0) { break; }

        int board[10][10] = {0};

        for (int i = 0; i < N; i++)
        {
            cin >> X >> Y;
            total_squares += Y;
            for (int j = X; j < X + Y; j++)
            {
                board[i][j] = 1;
            }
        }

        // agoritmo vai aqui
        int result = total_squares - 1;
        int current_result = total_squares - 1;
        board[0][0] = 0;
        horse_traverse(board, 0, 0, current_result, result);

        // resultado
        if (result != 1){
            cout << "Case " << count << ", " << result << " squares can not be reached." << endl;
        } else {
            cout << "Case " << count << ", " << result << " square can not be reached." << endl;
        }
        total_squares = 0;
        count += 1;
    }

    return 0;
}
