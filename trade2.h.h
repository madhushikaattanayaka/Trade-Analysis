/**
 * return the position of the key within the csv header
 * return -1 if the key is not found
 * @csv_header header of the csv file
 * @key the name of the field you are looking for
 */
int getFieldIndex(char *csv_head, char *key);

/** 
 * return the value of the ith field of the line 
 * works only with integer fields 
 * @line the line from which to extract the value 
 * @index of the field 
 * Can't fail unless the CSV file is miss formed or index is erroneous  
 */
int getFieldValue(char *line, int field);

/**
 * return the value of the ith field of the line
 * works only with strings 
 * @line the line from which to extract the value 
 * @index of the field
 * @results where results are to be placed 
 * return 1 if the field is found 0 otherwise  
 * Can't fail unless the CSV file is miss formed 
 */
void getFieldString(char *line, int filed, char *results);

int getFieldIndex(char *head, char *key)
{
  int i, j, count;
  for(i=0,j=0, count=0; head[i] != '\0' && key[j] != '\0'; i++) {
    if(head[i] == ',') count++;

    if(head[i] == key[j]) j++;
    else                  j=0;
  }

  if(key[j] == '\0') return count;
  else               return -1;
}

int getFieldValue(char *line, int field)
{
  char tmp[20];
  int i,j;
  for(i=0; line[i] != '\0' && field > 0; i++)
    if(line[i] == ',') field--;

  if(line[i] == '\0') return -1;

  for(j=0; line[i] != '\0' && line[i] != ','; j++, i++)
    tmp[j] = line[i];

  tmp[j] = '\0';
  return atoi(tmp);

}

void getFieldString(char *line, int field, char *res)
{
  int i,j;
  for(i=0; line[i] != '\0' && field > 0; i++)
    if(line[i] == ',') field --;

  if(line[i] == '\0') return;

  for(j=0; line[i] != '\0' && line[i] != ','; i++, j++)
    res[j] = line[i];

  res[j] = '\0';
  return;
}

//A.M.M.S.Attanayake