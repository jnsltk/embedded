// (C) Henrik Lagrosen, János Litkei, Shiyao Xin; Group 35 (2024)
// Work package 0
// Exercise 1
// Submission code: 023513

#define ROW1 11
#define ROW2 10
#define ROW3 9
#define ROW4 8

#define COL1 7
#define COL2 6
#define COL3 5
#define COL4 4

const char keys[4][4] = {
    {'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}};

int getCol();
int getRow();
char getInputChar(int col, int row);

void setup() {
    Serial.begin(9600);

    pinMode(ROW1, OUTPUT);
    pinMode(ROW2, OUTPUT);
    pinMode(ROW3, OUTPUT);
    pinMode(ROW4, OUTPUT);

    pinMode(COL1, INPUT);
    pinMode(COL2, INPUT);
    pinMode(COL3, INPUT);
    pinMode(COL4, INPUT);
}

void loop() {
    switch (getCol()) {
        case COL1: {
            Serial.println(getInputChar(COL1, getRow()));
            delay(1000);
            break;
        }
        case COL2: {
            Serial.println(getInputChar(COL2, getRow()));
            delay(1000);
            break;
        }
        case COL3: {
            Serial.println(getInputChar(COL3, getRow()));
            delay(1000);
            break;
        }
        case COL4: {
            Serial.println(getInputChar(COL4, getRow()));
            delay(1000);
            break;
        }
    }
}

int getCol() {
    if (digitalRead(COL1) == 0)
        return COL1;
    if (digitalRead(COL2) == 0)
        return COL2;
    if (digitalRead(COL3) == 0)
        return COL3;
    if (digitalRead(COL4) == 0)
        return COL4;
}

int getRow() {
    char rows[4] = {ROW1, ROW2, ROW3, ROW4};
    char row = -1;
    for (char i = 0; i < 4; i++) {
        pinMode(rows[i], INPUT);
        row = digitalRead(rows[i]);
        pinMode(rows[i], OUTPUT);
        if (row == 1)
            return rows[i];
    }
    return 0;
}

char getInputChar(int col, int row) {
    int c;
    int r;

    c = map(col, COL1, COL4, 0, 3);
    r = map(row, ROW1, ROW4, 0, 3);

    return keys[r][c];
}
