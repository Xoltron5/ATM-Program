/* Program Description:
    This program is a working ATM that asks you to enter your pin, change your pin and show you the amount of times
    you entered your pin correctly and incorrectly.

    Author: Denis Bajgora
    Date: 5/11/22

*/


#include <stdio.h>

int main()
{
    int loop_check = 1;
    int user_option;
    int inital_pin = 1234;
    int enter_digits[4];
    int enter_pin;
    int new_digits[4];
    int new_pin;
    int re_entered_digits[4];
    int re_entered_pin;
    int correct_entered = 0;
    int incorrect_entered = 0;
    int i;

    do
    {
        printf("\nChoose 4 of the following options by entering the number that is beside the option.\n");
        printf("\n1 = Enter your pin\n2 = Change your pin.\n3 = Display the number of times the PIN was entered successfully and incorrectly\n4 = Exist the ATM\n");
        scanf("%d",&user_option);

        while(getchar() != '\n'); // ingores the enter key which is seen as a character.

        switch (user_option)
        {
        case 1: // This case asks the user to enter their pin.
        {   
            for (i = 0; i < 4; i++)
            {
                printf("Enter digit %d\n",i + 1);
                scanf("%d",&enter_digits[i]);

                while(getchar() != '\n'); // ingores the enter key which is seen as a character.

                if (enter_digits[i] >= 0 && enter_digits[i] <= 9) // if entered digits is between 0 and 9
                    {
                        if (i == 3)
                        {
                            enter_pin = ((enter_digits[0]*1000) + (enter_digits[1]*100) + (enter_digits[2]*10) + enter_digits[3]);

                            if (enter_pin == inital_pin)
                            {
                                printf("\nPIN has been entered correctly!\n");
                                correct_entered++;
                            } // end if
                            else
                            {
                                printf("\nPIN has been entered incorrectly!\n");
                                incorrect_entered++;
                            } // end else

                        } // end if

                    } // end if
                    else // if enter digits is not between 0 and 9
                    {
                        printf("Digit was not between 0 and 9\n");
                        if (i >= 0)
                        {
                            i--;
                        }
                    } // end else

            } // end for

            break;
        } // end case 1

        case 2: // Changes the pin of the user
        {
            for (i = 0; i < 4; i++)
            {
                printf("Enter your new digit %d\n",i + 1);
                scanf("%d",&new_digits[i]);

                while(getchar() != '\n'); // ingores the enter key which is seen as a character.

                if (new_digits[i] >= 0 && new_digits[i] <= 9) // if new digits is between 0 and 9
                {
                    if (i == 3)
                    {
                        new_pin = ((new_digits[0] * 1000) + (new_digits[1] * 100) + (new_digits[2] * 10) + new_digits[3]);
                    } // end if      
                } // if 
                else // if new digits is not between 0 and 9
                {
                    printf("Digit has to be between 0 and 9\n");
                    if (i >= 0) // if the user enters the wrong digit it takes 1 away from i so the user can go again.
                    {
                        i--;
                    } // if 

                } // end else
            }
            for (i = 0; i < 4; i++)
            {
                printf("Re-Enter your new digit %d\n",i + 1);
                scanf("%d",&re_entered_digits[i]);

                while(getchar() != '\n'); // ingores the enter key which is seen as a character.
                
                if (re_entered_digits[i] >= 0 && re_entered_digits[i] <= 9) // if re entered digits is between 0 and 9
                {
                    if (i == 3)
                    {
                        re_entered_pin = ((re_entered_digits[0] * 1000) + (re_entered_digits[1] * 100) + (re_entered_digits[2] * 10) + re_entered_digits[3]);
                        if (new_pin == re_entered_pin)
                        {
                            inital_pin = new_pin; // inital pin is now the new pin
                            printf("PIN entered correctly!");
                            correct_entered++;
                        } // end if
                        else
                        {
                            printf("PIN entered incorrectly!");
                            incorrect_entered++;
                        } // end else

                    } // end if

                } // end if
                else
                {
                    printf("Digit has to be between 0 and 9\n");
                    if (i >= 0) // if the user enters the wrong digit it takes 1 away from i so the user can go again.
                    {
                        i--; 
                    } // if 

                } // end else

            } // end for

            break;
        } // end case 2

        case 3: // prints the amount of correct and incorrect times the pin was entered
        {
            printf("You have entered the correct pin %d times\n",correct_entered); // prints the correct times the pin was entered.
            printf("You have entered the incorrect pin %d times\n",incorrect_entered); // prints the incorrect times the pin was entered.
            break;
        } // end case 3

        case 4: // Exists the program
        {   
            loop_check = 0; 
            break;
        } // end case 4
        default:
        {
            printf("\nInvalid Option\n");
            break;
        }
        } // end default 
  
    } while (loop_check != 0); // end while
    return 0;
} // end main
