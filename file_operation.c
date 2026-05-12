int loadfile(StudentList *list, const char *filename)
 {
   if((filename = fopen(filename, "r")) ==NULL)
   {
      printf("Failed to open file for reading.\n");
      return -1;
   }
   fscanf(filename, "%d", &list->count);
   for(int i = 0; i < list->count; i++)
   {
      fscanf(filename, "%s %s %s %s %s", list->students[i].name, list->students[i].origin, list->students[i].phone1, list->students[i].phone2, list->students[i].email);
   }
 }


 int savefile(StudentList *list, const char *filename)
 {
   if((filename = fopen(filename, "w")) ==NULL)
   {
      printf("Failed to open file for writing.\n");
      return -1;
   }
   fprintf(filename, "%d\n", list->count);
   for(int i = 0; i < list->count; i++)
   {
      fprintf(filename, "%s %s %s %s %s\n", list->students[i].name, list->students[i].origin, list->students[i].phone1, list->students[i].phone2, list->students[i].email);
   }
 }
