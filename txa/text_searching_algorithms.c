#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


//Implement proper readfile!!!!!

char* ReadFile(char *filename);
void naive(char *pattern, char *text);

int main(int argc, char **argv)
{
    if(argc!=3)
    {
        printf("Wrong arguments! First text, than pattern!\n");
        exit(1);
    }

    char *text = ReadFile(argv[1]);
    char *pattern = ReadFile(argv[2]);

    char *ex_text = "AABAACAADAABAABA";
    char *ex_pattern = "AABA";

    printf("%s %ld",text,strlen(text));
    printf("%s",pattern);
    naive(pattern, text);

    free(pattern);
    free(text);
    return 0;
}

void naive(char *pattern, char *text)
{
    int text_length = strlen(text); //n
    int pattern_length = strlen(pattern); //m
    int diff = text_length-pattern_length; //n-m
    int i,j;
    for(i=0; i<=diff; i++)
    {
       // if(text[i]=='\n') text[i] = text[i+1];
        for(j=0; j<pattern_length; j++)
        {
           // if(pattern[j]=='\n') pattern[j] = pattern[j+1];
            if(text[i+j] != pattern[j]) break;
        }
        if(j==pattern_length) printf("Pattern found at index %d\n",i);
    }
}

char* ReadFile(char *filename)
{
   FILE *file = fopen(filename, "rt");
   char *buffer;
   long numbytes;

   if(file == NULL) exit(1);
   fseek(file, 0L, SEEK_END);
   numbytes = ftell(file);
   fseek(file, 0L, SEEK_SET);
   buffer = (char*)calloc(numbytes, (sizeof(char)));

   if(buffer == NULL) exit(1);
   fread(buffer, sizeof(char), numbytes, file);
   fclose(file);
   
   return buffer;
}

