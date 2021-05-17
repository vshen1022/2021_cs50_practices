#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string key = argv[1];

    //檢查使用者輸入的command line arguments 是否「剛好為2個」且「第2個皆為數字」
    if (argc != 2)
    {
        printf("Usage:./ caesar key\n");
        return 1;
    }
    else
    {
        int key_length = strlen(key);
        for (int i = 0; i < key_length; i++)
        {
            if (isdigit(key[i]) == 0)
            {
               printf("Usage:./ caesar key\n");
               return 1;
            }
        }

    }

    //command line arguments目前的資料型態為string，將資料型態改為int
    int key_int = atoi(key);

    //取得要處理的字串
    string plaintext = get_string("plaintext: ");

    //encipher取得的字串
    printf("ciphertext:");
    int text_length = strlen(plaintext);
    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                printf("%c", (plaintext[i] + key_int - 65) % 26 + 65); //A的ASCII value是65
            }
            else
            {
                printf("%c", (plaintext[i] + key_int - 97) % 26 + 97); //a的ASCII value是97
            }
        }
        else
        {
            printf("%c", plaintext[i]) ;
        }
    }

    printf("\n");
    return 0;

}