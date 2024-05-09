#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
  FILE *file;
  char line[256];

  file = fopen("input.txt", "r");

  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }


  while(fgets(line, sizeof(line), file)) 
  {
    int counter = 0;
    int length = strlen(line);
    int result = 0;
    char dig[256] = "";
    for(int i = 0; i < length; i++){
        if(isdigit(line[i])) {
            strncat(dig, &line[i], 1);
            //int num = line[i] - '0';
            //result += num; 
            if (counter == 1) {
                break;
            }

            counter++;
        }
    }
    //int num = dig - '0';
    //printf("%s", dig);
    int num = atoi(dig);
    result += num;
    printf("%d\n", result);
  };


  fclose(file);
  return 0;
}
