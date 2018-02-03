#include <stdio.h>

void Push(int data, int * queue);
void Pop(int * queue);
void Size(int * queue);
void Empty(int * queue);
void Front(int * queue);
void Back(int * queue);
void Command(char * command, int * queue, int data);
//문자열 비교
int strcmp(const char* text1, const char* text2);
int strcmp(const char* text1, const char* text2)
{
   int cmp = 0;
   int i = 0;
   while (text1[i])
   {
      if (*(text1 + i) == '\0')
      {
         if (*(text2 + i) == '\0')
            return cmp;
         else
            return -1;
      }
      else
      {
         if (*(text2 + i) == '\0')
            return -1;
         else
         {
            if (*(text1 + i) == *(text2 + i))
               cmp = 0;
            else
               return -1;
         }
      }
      i++;
   }
}

int main(void)
{
   int tc = 0;
   int queue[1000] = { 0, };
   char input[6] = { 0, };
   int output = 0;
   char * command;
   int data = 0;

   command = input;

   scanf("%d", &tc);
   for (int i = 0; i < tc; i++)
   {
      scanf("%s", command);
      if(strcmp(command, "push") == 0)
         scanf("%d", &data);
      Command(command, queue, data);
   }
   return 0;
}

void Command(char * command, int * queue, int data)
{
   char cmd[6][6] = {
      { "push" },
      { "pop" },
      { "size" },
      { "empty" },
      { "front" },
      { "back" } };
   int function = 0;

   for (int i = 0; i < 6; i++)
   {
      if (strcmp(command, cmd[i]) == 0)
         function = i;
   }
   switch (function)
   {
   case 0 :
      Push(data, queue);
      break;
   case 1:
      Pop(queue);
      break;
   case 2:
      Size(queue);
      break;
   case 3:
      Empty(queue);
      break;
   case 4:
      Front(queue);
      break;
   case 5:
      Back(queue);
      break;
   default:
      break;
   }
}

void Push(int data, int * queue)
{
   int index = 0;
   while (*(queue + index) != 0)
      index++;
   *(queue + index) = data;
}

void Pop(int * queue)
{
   int index = 0;

   if (*(queue + index) != 0)
      printf("%d\n", *(queue + index));
   else
      printf("%d\n", -1);
   //큐 pop
   *(queue + index) = 0;
   index++;
   //큐 정리
   do
   {
      if (*(queue + index) != 0)
      {
         *(queue + (index - 1)) = *(queue + index);
         *(queue + index) = 0;
      }
      index++;
   } while (*(queue + index) != 0);
}

void Size(int * queue)
{
   int index = 0;
   while (*(queue + index) != 0)
      index++;
   printf("%d\n", index);
}

void Empty(int * queue)
{
   int index = 0;
   while (*(queue + index) != 0)
      index++;
   printf("%d\n", index > 0 ? 0 : 1);
}

void Front(int * queue)
{
   int index = 0;
   if(*(queue + index) != 0)
      printf("%d\n", *(queue + index));
   else
      printf("%d\n", -1);
}

void Back(int * queue)
{
   int index = 0;
   while (*(queue + index) != 0)
      index++;
   if (index != 0)
      printf("%d\n", *(queue + (index - 1)));
   else
      printf("%d\n", -1);
}
