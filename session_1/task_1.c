//      task_1.c
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
//      ----------------------------------------------------------------
//		Session 1 
//		Task 1		- count the number of iversions in a transposition
//		Встреча 1 
//		Задача 1 	- подсчет инверсий в перестановке


#include <stdio.h>

int main(int argc, char **argv)
{
	#define MATRIX_LENGTH 9
	unsigned char transposition[MATRIX_LENGTH] = {9,1,2,3,4,5,6,7,8};
	int i,j = 0;
	char inversions = 0;
	
	printf("Session 1: task 1 - version 1\n");
	printf("Description: count the number of inversions in a transposition\n");
	
	// print array onto the screen
	for( i = 0; i < MATRIX_LENGTH; i++ ) {
		printf("%d\t", transposition[i]);
	}
	printf("\n\n");
	
	// count inversions
	for( i = 0; i < MATRIX_LENGTH; i++ ) {
		for( j = i+1; j < MATRIX_LENGTH; j++) {
			if(transposition[i] > transposition[j]) inversions++;
		}
	}
	
	// print the number of inversions
	printf("Number of inversions: %d", inversions);
	
	return 0;
}
