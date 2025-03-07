#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>
#include <string.h>

void print_users_sorted() {
    struct passwd *pw;
    setpwent();
    struct passwd *users[100];
    int count = 0;

    while ((pw = getpwent()) != NULL) {
        users[count] = pw;
        count++;
    }
    endpwent();

    // Сортировка по алфавиту
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(users[i]->pw_name, users[j]->pw_name) > 0) {
                struct passwd *temp = users[i];
                users[i] = users[j];
                users[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", users[i]->pw_name, users[i]->pw_dir);
    }
}
