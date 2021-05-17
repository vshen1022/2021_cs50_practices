#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc,char* argv[])
{
  if(argc!=2)//the command line arguemant should be exacly 2
  {
    printf("vigenere k\n");
    return 1;
  }
  else
  {
      char* key=argv[1];//the second command line arguemant is the key
      int key_nums [strlen(key)];//製作一個和key的字數相同的array,放在heap以防消失
      int* key_nums_ptr=malloc(sizeof(key_nums));
      if(!key_nums_ptr)
      {
          return 2;
      }
      //預先將key轉化成數字，儲存在int array key_num 裡面
      for(int i=0;i<strlen(key);i++)
      {
        if(isupper(key[i]))
        {
          key_nums[i]=(key[i]-65)%26;
        }
        else
        {
           key_nums[i]=(key[i]-97)%26;
        }
      }
      char* plaintext=get_string("plaintext:");//promt the user for plaintext
       printf("ciphertext: ");
        int alpha=0; //用int j來追蹤現在的第i個contant是plaintext中的第幾個字母,要定義在for loop外面以免會在for loop裡被重複歸零
      for(int i=0;i<strlen(plaintext);i++)//開始cypher
      {
        if(isalpha(plaintext[i]))
        {
          if(isupper(plaintext[i]))
          {
            //key_num array裡的第"現在在處理的第i次的i除以key的餘數"(ex.0/2=0，1/2=1，2/2=0)個數字來加密地i
            //個plaintext
            printf("%c",(plaintext[i]+key_nums[alpha%strlen(key)]-65)%26+65);
            alpha=alpha+1;
          }
          else
          {
            printf("%c",(plaintext[i]+key_nums[alpha%strlen(key)]-97)%26+97);
            alpha=alpha+1;
          }
        }
        else
        {
          printf("%c",plaintext[i]);
        }
      }
   printf("\n");
   free(key_nums_ptr);

  }
  return 0;
}
