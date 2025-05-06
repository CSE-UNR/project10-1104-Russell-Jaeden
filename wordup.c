//Jaeden Russell
//CS 135
//Project 10

#include <stdio.h>

#define ROWS 6
#define COLS 5
//declaring functions
	void startMessage();
	void readWord(char word[COLS + 1]);
	void usersInput(char wordupArray[ROWS][COLS + 1], char word[COLS + 1], int *won);
	void compareWords(char guess[COLS + 1], char word[COLS + 1]);
	void endMessage(int won);
	void errorMessages(char guess[COLS + 1]);

	int count = 1;

	int main() {
	
    	char wordupArray[ROWS][COLS + 1]; 
    	char word[COLS + 1]; 
    	int won = 0;
//calling functions
    		readWord(word);
    		usersInput(wordupArray, word, &won);
    		endMessage(won);

    return 0;
}
//beginning prompt
	void startMessage() {
	
    	printf("GUESS %d! Enter your guess: ", count);
    	count++;
}
//reading the word from the txt file
	void readWord(char word[COLS + 1]) {
	
    	FILE *file = fopen("mystery.txt", "r");
    	
    	if (file == NULL) {
        printf("Error opening file.\n");
        
        return;
    }

   	 fscanf(file, "%5s", word); 
   	 fclose(file);
}
//compares the words guessed by the user to the starting word
	void usersInput(char wordupArray[ROWS][COLS + 1], char word[COLS + 1], int *won) {
    	for (int i = 0; i < ROWS; i++) {
    	
        	char guess[COLS + 1];
        	
       	 	startMessage();
       	 	
        	scanf("%5s", guess);

        
        int valid = 1;
        	for (int j = 0; j < COLS; j++) {
           	 if (guess[j] == '\0') {
                	valid = 0;
                	break;
            	}
         }
        
        if (valid == 0 || guess[COLS] != '\0') {
        
            errorMessages(guess);
            i--;
            count--;
            
            continue;
        }

       
        for (int j = 0; j < COLS + 1; j++) {
            wordupArray[i][j] = guess[j];
        }

        printf("================================\n");
        
        for (int r = 0; r <= i; r++) {
            printf("%s\n", wordupArray[r]);
            compareWords(wordupArray[r], word);
        }

        int correct = 1;
        for (int j = 0; j < COLS; j++) {
            if (guess[j] != word[j]) {
                correct = 0;
                break;
            }
        }

        if (correct) {
            
            printf("\n        ");
            for (int j = 0; j < COLS; j++) {
                char ch = guess[j];
                if (ch >= 'a' && ch <= 'z') {
                    ch -= 32; 
                }
                printf("%c", ch);
            }
            printf("\n    You won in %d guesses!\n        Nice!\n", i + 1);
            *won = 1;
            break;
        }
    }
}
//adds ^ to the letters correct
	void compareWords(char guess[COLS + 1], char word[COLS + 1]) {
    	
    	for (int i = 0; i < COLS; i++) {
    	
        if (guess[i] == word[i]) {
            printf("^");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}
// end messages
	void endMessage(int won) {
	
    	if (!won) {
    	
        printf("You ran out of guesses. Better luck next time!\n");
    }
}

	void errorMessages(char guess[COLS + 1]) {
	
   	 printf("Invalid guess: must be exactly 5 letters.\n");
}

