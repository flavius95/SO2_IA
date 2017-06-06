#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

int i;
int main(int argc, char const *argv[])
{

    DIR *d;
    struct dirent *dir;
    struct stat fStat;
    struct passwd *pwd;
    uid_t uid;
    gid_t gid;
    pwd = getpwuid(id);
	if (stat(argv[1], &fStat) == -1) {
		perror("stat");
		exit(EXIT_FAILURE);
	}

    for (int i = 0; i < argc; i++)
    {
        do {
            d = opendir(argv[i]);
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                    printf("\nInformatii despre: %s\n", dir->d_name);
                    printf("---------------------------\n");
                    printf("Dimensiune: \t\t%lld bytes\n", (long long) fStat.st_size);
                    printf("Numarul de legaturi: \t%ld\n", (long) fStat.st_nlink);
                    printf("Numarul inode: \t\t%ld\n\n", (long) fStat.st_ino);
                    printf("Uid is: \t\t%d\n", fStat.st_uid);
                    printf("Group id is: %d\n", fStat.st_gid);

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
            }
        closedir(d);
        }
        while(argv[i]!=S_ISDIR(fStat.st_mode){
            //mi-a venit o idee sa citesc toate argumentele cat timp si fisiere dar dupa aia nu mai stiu ce sa fac..
        }
        }
    }

    return 0;
}