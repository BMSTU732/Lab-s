// ConsoleApplication28.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h" 
#include "targetver.h"
#include <stdio.h> 
#include <tchar.h>
#include <stdlib.h> 
#include <string.h>

int main (void) 
{ int s1 = 0; 
char file_name1[255];
FILE *file1;
printf("File1 name: "); 
fgets(file_name1, 255, stdin); 
*strchr(file_name1, '\n') = 0; 
file1 = fopen(file_name1, "r"); while (! feof(file1)) 
{ if (fgetc(file1) == '\n') s1++; } s1++;
fclose(file1);
int s2 = 0; 
char file_name2[255]; 
FILE *file2; 
printf("File_2 name: "); 
fgets(file_name2, 255, stdin); 
*strchr(file_name2, '\n') = 0; 
file2 = fopen(file_name2, "r"); 
while (! feof(file2)) 
{ if (fgetc(file2) == '\n') s2++; } s2++; 
fclose(file2); 
printf("In %s %d lines.\n",file_name1, s1-1); 
printf("In %s %d lines.\n",file_name2, s2-1); 
printf("\n"); printf("DIFFERENCES:\n"); 
int l1; l1 = s1 - 2;
int l2; l2 = s2-2; 
FILE *pF1; 
fopen_s(&pF1, file_name1, "r"); 
char **a = new char*[s1]; 
for (int i = 0; i < s1; i++) { a[i] = new char[128]; } 
for (int i = 0; i < s1; i++) fgets (a[i], 128, pF1); 
fclose(pF1); 
FILE *pF2; fopen_s(&pF2, file_name2, "r"); 
char **b = new char*[s2]; 
for (int i = 0; i < s2; i++) { b[i] = new char[128]; } 
for (int i = 0; i < s2; i++) fgets (b[i], 128, pF2); 
fclose(pF2); 
for (int i = 0; i <= l1; i++) 
{ int flag=0; for (int j = 0; j <= (l2); j++)
{ if ((strcmp(a[i], b[j]))==0) { flag = 1; break; } } 
if (flag==0) printf("\n%s: line %d %s",file_name1, i+1, a[i]); } 
for (int i = 0; i <= l2; i++) 
{ int flag=0; for (int j = 0; j <= (l1); j++) 
{ if ((strcmp(b[i], a[j]))==0) { flag = 1; break; } } 
if (flag==0) printf("\n%s: line %d %s",file_name2, i+1, b[i]); } 
system("pause"); 
return 0; }
