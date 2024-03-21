#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day {
 char* dayName;
 int date;
 char* activity;
};

struct Day* createCalendar()
{
 struct Day* calendar = (struct Day*)malloc(7 * sizeof(struct Day));
 for (int i = 0; i < 2; i++)
 {
 calendar[i].dayName = (char*)malloc(20 * sizeof(char)); 
 calendar[i].activity = (char*)malloc(100 * sizeof(char)); 
 }
 return calendar;
}


void readCalendarData(struct Day* calendar)
{
 for (int i = 0; i < 2; i++)
{
 printf("Enter the day name for Day %d: ", i + 1);
 scanf("%s", calendar[i].dayName);
 printf("Enter the date for Day %d: ", i + 1);
 scanf("%d", &calendar[i].date);
 printf("Enter the activity for Day %d: ", i + 1);
 scanf(" %[^\n]s", calendar[i].activity);
 }
}

void displayCalendar(struct Day* calendar)
{
 printf("Weekly Activity Report:\n\n");
 for (int i = 0; i < 2; i++)
{
 printf("Day %d: %s\n", i + 1, calendar[i].dayName);
 printf("Date: %d\n", calendar[i].date);
 printf("Activity: %s\n", calendar[i].activity);
 printf("\n");
 }
}
int main()
{
 struct Day* calendar = createCalendar();
 readCalendarData(calendar);
 displayCalendar(calendar);


 
 // Free memory
 for (int i = 0; i < 7; i++)
{
 free(calendar[i].dayName);
 free(calendar[i].activity);
 }
    
 free(calendar);

 return 0;
}
