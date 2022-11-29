#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Program will encrypt a word by skipping forward by a certain value along the
// alphabet(a -> b, b -> c).

// Declare functions
char *Encrypt(char base[]);

char *Decrypt(char base[]);

bool YesNo(char yesno);


int main() {
  // Declare variables.
  char word[30];
  char yes_or_no;
  int tally = 0;
  bool check = false;
  char encrypt[30];
  char decrypt[30];

  // Get word from user.
  printf("Input a word. (< 31) ");
  scanf("%s", word);

  // Check word has no spaces with do/while loop.
  do {
    // Loop for spaces and count them up.
    for (int i = 0; i < 30; i++) {
      if (word[i] == ' ') {
        tally++;
      }
    }
    // Check, and prompt for retype if spaces are included.
    if (tally > 1) {
      printf("Invalid word, contains %i spaces, please retype. \n", tally);
      scanf("%s", word); getchar();
    } else {
      check = false;
    }
  } while (check);

  // Ask user if they want to do decryption or encryption.
  printf("Do you want to do encryption or decryption? (e/m) ");
  scanf("%c", &yes_or_no); getchar();

  // Put encryption and decryption in variable and print them out.
  if (YesNo(yes_or_no))
  {
	  strcpy(encrypt, Encrypt(word));
	  printf("%s\n", encrypt);
  } else {
	  strcpy(decrypt, Decrypt(word));
	  printf("%s\n", decrypt);
  }

  return 0;
}

// Extra function in case I use it again in the future.
bool YesNo(char yesno)
{
	bool yon = false;

	if (yesno == 'e')
	{
		yon = true; 
	}

	return yon;
}

// Encrypt string

char *Encrypt(char base[]) 
{
	char encrypted[30];
       	int key = 1;
	for (int count = 0; base[count] != '\0'; count++) 
	{
		base[count]++;
	}
	return base;
}

// Decrypt string
char *Decrypt(char base[])
{
	char encrypted[30];
       	int key = 1;
	for (int count = 0; base[count] != '\0'; count++) 
	{
		base[count]--;
	}
	return base;
}
