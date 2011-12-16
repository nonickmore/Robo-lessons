//      task_2.c
//      
//      Copyright 2011 Live session user <ubuntu@ubuntu>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//      
// TODO: 1) если количество введенных элементов меньше, чем нужно - необходимо предложить продолжить ввод
//		 2) если введены одинаковые числа - выдать ошибку

#include <stdio.h>

// ----------------------- DEFINE SECTION

#define SESSION			 2	// номер встречи, на которой было выдано задание
#define TASK			 2  // номер задания, т.к. их могло быть несколько
#define VERSION			 1	// версия решения задания, которая была опубликована или доложена
//      ----------------------------------------------------------------
#define DESC1	"DESC1:count the number of inversions in a transposition\n"
#define DESC2	"DESC2:the trasposition is taken from user's keyboard input\n"
//
//#define DESC1		"DESC1:подсчитать количество инверсий в перестановке\n"
//#define DESC2		"DESC1:перестановку вводит пользователь с клавиатуры\n"
// 		----------------------------------------------------------------

#define MATRIX_LENGTH 	 9
#define ERROR			-1

// ----------------------- FUNCTION DECLARATION

int read_transposition();
int convert_to_number(unsigned char);
int count_inversions();

// ----------------------- GLOBAL VARIABLES AND CONSTANTS

unsigned char transposition[MATRIX_LENGTH] = {9,1,2,3,4,5,6,7,8};

// ----------------------- MAIN FUNCTION

int main(int argc, char **argv)
{
	extern unsigned char transposition[];
	char inversions = 0;
	int i = 0;
	
	printf("Session %d\n-->task %d\nversion %d\n", SESSION, TASK, VERSION);
	printf(DESC1);
	printf(DESC2);
	printf("\n\n");
	
	if(read_transposition() == ERROR) {
		printf("An error occured during entering numbers: possibly you are not entering numbers!\n");
		return 0;
	}
	printf("\n\n");

	// print transposition array onto the screen
	printf("Transposition: ");
	for( i = 0; i < MATRIX_LENGTH; i++ ) {
		printf("%d\t", transposition[i]);
	}
	printf("\n\n");
	
	inversions = count_inversions();
	
	// print the number of inversions
	printf("---------------------\n");
	printf("Number of inversions: %d", inversions);
	printf("\n\n");
	
	return 0;
}

// ----------------------- FUNCTIONS' DEFINITIONS

int read_transposition() {
	extern unsigned char transposition[];
	unsigned char input;
	int i = 0;
		
	printf("This part of the program requires user input\n");
	printf("Please, input below via your keyboard %d natural numbers without repetition\n", MATRIX_LENGTH);
	printf("Each number will be acquired by a single string of numbers without spaces, finishing with ENTER key\n");
	printf("Enter numbers: ");
	
	for( i = 0; i < MATRIX_LENGTH; i++) {
		input = getchar();
		
		if(convert_to_number(input) == ERROR) return ERROR;
		transposition[i] = (unsigned char)convert_to_number(input);
	}
	
	return 0;
}

// -----------------------

int convert_to_number(unsigned char input_char) {
	unsigned char return_number;
	
	return_number = input_char - '0';
	
	if( return_number > 9 ) return ERROR;
	
	return (int)return_number;
}

// -----------------------

int count_inversions() {
	extern unsigned char transposition[];
	int i,j = 0;
	char inversions = 0;
	
	// count inversions
	for( i = 0; i < MATRIX_LENGTH; i++ ) {
		for( j = i+1; j < MATRIX_LENGTH; j++) {
			if(transposition[i] > transposition[j]) inversions++;
		}
	}
	
	return inversions;
}
