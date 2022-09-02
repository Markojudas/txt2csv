#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ROW 10000
#define MAX_STRING_SIZE 10000
#define MAX_LEN 10000


void handleConvert ();
void handleFiles ();
char getCommandWord (char cmd[], int maxLength);
void doConversions (char *sourceFile, char *destinationFile, char *sourceExt,
		    char *destExt);

int
main ()
{
  char cmd[MAX_STRING_SIZE];
  char lastCharacter;

  printf
    ("\n********************************************************************\n");
  printf
    ("********** FILE CONVERSION PROGRAM (.txt -> .csv -> .txt) ************\n");
  printf
    ("********************************************************************\n\n");

  printf ("List of commands:\n\n");
  printf ("quit\t\t\t\t\tTerminates and exits the program\n");
  printf ("convert <source.ext> <dest.ext>\t\tConverts file\n");

  while (1)
    {
      printf ("\nPlease enter command: ");
      lastCharacter = getCommandWord (cmd, MAX_STRING_SIZE);
      if (!strcmp (cmd, "quit")) break;
      else if (!strcmp (cmd, "convert"))
	{
	  if (lastCharacter == '\n')
	    {
	      printf ("\nNOT ENOUGH ARGUMENTS\n");
	    }
	  else
	    {
	      handleConvert ();
	    }
	}
      else
	{
	  printf ("\nINVALID COMMAND\n");
	  while (lastCharacter != '\n')
	    lastCharacter = getCommandWord (cmd, MAX_STRING_SIZE);
	}
    }
}

char
getCommandWord (char cmd[], int maxLength)
{
  char lastCharacter;
  int i;

  for (i = 0; i < maxLength && (cmd[i] = getchar ()) != ' ' && cmd[i] != '\n';
       i++);

  lastCharacter = cmd[i];
  cmd[i] = '\0';

  return lastCharacter;
}

void
doConversions (char *sourceFile, char *destinationFile, char *sourceExt,
	       char *destExt)
{
  int i = 0;
  FILE *input = fopen (sourceFile, "r");
  if (input == NULL)
    {
      printf ("\nNO INPUT FILE FOUND\n");
      return;
    }
  char *data[MAX_ROW];
  char *token = (char *) malloc (MAX_STRING_SIZE + 1);
  int dataIndex = 0;
  char line[MAX_LEN];
  char delim[] = " ,\t\n";

  for (; fgets (line, MAX_LEN, input) != NULL; i++)
    {
      data[dataIndex] = (char *) malloc (strlen (line) + 1);
      strcpy (data[dataIndex++], line);
    }
  fclose (input);
  input = NULL;

  if (!strcmp (destExt, "txt") || !strcmp (destExt, "csv"))
    {
      FILE *output = fopen (destinationFile, "w");
      for (i = 0; i < dataIndex; i++)
	{
	  token = strtok (data[i], delim);
	  fprintf (output, "%s", token);
	  while (token = strtok (NULL, delim))
	    {
	      if (!strcmp (destExt, "txt"))
		fprintf (output, "\t%s", token);
	      else
		fprintf (output, ",%s", token);
	    }
	  fprintf (output, "\n");
	}
      fclose (output);
      output = NULL;
    }
  else
    {
      printf ("\nFILE EXTENSION NOT SUPPORTED FOR CONVERSION (yet)\n");	//prints if an extension that's not supported is passed
      return;
    }
  printf ("\nCONVERSION COMPLETE!\n");
}

void
handleConvert ()
{

  char sourceFile[MAX_STRING_SIZE];
  char destinationFile[MAX_STRING_SIZE];
  char lastCharacter;

  //getting the sourceFile
  lastCharacter = getCommandWord (sourceFile, MAX_STRING_SIZE);
  if (lastCharacter == '\n')
    {
      printf ("\nNOT ENOUGH ARGUMENTS\n");
      return;
    }
  //getting the destinationFile
  lastCharacter = getCommandWord (destinationFile, MAX_STRING_SIZE);
  if (lastCharacter != '\n')
    {
      printf ("\nTOO MANY ARGUMENTS\n");
      while (getCommandWord (destinationFile, MAX_STRING_SIZE) != '\n');
      return;
    }

  char *sourceExt = NULL;
  char *destExt = NULL;

  if ((sourceExt = strstr (sourceFile, ".")) != NULL)
    {
      sourceExt++;
    }
  else
    {
      printf ("\nPLEASE IDENTIFY THE FILE EXTENSION FOR SOURCE\n");
      return;
    }

  if ((destExt = strstr (destinationFile, ".")) != NULL)
    {
      destExt++;
    }
  else
    {
      printf ("\nPLEASE IDENTIFY THE FILE EXTENSION FOR DESTINATION\n");
      return;
    }

  //depending on the extension of the sourceFile, calling the function
  if (!strcmp (sourceExt, "csv") || !strcmp (sourceExt, "txt"))
    {
      doConversions (sourceFile, destinationFile, sourceExt, destExt);
    }
  else
    {
      printf ("\nFILE EXTENSION NOT SUPPORTED OR RECOGNIZED\n");
      return;
    }
}
