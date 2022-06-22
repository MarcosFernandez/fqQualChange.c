#include <stdlib.h>
#include <stdio.h>

int main(int argc,char** argv) {
    if (argc!=2) {
        printf("Syntax: %s <quality displacement> <input> output\n", argv[0]);
        exit(1);
    }

    const int        n    = atoi(argv[1]);
    size_t           dum  = 0;
    register ssize_t read = 0;
    char*            buf  = 0;
    register ssize_t i;

    /* Loop over all lines in the file */
    while (getline(&buf, &dum, stdin)!=-1) {
        /* Read and write the first 3 lines of the entry */
        printf("%s", buf);
        getline(&buf, &dum, stdin);
        printf("%s", buf);
        getline(&buf, &dum, stdin);
        printf("%s", buf);

        /* Read qualities line */
        read=getline(&buf, &dum, stdin);

        /* Substract displacement if it is not zero */
        if (n != 0) {
            --read; /* Don't forget the NL char at the end! */
            for (i=0; i<read; ++i)
                buf[i]+=n;
        }

        /* Write displaced qualities line */
        printf("%s", buf);
    }

    /* Resource freeing */
    free(buf);

    return EXIT_SUCCESS;
}

