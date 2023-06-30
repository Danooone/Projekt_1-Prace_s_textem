#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_COUNT 42
#define MAX_STR_LEN 100

// Převod písmen na čísla
void to_digits(char source[], char as_digits[])
{
  const char* digits = "22233344455566677778889999";
                     // abcdefghijklmnopqrstuvwxyz
  for (int i = 0; i < MAX_STR_LEN+1; ++i) {
    char ch = source[i];
    if (ch == '+') { ch = '0'; }
    else if (isalpha(ch)) {
      ch = digits[tolower(ch)-'a'];  // písmena k číslům
    }
    as_digits[i] = ch;
    if (!ch) { break; }
  }
}


int main(int argc, char* argv[])
{
    // Přečtení požadavku z terminalu
  int t9_len = 0;
  char t9[MAX_STR_LEN+1] = "";
  if (argc >= 2) {
    for (int i = 0; i < MAX_STR_LEN+1 && argv[1][i]; ++i) {
      char ch = argv[1][i];  // další znak terminalu
      if (!isdigit(ch)) {
        printf("T9 search string must contain only digits.\n");
        return EXIT_FAILURE;
      }
      t9[i] = ch;
      ++t9_len;
    }
  }

    // Čtení dat
  char s[MAX_COUNT][2][MAX_STR_LEN+1];
  int count = 0;
  for (int i = 0; i < MAX_COUNT && fgets(s[i][0], MAX_STR_LEN+1, stdin) && fgets(s[i][1], MAX_STR_LEN+1, stdin); ++i) {
    int len1 = strlen(s[i][0]);
    if (len1 > 0 && s[i][0][len1-1] == '\n') { s[i][0][--len1] = '\0'; }
    int len2 = strlen(s[i][1]);
    if (len2 > 0 && s[i][1][len2-1] == '\n') { s[i][1][--len2] = '\0'; }
    if (len1 == 0 || len2 == 0) {
      printf("Empty strings are not allowed.\n");
      return EXIT_FAILURE;
    }
    ++count;
  }
  if (count == 0) {
    printf("No contacts are read.\n");
    return EXIT_FAILURE;
  }
  printf("%d contact(s) successfully read.\n", count);

    // Zpracování požadavku
  int found = 0;  // počet nalezených kontaktů
  for (int i = 0; i < count; ++i) {
    int ok = 1;
    if (t9[0]) {
      char as_digits[2][MAX_STR_LEN+1];
      to_digits(s[i][0], as_digits[0]);  // převod jména na čísla
      to_digits(s[i][1], as_digits[1]);  // převede číslo na čísla
      ok = strstr(as_digits[0], t9) || strstr(as_digits[1], t9);
    }
    if (ok) {
      printf("%s, %s\n", s[i][0], s[i][1]);
      ++found;
    }
  }
  if (found == 0) {
    printf("Contacts not found.\n");
  } else {
    printf("%d contacts found.\n", found);
  }
}
