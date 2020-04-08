#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[])
{   
    int n;
    if(argc == 4 && access(argv[1], F_OK | R_OK) != -1 && sscanf(argv[2], "%d", &n) == 1 && atoi(argv[2]) >= 0 && atoi(argv[2]) < 2 && strlen(argv[3]) > 0)
    {
        puts("\netf - encrypt text file\ncreds: sc3m3 aka kolya aka god aka one true and only god of this reality\n\n");

        FILE *fp;
        fp = fopen(argv[1], "r");
        fseek(fp, 0L, SEEK_END);
        int size = ftell(fp);
        fseek(fp, 0L, SEEK_SET);

        char* outstr = calloc(size, sizeof(char));
        fread(outstr, sizeof(char), size, fp);

        int keylen = strlen(argv[3]);
        for(int i = 0; i < strlen(outstr); i++)
        {
            outstr[i] = outstr[i] + (atoi(argv[2]) ? argv[3][i % keylen] : -argv[3][i % keylen]);
        }

        char* path = strdup(argv[1]);
        FILE* fout;
        switch(atoi(argv[2]))
        {
            case 1:
                strcat(path, ".etfc");
                break;
            case 0:
                path[strlen(path) - 5] = '\0'; break;
            default:
                puts("[-] highly unexpected error\nhow did you manage to get here?"); exit(0);
        }

        fout = fopen(path, "w+");
        fclose(fp);
        if(remove(argv[1]) != 0) puts("[-] couldn't delete input file, delete manually to ensure only crypted data remains");
        if(fwrite(outstr, sizeof(char), strlen(outstr), fout) > 0) printf("[+] success, wrote crypted data to %s\n", path);
        fclose(fout);
        exit(0);

    } else {
        printf("usage: %s <text file to crypt> <0 for de- 1 for encrypt> <key to use for crypting>\n", argv[0]);
        exit(0);
    }
}
