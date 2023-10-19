#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    float average;
};

int main() {
    struct student s[3] = {{1, 80.0}, {2, 85.0}, {3, 90.0}};
    FILE *fp;

    fp = fopen("students.dat", "wb+");
    fwrite(s, sizeof(struct student), 3, fp);

    fseek(fp, sizeof(struct student), SEEK_SET);
    struct student new_s = {2, 95.0};
    fwrite(&new_s, sizeof(struct student), 1, fp);

    fseek(fp, 0, SEEK_SET);
    struct student read_s;
    printf("Registros antes de ser modificados:\n");
    while (fread(&read_s, sizeof(struct student), 1, fp)) {
        printf("Número de matrícula: %d\n", read_s.id);
        printf("Promedio: %.2f\n", read_s.average);
        printf("\n");
    }

    fseek(fp, sizeof(struct student), 0);
    new_s.average = 999.0;
    fwrite(&new_s, sizeof(struct student), 1, fp);

    fseek(fp, 0, SEEK_SET);
    printf("Registros después de ser modificados:\n");
    while (fread(&read_s, sizeof(struct student), 1, fp)) {
        printf("Número de matrícula: %d\n", read_s.id);
        printf("Promedio: %.2f\n", read_s.average);
        printf("\n");
    }

    fclose(fp);

    return 0;
}
