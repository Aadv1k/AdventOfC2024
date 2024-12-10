#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define INPUT_FILE "./sample.txt"

void bubble_sort(int* items, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j <= length - i - 1; j++) {
            if (items[j] >= items[j+1]) {
                int temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}

void do_part1() {
    FILE *fp = fopen(INPUT_FILE, "r");

    int lineCount = 0;
    while (!feof(fp)) {
        if (fgetc(fp) == '\n') lineCount++;
    }

    int* list1 = (int*)malloc(sizeof(int) * lineCount);
    int* list2 = (int*)malloc(sizeof(int) * lineCount);


    rewind(fp);

    int i = 0;
    int locId1, locId2;
    while (!feof(fp) && i < lineCount) {
        fscanf(fp, "%d   %d", &locId1, &locId2);
        list1[i] = locId1;
        list2[i] = locId2;
        i++;
    }


    bubble_sort(list1, lineCount);
    bubble_sort(list2, lineCount);

    int result = 0;

    for (int i = 0; i <= lineCount; i++) {
        result += abs(list1[i] - list2[i]);
    }

    printf("The sum of all differences is %d\n", result);

    free((void*)list1);
    free((void*)list2);

    fclose(fp);
}


int main() {
    do_part1();
}
