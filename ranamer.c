#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int counter = 0;

void rename_file(const char *old_path, const char *new_path) {
    if (rename(old_path, new_path) == 0) {
        printf("Renamed: %s -> %s\n", old_path, new_path);
		counter++;
    } else {
        perror("Error renaming file");
    }
}

void traverse_directory(const char *directory) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        char old_path[1024];
        snprintf(old_path, sizeof(old_path), "%s/%s", directory, entry->d_name);

        // Skip the current directory and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Check if it's a directory
        struct stat file_stat;
        if (stat(old_path, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
                // Recursively traverse subdirectories
                traverse_directory(old_path);
            } else if (S_ISREG(file_stat.st_mode) && strchr(entry->d_name, 'a') != NULL) {
                // Rename the file if it contains 'a'
                rename_file(old_path, old_path); // Here you can change the new name as needed
            }
        }
    }

    closedir(dp);
}

int main() {

	const char *directory = "C:\\Users\\user\\Desktop\\renamer\\some_dir"; // Change this to your desired directory path
    traverse_directory(directory);
	printf("Renamed %d files\n", counter);
	getchar();
    return 0;
}
