#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
void is_ascii(char string[]) {
        int check = 1;
        int i = 0;
        while(string[i]!=0){
                if((string[i] & 0b11100000) == 0b11000000) { check = 0;}
                if((string[i] & 0b11110000) == 0b11100000) { check = 0;}
                if((string[i] & 0b11111000) == 0b11110000) { check = 0;}
                i++;
        }
        if(check == 1) { printf("true\n");}
        else { printf("false\n");}
        
}

void capitalize_ascii(char string[]) {
        int i = 0;
        char temp[256];
        strcpy(temp,string);
           while(temp[i]!=0){
            if((temp[i] & 0b10000000) == 0 && temp[i]>='a' && temp[i]<='z') {
                   temp[i]=temp[i]-32;
            }
                i++;
           }
          printf("%s\n",temp);
}

void utf8_strlen(char str[]) {
    int i = 0;
    int length = 0;
    while(str[i] != 0)
    {
      if((str[i] & 0b10000000) == 0) { length++;}
      if((str[i] & 0b11100000) == 0b11000000) { length++;}
      if((str[i] & 0b11110000) == 0b11100000) { length++;}
      if((str[i] & 0b11111000) == 0b11110000) { length++;}

      i++;
    }

    printf("%d\n",length);
}

void codepoint_size(char string[]) {
       int length = strlen(string);
       int i = 0;
       int size = 0;
       if(length == 0){
        printf("0");
       }
       while (string[i]!=0){
       if((string[i] & 0b10000000) == 0){ size = 1; i+=1; printf("%d ",size);}
       else if((string[i] & 0b11100000) == 0b11000000) { size = 2; i+=2; printf("%d ",size);}
       else if((string[i] & 0b11110000) == 0b11100000) { size = 3; i+=3; printf("%d ",size);}
       else if((string[i] & 0b11111000) == 0b11110000) { size = 4; i+=4; printf("%d ",size);}
       else { i++;}
       }
}

void utf8_substring(const char str[],int start, int end){ 
    int start_byte = 0;
    int end_byte = 0;
    int i = 0;
    int cp1 = 0;
    int cp2 = 0;

    while(str[i]!= 0 && cp1 < start){
          if ((str[i] & 0b10000000) == 0) { i+=1; cp1++;}
          else if ((str[i] & 0b11100000) == 0b11000000) { i+=2; cp1++;}
          else if ((str[i] & 0b11110000) == 0b11100000) { i+=3; cp1++;}
          else if ((str[i] & 0b11111000) == 0b11110000) { i+=4; cp1++;}
          else { i++;}


    }
    start_byte = i;
    cp2 = cp1;
   while(str[i]!=0 && cp2 < end){

         if ((str[i] & 0b10000000) == 0) { i+=1; cp2++;}
          else if ((str[i] & 0b11100000) == 0b11000000) { i+=2; cp2++;}
          else if ((str[i] & 0b11110000) == 0b11100000) { i+=3; cp2++;}
          else if ((str[i] & 0b11111000) == 0b11110000) { i+=4; cp2++;}
          else { i++;}
   }
   end_byte = i;

   int count = end_byte-start_byte;
   int count1 = cp2-cp1;
   char temp[count+1];
   strncpy(temp,str+start_byte,count);
   int count2 = strlen(temp);
   if(count2 > count1){
           temp[count] = 0;
   }
   temp[count+1] = 0;
   printf("%s",temp);
   printf("\n");
}

void codepoint_value(char string[]) {
        int byte_index = 0;
        int result = 0;
     while(string[byte_index]!=0){
     if((string[byte_index] & 0b10000000) == 0) {
        result = string[byte_index] & 0b11111111;
         printf("%d ", result);
         byte_index+=1;
        }
     else if((string[byte_index] & 0b11100000) == 0b11000000) { 
        result = ((string[byte_index] & 0b00011111) << 6) + (string[byte_index+1] & 0b00111111);
        printf("%d ", result);
        byte_index+=2;
}
     else if((string[byte_index] & 0b11110000) == 0b11100000) { 
        result = ((string[byte_index] & 0b00001111) << 12) + ((string[byte_index+1] & 0b00111111) << 6) + (string[byte_index+2] & 0b00111111);
        printf("%d ", result);
        byte_index+=3;
}
     else if((string[byte_index] & 0b11111000) == 0b11110000) 
     { 
        result = ((string[byte_index] & 0b00000111) << 18) +((string[byte_index+1] & 0b00111111) << 12) + ((string[byte_index+2] & 0b00111111) << 6) + (string[byte_index+3] & 0b00111111);
        printf("%d ", result);
        byte_index+=4;
     }
        else { byte_index++;}
     }
}

void animal_emoji(const char str[]){
        int i = 0;
        uint32_t a;
        char animal[256];

        while(str[i]!=0){

           if((str[i] & 0b10000000) == 0) {i+=1;}
           else if((str[i] & 0b11100000) == 0b11000000) {
                char b0 = str[i];
                char b1 = str[i+1];
                b0 = b0 & 0b00011111;
                b1 = b1 & 0b00111111;
                a = b0*64 + b1;
                
                if((a >= 128000 && a<= 128063) || (a >= 129408 && a<= 129454)) {
                        strncpy(animal,str+i,2);
                        animal[2] = 0;
                        printf("%s",animal);
                        i+=2;
                }else
                { 
                        i+=2;
                }
        }
           else if((str[i] & 0b11110000) == 0b11100000) {
                char b0 = str[i];
                char b1 = str[i+1];
                char b2 = str[i+2];     
                 b0 = b0 & 0b00001111;
                 b1 = b1 & 0b00111111;
                 b2 = b2 & 0b00111111;
                 a = b0*4096+b1*64+b2;
                if((a >= 128000 && a<= 128063) || (a >= 129408 && a<= 129454)) {
                        strncpy(animal,str+i,3);
                        animal[3] = 0;
                        printf("%s",animal);
                        i+=3;
                }else{
                        i+=3;
                }
        }
           else if((str[i] & 0b11111000) == 0b11110000) {
                   char b0 = str[i];
                   char b1 = str[i+1];
                   char b2 = str[i+2];
                   char b3 = str[i+3];
                   b0 = b0 & 0b00000111;
                   b1 = b1 & 0b00111111;
                   b2 = b2 & 0b00111111;
                   b3 = b3 & 0b00111111;
                   a  = b0*262144+b1*4096+b2*64+b3;
                if((a >= 128000 && a<= 128063) || (a >= 129408 && a<= 129454)) {
                        strncpy(animal,str+i,4);
                        animal[4] = 0;
                        printf("%s",animal);
                        i+=4;
                }else{
                        i+=4;
                }
        }
        }
}

int main() {
    char input[256];
    if(isatty(fileno(stdin))){
	printf("Enter a UTF-8 encoded string: ");
	fflush(stdout);
    }else {
	    printf("Enter a UTF-8 encoded string: \n");
	  }
    if (!fgets(input, 256, stdin)) return 1;
    input[strcspn(input, "\r\n")] = 0;
    printf("Valid ASCII: ");
    is_ascii(input);
    printf("Uppercased ASCII: ");
    capitalize_ascii(input);
    int result = strlen(input);
    printf("Length in bytes: %d\n", result);
    printf("Number of code points: ");
    utf8_strlen(input);
    printf("Bytes per code point: ");
    codepoint_size(input);
    printf("\n");
    printf("Substring of the first 6 code points: ");
    utf8_substring(input,0,6);
    printf("Code points as decimal numbers: ");
    codepoint_value(input);
    printf("\n");
    printf("Animal emojis: ");
    animal_emoji(input);
    printf("\n");
    return 0;
}            
