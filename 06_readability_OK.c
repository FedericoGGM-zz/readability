#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void count_tot();

int main(void)
{
    //Get text from user, store in string
    string text = get_string("Text: ");
    //Call function that calculate the index and print it on screen
    count_tot(text);

}


void count_tot(string s)
{
    int n_letter = 0, n_sentences = 0, index = 0; 
    float L = 0, S = 0, n_word = 0;
    
    for (int i = 0; i < strlen(s) ; i++)
    {
        //If the element is a letter, increment n_letter
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            n_letter++;
        }
        //If the element is a space, increment de words counter
        else if (s[i] == ' ')
        {
            n_word++;
        }
        //If any of these characters, it is a sentence end
        else if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            n_sentences++;
        }
    }
    //Add one more word 
    n_word++;
    
    //Calculate L and S values
    L = (100 * n_letter) / n_word;
    S = (100 * n_sentences) / n_word;
    
    //Calculate index using Coleman-Liau formula
    index = round(0.0588 * L - 0.296 * S - 15.8);
	
	//Print any of the scenarios
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}