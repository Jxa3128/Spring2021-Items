#include <stdio.h>
#include <stdlib.h>

int isCompare (char w1[], char w2[])
{
  int count1 = 0, count2 = 0;
  while (w1[count1] != '\0' && w2[count2] != '\0')
    {
      if (w1[count1] != w2[count2]){
        return 0; //not the same
      }
      count1++;
      count2++;
    }
  return 1;
}

int main ()
{
  char w1[100];
  char w2[100];
  printf ("Enter Word 1: ");
  scanf ("%s", w1);
  printf ("Enter Word 2: ");
  scanf ("%s", w2);
  int res = isCompare(w1, w2);
  if (res==1)
    printf ("The words %s and %s are the same.\n",w1,w2);
  else
    printf ("Not the same word.");
  return 0;
}
