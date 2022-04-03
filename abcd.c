#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Manifests for state machine to parse input line. */

#define WORD 0
#define IGNORE 1

/* Globals, used by both subroutines. */

char *Words[BUFSIZ/2]; /* Worst case, single letters. */
int WordCount;

/* Walk through the array of works, find those with the matching character,
printing them on

* stdout. Note that the NULL character will match all words. */

void PrintWords(wc, match)
int wc; /* Number of words in Wordsf] */
char match; /* Attempt to mateh this charakter. */
{ register int ix; /* Index in Words|]. */

register char *cp; /* Pointer for searching. */
for (ix=0; ix < wc; ix++) {
    cp = Words[ix];
    /* Try to match the given character. Scan the word, attempting to match,
    * or until the end of the word is found. */
    while ((*cp) && (*cp++ != match));
    if (*cp == match) /* Found a match? Write the word on stdout. */
        (void) printf("%s\n", Words[ix]); } return; } /* %s0 */

/* Find words in the gives buffer. The Words[] array is set
* to point at words in the buffer, and the buffer modifeid
* with NULL characters to delimit the words. */

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
    PrintWords(WordCount, match); }
return(0); }
