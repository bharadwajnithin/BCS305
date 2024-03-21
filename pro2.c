#include <stdio.h>

// Function prototypes
void read();
void match();

// Global variables
char STR[100], PAT[100], REP[100], ANS[100];
int flag = 0;

int main() {
    read();
    match();
    return 0;
}

void read() {
    printf("Enter the main string (STR): ");
    gets(STR);
    printf("Enter the pattern string (PAT): ");
    gets(PAT);
    printf("Enter the replace string (REP): ");
    gets(REP);
}

void match() {
    int c = 0, i = 0, j = 0, k = 0, m = 0;

    while (STR[c] != '\0') {
        if (STR[m] == PAT[i]) {
            i++;
            m++;
            flag = 1;
            if (PAT[i] == '\0') {
                for (k = 0; REP[k] != '\0'; k++, j++)
                    ANS[j] = REP[k];
                i = 0;
                c = m;
            }
        } else {
            ANS[j] = STR[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }

    if (flag == 0)
        printf("Pattern not found\n");
    else {
        ANS[j] = '\0';
        printf("Resultant string is %s\n", ANS);
    }
}
