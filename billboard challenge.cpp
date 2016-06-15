#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
using namespace std;

int MaxFont(int width, int height, int wordLength[], int WordsArr)//WordsArr = jumlah kata di dalam kalimat
{
   int font = 1;
   int widthLeft, lines, i;
   
   while(font<=height)//terus looping cari font terbesar
   {
      lines = height/font;
      widthLeft = width;
      
      for(i=0; i<WordsArr; i++)//proses tiap kata dalam kalimat
      {
         if(wordLength[i]*font<=widthLeft)
         {
            widthLeft -= (wordLength[i]*font+font);//+font dianggap seperti SPACE
         }
         else if(lines>1)
         {
            lines--;
            widthLeft=width;
            if(wordLength[i]*font<=widthLeft)
            {
               widthLeft -= (wordLength[i]*font+font);
            }
            else
            {
               break;
            }
         }
         else
         {
            break;
         }
      }/* end of for */
      
      if(i==WordsArr)//jika 1 kalimat uda selesai diproses
      {
         font++;//naikan font size
      }
      else//jika belum baca 1 kalimat, tapi uda break, berarti font size nya kegedean!
         //makanya langsung break aja, ga perlu font++ lagi!
      {
         break;
      }
   }
   return font-1;//Jika font lebih besar dari Height-nya, return 0
   //jika font nya pas, harus di minus 1 juga. karena diatas ada font++
   //contoh: font 12 uda oke, di font++ jadi 13
   //jadi harus di minus 1 biar 12 lagi
}

void display(int font_size[], int test_case)
{
   for(int x=0;x<test_case;x++)
   {
      cout<<"Case #"<<x+1<<": "<<font_size[x]<<endl;
   }
}

int main()
{
    int test_case, i,j,k, WordsArr;
    int width, height;
    int wordLength[500];
    string arrOfWords[500];
    string str;
    cin>>test_case;
    
    int font_size[test_case];
    
    for(i=0;i<test_case;i++)
    {               
       WordsArr = 0;//array untuk menyimpan setiap kata
       cin>>width;
       cin>>height;
       cin.ignore();
       getline(cin, str);
       stringstream ssin(str);
       
       while(ssin.good())
       {
          ssin>>arrOfWords[WordsArr];//ambil setiap kata di dalam String
          WordsArr++;               
       }
       
       for(j = 0;j<WordsArr;j++)
       {
          wordLength[j] = arrOfWords[j].length();//simpan length dari tiap huruf
       }
       
       font_size[i] = MaxFont(width, height, wordLength, WordsArr);
    }
    
    display(font_size, test_case);
    
    system("pause");
    return 0;
}
