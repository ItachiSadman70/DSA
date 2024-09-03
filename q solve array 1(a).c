#include <stdio.h>
#include <string.h>
#define arrSize 10
char arr[arrSize][5] = {
  "BBBB",
  "DDDD",
  "MMMM",
  "XXXX"
};

void insertIntoArrayAsc(char data[5]) {
  // finding the correct index to insert data
  int index = 0;
  while ((index < arrSize) && (strcmp(arr[index], data) < 0) && (strcmp(arr[index], data) > -2)) {
    index++;
  }
  // inserting data into the correct index
  // moving elements to create space for data
  for (int i = arrSize - 1; i > index; i--) {
    strcpy(arr[i], arr[i - 1]);
  }
  // inserting data into index
  strcpy(arr[index], data);
}

void deleteItem(char data[5]) {
  // get index to delete from
  int index = 0;
  while ((index < arrSize) && (strcmp(arr[index], data) != 0)) {
    index++;
  }
  if (index == 10) {
    printf("%s not found in array!\n\n", data);
    return;
  }
  // moving elements to delete space for data
  for (int i = index; i < arrSize - 1; i++) {
    strcpy(arr[i], arr[i + 1]);
  }
  strcpy(arr[arrSize - 1], "");
}

void displayArr() {
  // printing array elements
  printf("Array elements:\n");
  for (int i = 0; i < arrSize; i++) {
    printf("Index: %d\tElement: %s\n", i, arr[i]);
  }
  printf("\n");
}

int main() {
  printf("Initializing array:\n");
  displayArr();

  printf("Inserting elements:\n");
  insertIntoArrayAsc("AAAA");
  insertIntoArrayAsc("FFFF");
  insertIntoArrayAsc("ZZZZ");
  displayArr();

  printf("Deleting elements:\n");
  deleteItem("MM");
  displayArr();
  return 0;
}

