#include <stdio.h>
#include <string.h>
char main(void)
{
    char chaine1[50];
    char chaine2[60];
    
    printf("donner chaine1 \n");
    scanf("%s",&*chaine1);
    
    printf("donner chaine2 \n ");
    scanf("%s",&*chaine2);

    strcat(chaine1,chaine2);
    printf("%s\n", chaine1);
    return 0;
}

