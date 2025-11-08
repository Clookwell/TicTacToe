#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define X 'X'
#define O 'O'

char empty = ' ';
char arr[3][3];

//ask: play or quit
//while(no win or no tie) {
//	dislpay()
//	ask: where to write
//	check if some one win OR all fields are writed in
//	swap queue for X and O
//}

void init(char array[3][3]) {
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) 
			array[i][j] = empty;
}

int ask_to_start() {
	char answer;

	while(1) {
		printf("Play Tic Tac Toe (y for yes, n for no): ");
		scanf("%c", &answer);

		int i;
		while((i = getchar()) != '\n' && i != EOF);

		if(!(tolower(answer) == 'y' || tolower(answer) == 'n')) {
			puts("\nwrong enter\n");
			continue;
		} 
		else if(tolower(answer) == 'y') {
			return 0;
		}
		else if(tolower(answer) == 'n') {
			exit(EXIT_SUCCESS);
		}
	}
}

void turn_to_write(char symbol) {
	int pos;

	while(1) {

		puts("Write position from 1 to 9\n");
		scanf("%d", &pos);

		int c;
		while((c = getchar()) != '\n' && c != EOF);

		if(pos < 1 || pos > 9) {
			puts("Wrong position\n");
			continue;
		}
	
		

		switch(pos) {
		case 1:
			if(arr[0][0] != empty) {
				puts("This position is not empty");
				continue;
			}
			arr[0][0] = symbol;
			return;
		case 2:
			if(arr[0][1] != empty) {
				puts("This position is not empty");
				continue;
			}
			arr[0][1] = symbol;
			return;
		case 3:
			if(arr[0][2] != empty) {
				puts("This position is not empty");
				continue;
			}
			arr[0][2] = symbol;
			return;
		case 4:
			if(arr[1][0] != empty) {
				puts("This position is not empty");
				continue;
			}
			arr[1][0] = symbol;
			return;
		case 5:
			if(arr[1][1] != empty) {
				puts("This position is not empty");
				continue;
			}
			arr[1][1] = symbol;
			return;
		case 6:
			if(arr[1][2] != empty) {
				puts("This position is not empty");
				continue;
			}
			arr[1][2] = symbol;
			return;
		case 7:
			if(arr[2][0] != empty) {
				puts("This position is not empty");
				continue;
			}
			arr[2][0] = symbol;
			return;
		case 8:
			if(arr[2][1] != empty) {
				puts("This position is not empty");
				continue;
			}
			arr[2][1] = symbol;
			return;
		case 9:
			if(arr[2][2] != empty) {
				puts("This position is not empty");
				continue;
			}
			arr[2][2] = symbol;
			return;
		}
	}
}

void display() {
	system("clear");
	printf("%c |%c |%c\n", arr[0][0], arr[0][1], arr[0][2]);
	printf("--------\n");
	printf("%c |%c |%c\n", arr[1][0], arr[1][1], arr[1][2]);
	printf("--------\n");
	printf("%c |%c |%c\n", arr[2][0], arr[2][1], arr[2][2]);
}

int check_for_win() {
	int result = 2;

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			if(arr[i][j] == empty) result = 0;

	if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][2] != ' ') result = 1;
	else if(arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[2][0] != ' ') result = 1;
	else if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] != ' ') result = 1;
	else if(arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][2] != ' ') result = 1;
	else if(arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][2] != ' ') result = 1;
	else if(arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[2][1] != ' ') result = 1;
	else if(arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[2][2] != ' ') result = 1;
	else if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] != ' ') result = 1;

	return result;	

}

int main(void) {
	init(arr);

	char player = X;

	ask_to_start();
	while(1) {
		display();
		printf("turn of Player %c\n", player);
		turn_to_write(player);
		if(check_for_win() == 1) {
			display();
			printf("Player %c Won!\n", player);
			break;
		}
		else if(check_for_win() == 2) {
			display();
			printf("Tie!\n");
			break;
		}
		if(player == X) player = O;
		else if(player == O) player = X;
	}

	return 0;
}
