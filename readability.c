#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //取得使用者提供的文章段落
    string text = get_string("Text: ");

    //計算段落裡有幾個英文字母
    int text_length = strlen(text);

    float num_of_char = 0;//註：當使用int型態的值進行計算後，便只能得到int型態的結果，如此會影響第51行公式的運算，故使用floatt宣告此變數

    for(int i = 0; i < text_length; i++)
    {
        if(isalpha(text[i]))//用array裡的物件是不是字母來判斷text裡有多少英文字母
        {
           num_of_char = num_of_char + 1;
        }
    }

    //計算段落裡有幾個詞語
    float num_of_word = 1;//因為空白會出現在詞語和詞語間，詞語數會是空白數+1，所以從1起算

    for (int i = 0; i < text_length; i++)
    {
         if (isspace(text[i]))//用詞語和詞語間的空格來計算詞語的數量
         {
             num_of_word = num_of_word + 1;
         }
    }

    //計算段落裡有幾個句子數量
    float num_of_sentence = 0;

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == 46||text[i] == 63||text[i] == 33)//句號的ascii是46，問號的ascii是63，驚嘆號的ascii是33
        {
            num_of_sentence = num_of_sentence + 1;
        }
    }

    //套用可讀性公式"index = 0.0588 * L - 0.296 * S - 15.8"
    //L是指每100個詞語中平均有多少英文字母，用  (總英文字母數/總詞語數)*100 計算
    float l = (num_of_char / num_of_word) * 100;
    //S是指每100個詞語中平均有幾個句子，用  (總句子數/總辭與數)*100  計算
    float s = (num_of_sentence /  num_of_word) * 100;
    //套用公式
    int index = round(0.0588 * l - 0.296 * s - 15.8);
    //印出index
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n",index);
    }
}