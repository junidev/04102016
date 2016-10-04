#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
#define NKEYS 20


#define BUFSIZE 100
char buf[MAXWORD];
int bufp = 0;


int getword(char *, int);
struct key *binsearch(char *, struct key *, int);
//struct key keytab[NKEYS];


int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("Demasiados caracteres\n");
    else
        buf[bufp++] = c;
}

struct key{
      char *word;
      int count;
}keytab[] = {
   "auto",0,
   "break",0,
   "case",0,
   "char",0,
   "const",0,
   "continue",0,
   "default",0,
   /*******/
   "unsigned",0,
   "void",0,
   "volatile",0,
   "while",0

};




main(){

    char word[MAXWORD];
    struct key *p;
    while(getword(word,100)!=EOF){
        if(isalpha(word[0])){
            if((p=binsearch(word,keytab,99))!=NULL){
                p->count++;
            }
        }
    }
    for(p=keytab;p<keytab+99;p++){
        if(p->count>0){
            printf("%d %s\n",p->count,p->word);
        }
    }
    return 0;
}


struct key *binsearch(char *word, struct key *tab, int n ){

       int cond;
       struct key *low = &tab[0];
       struct key *high = &tab[n];
       struct key *mid;


       while(low <high){

          mid = low+(high-low)/2;

          if((cond == strcmp(word, mid->word))<0)
                high=mid;
          else if (cond>0)
            low = mid+1;
          else
             return mid;
       }
        return NULL;
}


int getword( char *word, int lim )
{

    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c=getch()));
    if (c != EOF)
        *w++ = c;
    if(!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
      if (!isalnum(*w = getch())){
             ungetch(*w);
             break;
      }

        *w = '\0';
       return word[0];
}

