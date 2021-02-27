#include <stdio.h>
#define WIN_X 'X'
#define WIN_O 'O'
#define GO_ON 'G'
#define TIE 'T'
#define TRUE 1
#define FALSE 0

typedef char array_of_3_chars[3];


// Function Prototypes
void setPlayNumberToBoard(array_of_3_chars*, int, char);
int checkPlayNumberForAvailability(array_of_3_chars*, int);
void startGame(array_of_3_chars*, char);
void askForPlay(array_of_3_chars*, char);
void showBoard(array_of_3_chars*);
char checkWin(array_of_3_chars*);
char checkHorizontal(array_of_3_chars*);
char checkVertical(array_of_3_chars*);
char checkFirstDiagonal(array_of_3_chars*);
char checkSecondDiagonal(array_of_3_chars*);
char checkTie(array_of_3_chars*);


void showAmazingTitle() {
printf("    ___          ___           ___           ___                   _____          ___                    ___                       ___           ___           ___\\\n");     
printf("   /  /\\        /  /\\         /  /\\         /  /\\                 /  /::\\        /  /\\                  /  /\\        ___          /__/\\         /  /\\         /  /\\\n");    
printf("  /  /:/       /  /::\\       /  /:/_       /  /::\\               /  /:/\\:\\      /  /::\\                /  /:/_      /  /\\        |  |::\\       /  /::\\       /  /::\\\n");   
printf(" /__/::\\      /  /:/\\:\\     /  /:/ /\\     /  /:/\\:\\             /  /:/  \\:\\    /  /:/\\:\\              /  /:/ /\\    /  /:/        |  |:|:\\     /  /:/\\:\\     /  /:/\\:\\\n");  
printf(" \\__\\/\\:\\    /  /:/  \\:\\   /  /:/_/::\\   /  /:/  \\:\\           /__/:/ \\__\\:|  /  /:/  \\:\\            /  /:/ /::\\  /__/::\\      __|__|:|\\:\\   /  /:/~/::\\   /  /:/  \\:\\\n"); 
printf("    \\  \\:\\  /__/:/ \\__\\:\\ /__/:/__\\/\\:\\ /__/:/ \\__\\:\\          \\  \\:\\ /  /:/ /__/:/ \\__\\:\\          /__/:/ /:/\\:\\ \\__\\/\\:\\__  /__/::::| \\:\\ /__/:/ /:/\\:\\ /__/:/ \\__\\:\\\n");
printf("     \\__\\:\\ \\  \\:\\ /  /:/ \\  \\:\\ /~~/:/ \\  \\:\\ /  /:/           \\  \\:\\  /:/  \\  \\:\\ /  /:/          \\  \\:\\/:/~/:/    \\  \\:\\/\\ \\  \\:\\~~\\__\\/ \\  \\:\\/:/__\\/ \\  \\:\\ /  /:/\n");
printf("     /  /:/  \\  \\:\\  /:/   \\  \\:\\  /:/   \\  \\:\\  /:/             \\  \\:\\/:/    \\  \\:\\  /:/            \\  \\::/ /:/      \\__\\::/  \\  \\:\\        \\  \\::/       \\  \\:\\  /:/\n"); 
printf("    /__/:/    \\  \\:\\/:/     \\  \\:\\/:/     \\  \\:\\/:/               \\  \\::/      \\  \\:\\/:/              \\__\\/ /:/       /__/:/    \\  \\:\\        \\  \\:\\        \\  \\:\\/:/\n");  
printf("    \\__\\/      \\  \\::/       \\  \\::/       \\  \\::/                 \\__\\/        \\  \\::/                 /__/:/        \\__\\/      \\  \\:\\        \\  \\:\\        \\  \\::/\n");   
printf("                \\__\\/         \\__\\/         \\__\\/                                \\__\\/                  \\__\\/                     \\__\\/         \\__\\/         \\__\\/\n");    








}

void showBoard(array_of_3_chars* board) {
    int n = 1;
    int i = 0;
    int j = 0;
    for (i = 0; i < 3; i++) {
        printf("+------+------+------+\n");
        for (j = 0; j < 3; j++) {
            printf("| %d  %c ",n, board[i][j]);
            n++;
        }
        printf("|\n");
    }
    printf("+------+------+------+\n");
}

char checkWin(array_of_3_chars* board) {
    char h_result = checkHorizontal(board);
    char v_result = checkVertical(board);
    char fd_result = checkFirstDiagonal(board);
    char sd_result = checkSecondDiagonal(board);
    char tie_result = checkTie(board);
    if (h_result != GO_ON)
        return h_result;
    if (v_result != GO_ON)
        return v_result;
    if (fd_result != GO_ON)
        return fd_result;
    if (sd_result != GO_ON)
        return sd_result;
    return tie_result;
}

char checkHorizontal(array_of_3_chars* board) {
    int row = 0;
    for (row = 0; row < 3; row++) {
        if ( (board[row][0] == board[row][1]) && (board[row][1] == board[row][2]) ) {
           if (board[row][0] == WIN_X)
                return WIN_X;
            else if (board[row][0] == WIN_O)
                return WIN_O;
            else
                ;
        }
    }
    return GO_ON;
}

char checkVertical(array_of_3_chars* board) {
    int col = 0;
    for (col = 0; col < 3; col++) {
        if ( (board[0][col] == board[1][col]) && (board[1][col] == board[2][col]) ) {
            if (board[0][col] == WIN_X)
                return WIN_X;
            else if (board[0][col] == WIN_O)
                return WIN_O;
            else
                ;
        }
    }
    return GO_ON;
}

char checkFirstDiagonal(array_of_3_chars* board) {
        if ( (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) ) {
           if (board[0][0] == WIN_X)
                return WIN_X;
            else if (board[0][0] == WIN_O)
                return WIN_O;
            else
                ;
        }
    return GO_ON;
}

char checkSecondDiagonal(array_of_3_chars* board) {
        if ( (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) ) {
            if (board[0][2] == WIN_X)
                return WIN_X;
            else if (board[0][2] == WIN_O)
                return WIN_O;
            else
                ;
        }
    return GO_ON;
}

char checkTie(array_of_3_chars* board) {
    int i = 0;
    int j = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return GO_ON;
            }
        }
    }
    return TIE;
}

void startGame(array_of_3_chars* board, char currentPlayer) {
    char win_condition = GO_ON;
    
    while (win_condition == GO_ON) {
        askForPlay(board,currentPlayer);
        win_condition = checkWin(board);
        if (currentPlayer == WIN_X)
            currentPlayer = WIN_O;
        else
            currentPlayer = WIN_X;
    }
    showBoard(board);
    if (win_condition == WIN_O) {
        printf("O jogador O ganhou. Parabéns!\n");
    }
    else if (win_condition == WIN_X) {
         printf("O jogador X ganhou. Parabéns!\n");
    }
    else {
        printf("O jogo empatou.\n");
    }
}

void askForPlay(array_of_3_chars* board, char currentPlayer) {
    showBoard(board);
    printf("Insira o nº do quadrado onde quer jogar: \n");
    int play = 0;
    while (TRUE) {
        scanf("%d", &play);
        if (play > 9 || play < 1) {
            printf("[!] Inseriu um nº inválido. Tente novamente.\n");
        }
        else if (!checkPlayNumberForAvailability(board,play)) {
            printf("[!] Essa posição está ocupada. Tente novamente.\n");
        }
        else {
            break;
        }
    }
    setPlayNumberToBoard(board,play,currentPlayer);
}

int checkPlayNumberForAvailability(array_of_3_chars* board, int playChoice) {
    int row = (playChoice - 1) / 3;
    int col = (playChoice - 1) % 3;
    if (board[row][col] == '-') {
        return TRUE;
    }
    return FALSE;
}

void setPlayNumberToBoard(array_of_3_chars* board, int playChoice, char player) {
    int row = (playChoice - 1) / 3;
    int col = (playChoice - 1) % 3;
    board[row][col] = player;
}

int main() {
    char board[3][3];
    int i = 0;
    int j = 0;
    for (i = 0 ; i < 3 ; i++)
        for (j=0; j<3; j++)
        board[i][j] = '-';
    char currentPlayer = 'X';
    showAmazingTitle();
    startGame(board, currentPlayer);
}