#pragma once

#ifndef BOARD_H
#define BOARD_H


#define NO_STONES 0
#define P1 1 // black player
#define P2 2 // white player

#define BOARD_DEFAULT_SIZE 13
#define BOARD_OFFSET_X 50
#define BOARD_OFFSET_Y 2

#define BORDER_COLOR YELLOW
#define EMPTY_FIELD_COLOR LIGHTGRAY

// ASCII codes
#define EMPTY_FIELD 126
#define STONE 254

#define BORDER_TOP_LEFT_CORNER 218
#define BORDER_TOP 196
#define BORDER_TOP_RIGHT_CORNER 191

#define BORDER_LEFT 179
#define BORDER_RIGHT 179

#define BORDER_BOTTOM_LEFT_CORNER 192
#define BORDER_BOTTOM 196
#define BORDER_BOTTOM_RIGHT_CORNER 217

// Keys codes
#define ARROW_UP 0x48
#define ARROW_LEFT 0x4b
#define ARROW_RIGHT 0x4d
#define ARROW_DOWN 0x50


struct go_data {
	char curr_player = P1; // P1 (black) or P2 (white)
	int** board; // dynamic array with values: NO_STONES or P1 or P2
	bool is_new_board_size = true; // flag to skip memory allocation if it isn't needed
	int board_size = BOARD_DEFAULT_SIZE;
	int board_x = 0;
	int board_y = 0;

	int cursor_x() { return board_x + BOARD_OFFSET_X; };
	int cursor_y() { return board_y + BOARD_OFFSET_Y; };

};

void newGame(struct go_data* go); // Create board and place the cursor in the center of the board

void displayBoard(struct go_data go);
void drawBorder(int board_size);

void displayCursor(struct go_data go);
void moveCursor(struct go_data* go);
void centerCursor(struct go_data* go);

void putStone(struct go_data* go);

int coutLiberties(struct go_data go);

bool hasLiberty(struct go_data go, int x_shift, int y_shift);
bool isInBoard(struct go_data go, int x_shift, int y_shift);
bool isLegalMove(struct go_data go);

#endif