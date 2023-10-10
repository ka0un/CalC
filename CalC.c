#include <stdio.h>
#include <string.h>

int toInt(char cha);
char toChar (int in);
void printWelcome();

char devideTwoChars(char one, char two);
char multiplyTwoChars(char one, char two);
char addTwoChars(char one, char two);
char subTwoChars(char one, char two);

void doDevision(char input[]);
void doMultiplication(char input[]);
void doAddition(char input[]);
void doSubstraction(char input[]);

void deleteElements(char arr[], int index, int numToDelete);
int isOperatorExisit(char input[], char op);

void performArthmaticOperations(char input[]);

int main(){
	
	char input[100];
	
	printWelcome();
	
	while (!(input[0] == 'x' || input[0] == 'X')){
		printf("\n> ");
		scanf("%s", input);
		performArthmaticOperations(input);
		printf("= %s\n", input);	
	}
	
	return 0;
}

//arithmatic operations

void performArthmaticOperations(char input[]){
	
	while(isOperatorExisit(input, '/')){
		doDevision(input);
	}
	
	while(isOperatorExisit(input, '*')){
		doMultiplication(input);
	}
	
	while(isOperatorExisit(input, '+')){
		doAddition(input);
	}
	
	while(isOperatorExisit(input, '-')){
		doSubstraction(input);
	}
	
}


void doDevision(char input[]){
	int i;
	for(i = 0; i < strlen(input); i++){
		if(input[i] == '/'){
			input[i-1] = devideTwoChars(input[i-1],input[i+1]);
			deleteElements(input, i, 2);
		}
	}
}

void doMultiplication(char input[]){
	int i;
	for(i = 0; i < strlen(input); i++){
		if(input[i] == '*'){
			input[i-1] = multiplyTwoChars(input[i-1],input[i+1]);
			deleteElements(input, i, 2);
		}
	}
}

void doAddition(char input[]){
	int i;
	for(i = 0; i < strlen(input); i++){
		if(input[i] == '+'){
			input[i-1] = addTwoChars(input[i-1],input[i+1]);
			deleteElements(input, i, 2);
		}
	}
}

void doSubstraction(char input[]){
	int i;
	for(i = 0; i < strlen(input); i++){
		if(input[i] == '-'){
			input[i-1] = subTwoChars(input[i-1],input[i+1]);
			deleteElements(input, i, 2);
		}
	}
}

// char arthithmatic simplification

char  devideTwoChars(char one, char two){
	return toChar(toInt(one) / toInt(two));
}

char  multiplyTwoChars(char one, char two){
	return toChar(toInt(one) * toInt(two));
}

char  addTwoChars(char one, char two){
	return toChar(toInt(one) + toInt(two));
}

char  subTwoChars(char one, char two){
	return toChar(toInt(one) - toInt(two));
}

// char int converting

int toInt(char cha){
	return (int) (cha - 48);
}

char toChar (int in){
	return (char) (in + 48);
}

// Utils

void deleteElements(char arr[], int index, int numToDelete) {
	
	
    if (index < 0 || index >= 100 || numToDelete <= 0) {
        printf("Invalid index or number of elements to delete.\n");
        return;
    }

    int i;
    for (i = index; i < 100 - numToDelete; ++i) {
        arr[i] = arr[i + numToDelete];
    }

}

int isOperatorExisit(char input[], char op){
	int i;
	for(i = 0; i < strlen(input); i++){
		if(input[i] == op){
			return 1;
		}
	}
	
	return 0;
}

void printWelcome(){
	printf("=================================\n");
	printf("\n");
	printf("CalC V 1.0.0 \n");
	printf("by Kasun Hapangama \n");
	printf("\n");
	printf("=================================\n");
	printf("\n");
	printf("[x] White Spaces Arent Supported!\n");
	printf("[x] Multiple Digit numbers not supported yet!\n");
	printf("[x] Negative Values arent Supported Yet!\n");
	printf("[x] Multiple Operators are Supported!\n");
	printf("[x] Supported Operators [+][-][/][*]\n");
	printf("[x] Enter just X to exit\n");
	printf("\n");
	printf("Example : \n");
	printf("Input : 4/2+1\n");
	printf("Output : 3\n");
    printf("\n");
	printf("=================================");
}