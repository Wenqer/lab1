#include <stdio.h>

#include <iostream>
#include <cstdlib>
#include <string>

long int  a, a1, b, b1, c, c1, left_С, right_С, left_A, right_A, d;
const long int k = 21;

 
using namespace std;
	int err_la, err;// Ошибка в левой части выражения в асcемблере

int main()
  {
	// Сбросить переменне
	a=0; b=0; c=0; a1=0; b1=0; c1=0;
    // Вводим данные
	printf("\n\t Vipolnit proverku togdestva 2(-ab-ac+bc)=(a-b-c)2-a2-b2-c2,");
    printf("\n\tgde a=a/23");
	printf("\n\tgde b=b/24");
	printf("\n\tgde c=c/25");
    printf("\nVvedite chisla a,b,c : ");
    //scanf("%d%",&a,&b,&c);
	cin>> a;
	cin>> b;
	cin>> c;
//=============================== C ==================================

// Разделить исходные переменные
    a1 = a/ (k+2);
	b1 = b/ (k+3); 
	c1 = c/ (k+4);
// Сбросить признак ошибки на С
    err = 0;
// Вычислить выражение
    left_С = 2*(-a1*b1-a1*c1+b1*c1);
    right_С = (a1-b1-c1)*(a1-b1-c1)-a1*a1-b1*b1-c1*c1;
// ========================== Assembler================================ 	2(-ab-ac+bc)= (a-b-c)2-a2-b2-c2
  __asm {
	 
	  // 2(-ab-ac+bc) - Right Chast
	 mov eax, a1 // a
     mov ebx, b1 
	 mov ecx, c1
	 mov edx, a1 // a
	 imul eax, ebx // a*b
	 imul eax, -1 // -a*b
	 imul ecx, a1 // a*c
	 imul ebx, c1 // b*c
	 sub eax, ecx
	 add eax, ebx // (-ab-ac+bc)
	 imul eax, 2
	 mov right_A, eax
	 
	 // (a-b-c)2-a2-b2-c2 - Left Chast
	 mov eax, a1 // a
     mov ebx, b1 
	 mov ecx, c1
	 sub eax, ebx // a-b
	 sub eax, ecx // a-b-c
	 imul eax, eax // (a-b-c)2
	 imul edx, edx // a2
	 imul ebx, ebx // b2
	 imul ecx, ecx // c2
	 sub eax, edx
	 sub eax, ebx
	 sub eax, ecx
	 mov left_A, eax


  }
	 // В будущем проверка на переполнение!

	// Вывод на С
	printf("Right_C= %ld\n", right_С);
	printf("Left_C= %ld\n", left_С);
	// Вывод на Ассемблере 
	printf("Right_A= %ld\n", right_A);
	printf("Left_A= %ld\n", left_A);
  
	printf(" a1= %d,%i\n", a1);
	printf(" b1= %d,%i\n", b1);
	printf(" c1= %d,%i\n",  c1);
	printf(" k= %d,%i\n",  k);
	system("PAUSE");
}

	