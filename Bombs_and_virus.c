#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------------------//
float probabilityBomb[4]; //вероятность уничтожения для бомб 1,3,5,7 соответственно
//----------------------------------------------------------------------------//
//Чтение данных из файла
//----------------------------------------------------------------------------//
void ReadConfig()
{
  FILE *file;
  file = fopen("config", "r");
  for(int i = 0; fscanf(file, "%f", &probabilityBomb[i]) != EOF; i++)
  {//Читает пока не кончиться файл
    printf("Читаю значение для %d калибра бомб:\n", i + 1);
    printf("%f\n", probabilityBomb[i]);
  }
}
//----------------------------------------------------------------------------//
//Рекурсивная функция подсчета вероятности уничтожения
//----------------------------------------------------------------------------//
float CalcProbility(int balance)
{
  float tempProbality;  //временное значение вероятности уничтожения

  if((balance - 7) >= 0)
  {//выбор бомбы исходя из остатка средств
    tempProbality += probabilityBomb[3];
    printf("7 ");
    tempProbality += CalcProbility(balance - 7);
  }
  else if ((balance - 5) >= 0)
  {
    tempProbality += probabilityBomb[2];
    printf("5 ");
    tempProbality += CalcProbility(balance - 5);
  }
  else if ((balance - 3) >= 0)
  {
    tempProbality += probabilityBomb[1];
    printf("3 ");
    tempProbality += CalcProbility(balance - 3);
  }
  else if (balance-- > 0)
  {
    tempProbality += probabilityBomb[0];
    printf("1 ");
    tempProbality += CalcProbility(balance--);
  }
  return tempProbality;
}
//----------------------------------------------------------------------------//
//Вход
//----------------------------------------------------------------------------//
int main ()
{
  int rub;
  ReadConfig(); //бюджет миротворческой акции
  printf("Введите сумма в рублях(не больше 1 200 000):\n");
  scanf("%d", &rub);
  printf("\n");
  printf("Бомбы:\n");

  float probabity;  //наибольшая вероятности уничтожения
  probabity = CalcProbility(rub);

  printf("\n");
  printf("Вероятность уничтожения: %10.2f\n", probabity);
}
