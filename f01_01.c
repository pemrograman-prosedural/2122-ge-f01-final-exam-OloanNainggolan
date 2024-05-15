// 12S23001 - Kevin Gultom
// 12S23033 - Oloan Nainggolan
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/gender.h"

int main(int _argc, char **_argv){
  char x[100];
  int zdrm = 0;
  int size = 0;
  struct dorm_t *drm = malloc(size * sizeof(struct dorm_t));
  int std = 0;
  int sizee = 0;
  struct student_t *mhs = malloc(sizee * sizeof(struct student_t));
  char *token;

  while (1==1)
  {
    fgets(x, sizeof x, stdin);
    x[strlen(x) - 1] = '\0';
    token = strtok(x, "#");
    if (strcmp(token, "---") == 0)
    { break;
    } else if (strcmp(token, "dorm-add") == 0){
      size++;
      drm = realloc(drm, size * sizeof(struct dorm_t));
      drm[zdrm] = create_dorm(x);
      zdrm++;
    }else if (strcmp(token, "student-add") == 0)
    {
      sizee++;
      mhs = realloc(mhs, sizee * sizeof(struct student_t));
      mhs[std] = create_student(x);
      std++;
    }else if (strcmp(token, "student-print-all-detail") == 0)
    {
      for (int m = 0; m < std; m++)
      {
        print_student_detail(mhs[m]);
      }
    }else if (strcmp(token, "student-leave") == 0)
    {
      char *nim = strtok(NULL, "#");
      char *asrama = "left";
      leave_student(drm, mhs, nim, asrama, std, zdrm, find_id, find_dorm);
    }else if (strcmp(token, "assign-student") == 0)
    {
      char *nim = strtok(NULL, "#");
      char *asrama = strtok(NULL, "#");
      assign_student(drm, mhs, nim, asrama, std, zdrm, find_id, find_dorm);
    }
  }
  free(mhs);
  free(drm);

  return 0;
}