#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

int i;
int main(int argc, char const *argv[])
{

    struct stat fStat;
	if (stat(argv[1], &fStat) == -1) {
		perror("stat");
		exit(EXIT_FAILURE);
	}

    for(i=1; i<argc; i++) {
        printf("Informatii despre: %s\n", argv[i]);
        printf("---------------------------\n");
        printf("Dimensiune: \t\t%lld bytes\n", (long long) fStat.st_size);
        printf("Numarul de legaturi: \t%ld\n", (long) fStat.st_nlink);
        printf("Numarul inode: \t\t%ld\n\n", (long) fStat.st_ino);

        printf("Permisiuni: \t");
        printf( (S_ISDIR(fStat.st_mode)) ? "d" : "-");
        printf( (fStat.st_mode & S_IRUSR) ? "r" : "-");
        printf( (fStat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (fStat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (fStat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (fStat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (fStat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (fStat.st_mode & S_IROTH) ? "r" : "-");
        printf( (fStat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (fStat.st_mode & S_IXOTH) ? "x" : "-");

        printf("\nThe file %s a symbolic link\n", (S_ISLNK(fStat.st_mode)) ? "is" : "is not");

        printf("Ultimul status schimbat: %s\n", ctime(&fStat.st_ctime));
        printf("Ultima accesare a fisierului: %s\n", ctime(&fStat.st_atime));
        printf("Ultima modificare a fisierului: %s\n", ctime(&fStat.st_mtime));
    }

    return 0;
}