#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Manifests for state machine to parse input line. */

#define WORD 0
#define IGNORE 1

char *Words[BUFSIZ/2]; /* Worst case, single letters. */
int WordCount;
extern void PrintWords(int wc, char match, char *Words[]);

int GetWords (buf)

char buf[];                /* The input buffer. */

{register char *cp;         /* Pointer for scanning. */
int end = strlen(buf);      /* length of the butter. */
register int wc = 0; /* Number of words found. */

int state=IGNORE;  /* Current state. */
/* For each character in the buffer, */
for (cp = &buf[0]; cp < &buf[end]; cp++) {
/* A simple state machine to process
* the current character in the buffer. */
switch(state) {
case IGNORE:
if (!isspace(*cp)) {
Words[wc++] = cp;
state = WORD; } break;
case WORD:
if (isspace(*cp)) {
    *cp = '\0';
    state = IGNORE; } break; }}
return wc; }

int main(argc, argv) int argc; char *argv[]; { char buf[BUFSIZ], match;
/* Check command line arguments. */
if (argc < 2) match = '\0';
/* No command line argument, match all words. */

else match = *++argv[1]; /* match the char afier the first - */

while(gets(buf) != (char *)NULL) {
    WordCount = GetWords(buf);
    PrintWords(WordCount, match, Words); }
return(0); }