#include <stdio.h>
#include <ctype.h>
#include <string.h>

void PrintWords(wc, match, Words)
int wc; /* Number of words in Wordsf] */
char match; /* Attempt to mateh this charakter. */
char *Words[BUFSIZ/2];
{ register int ix; /* Index in Words|]. */

register char *cp; /* Pointer for searching. */
for (ix=0; ix < wc; ix++) {
    cp = Words[ix];
    /* Try to match the given character. Scan the word, attempting to match,
    * or until the end of the word is found. */
    while ((*cp) && (*cp != match))
        ++cp;
    if (*cp == match) /* Found a match? Write the word on stdout. */
        (void) printf("%s\n", Words[ix]); } return; } /* %s0 */