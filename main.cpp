#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int size = 10;
 int mines = 10;

int board[10][10] ;
bool revealed[10][10] ;

void putting() {
    int minesplace = 0;
    while (minesplace < mines)
        {
        int x = rand() % 10;
        int y = rand() % 10;
        if (board[x][y] != -1) {
    board[x][y] = -1;
    minesplace++;
        }
    }

    int dx, dy,nx,ny;
    for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
     if (board[i][j] != -1) {
        int countt = 0;
        for (dx = -1; dx <= 1; dx++) {
                     for ( dy = -1; dy <= 1; dy++) {
                         nx = i + dx;
                         ny = j + dy;
                        if (nx >= 0 && nx < size && ny >= 0 && ny < size && board[nx][ny] == -1) {
                            countt++;
            }
                }
                }
                board[i][j] = countt;
                    }
    }
    }
}

void printboard(bool revealmines = false) {
    cout << "  ";
    for (int i = 0; i < size; i++)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < size; i++) {
        cout << i << " ";
        for (int j = 0; j < size; j++) {
            if (revealed[i][j]||(board[i][j] == -1 && revealmines)){


                cout << (board[i][j] == -1?"*" : to_string(board[i][j])) << " ";
            }else{

                cout << ". ";}

}
 cout<<endl;
    }
}

void reveal(int x, int y) {
    if (x < 0 || x >= size || y < 0 || y >= size || revealed[x][y])
        return;

    revealed[x][y] = true;

    if (board[x][y] == 0) {
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy)
                {
                int nx = x + dx;
                int ny = y + dy;
                reveal(nx, ny);
            }
}
}
}

int main() {
    srand(time(0));
    putting();

    while (true) {
        printboard();
        int x, y;
        cout << "give two numbers for row and column : ";
        cin >> x >> y;

        if (x < 0 || x >= size || y < 0 || y >= size) {
            cout << "wrong input.\n";
            break;
    }
        if (board[x][y] == -1) {
            cout << "you hit a mine!\n";
            printboard(true);
            break;
        } else {
            reveal(x, y);
    }

        bool reveale = true;
        for (int i = 0; i < size;i++) {
            for (int j = 0; j < size; j++) {
                if (!revealed[i][j] && board[i][j] != -1) {
                    reveale = false;
                    break;
        }
}
            if (!reveale)
                break;
}

        if (reveale) {
            cout << "you won!\n";
            break;
}
    }

    return 0;
}
