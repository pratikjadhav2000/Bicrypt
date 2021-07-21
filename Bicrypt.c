/*
Author : Pratik U. Jadhav

Hello this C program 'Bicrpyt' is used to Encrypt a string
into binary string. Also encrpyted string can be Decrypted
into a message.

*/

#include<stdio.h>
#include<stdlib.h>
#define BINARYLENGTH 8
#define TRUE 1

void string_to_binary();
void binary_to_string();


int main(int argc, char const *argv[])
{
  printf("\n\n\t\t\tWelcome to Bicrpyt!\n\n ");

  int get_input;
  while (TRUE) {
    printf("\n Pick your conversion\n\n1.Encrypt a Message\n2.Decrypt Binary Message\n3.EXIT\n");
    scanf("%c", &get_input );

      switch ( get_input )
       {
        case '1':
        string_to_binary();
        break;

        case '2':
        binary_to_string();
        break;

        case '3':
        exit(0);
        break;

        default:
        printf("Please choose appropriate choice\n" );
        break;

      }//end switch


  }//end while


  return 0;
}//end main

void string_to_binary(){

printf("\nEnter a message to Encrypt\n" );
      int char_input;
      char_input = getchar();
      while ( ( char_input = getchar() ) != '\n')
       {

        if( char_input == '\n' )
        break;

        //convert char to binary

        char binary_number[BINARYLENGTH];
        char binary_reverse[BINARYLENGTH];

        //initialization
        for (int i = 0; i < BINARYLENGTH; ++i)
          binary_number[i] = binary_reverse [i] = '0';


        int input = (int)char_input;
        int position = -1;
        //conversion to binary
        while ( input > 0 )
        {
          position++;

          if( input % 2 == 0 )
          binary_reverse[position] = '0';
          else
          binary_reverse[position] = '1';

          input /= 2;
          if ( (position + 1) == BINARYLENGTH )
            break;

        }

        //reverse the result to get actual binary result
        for (int i = BINARYLENGTH - ( position + 1 ); i < BINARYLENGTH; ++i)
          binary_number[i] = binary_reverse[position--];

        for (int i = 0; i < BINARYLENGTH; ++i)
        printf("%c",binary_number[i] );


      }//end while
printf("\n" );

}

void binary_to_string(){

printf("\nEnter a binary Decrypted message\n");

    int bin_input;
    int length = 0;

    char binary_number[BINARYLENGTH];
    for (int i = 0; i < BINARYLENGTH; ++i)
      binary_number[i] = '0';

    bin_input = getchar();
    while ( ( bin_input = getchar() ) != EOF)
    {
      if ( bin_input == '\n' )
      break;

      binary_number[length++] = bin_input;

      if( length > BINARYLENGTH - 1 )
      {
        int number=0;
        int power = 1 ;
        //now binary number is filled in binary_number array
        //to do process it and display char

          for (int i = BINARYLENGTH - 1; i >=0 ; --i)
          {
              if( binary_number[i] == '1' )
              {
                number += power;
              }

              power *= 2;
          }
          printf("%c",number );

            length = 0;
      }

    }//end while
printf("\n");

}
