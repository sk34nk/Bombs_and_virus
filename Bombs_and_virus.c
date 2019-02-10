#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------------------//
#define PROBABILITY_BOMB_ONE 3                                                  //вероятность уничтожения для бомбы (1,1)
#define PROBABILITY_BOMB_THREE 15.17                                            //вероятность уничтожения для бомбы (3,3)
#define PROBABILITY_BOMB_FIVE 39                                                //вероятность уничтожения для бомбы (5,5)
#define PROBABILITY_BOMB_SEVEN 73                                               //вероятность уничтожения для бомбы (7,7)
//----------------------------------------------------------------------------//
//Рекурсивная функция подсчета вероятности уничтожения
//----------------------------------------------------------------------------//
float calcProbility(int balance) {
  float tempProbality;                                                          //временное значение вероятности уничтожения

  if((balance - 7) >= 0){                                                       //выбор бомбы исходя из остатка средств
    tempProbality += PROBABILITY_BOMB_SEVEN;
    printf("7 ");
    tempProbality += calcProbility(balance - 7);
  }else if ((balance - 5) >= 0) {
    tempProbality += PROBABILITY_BOMB_FIVE;
    printf("5 ");
    tempProbality += calcProbility(balance - 5);
  }else if ((balance - 3) >= 0) {
    tempProbality += PROBABILITY_BOMB_THREE;
    printf("3 ");
    tempProbality += calcProbility(balance - 3);
  }else if (balance-- > 0) {
    tempProbality += PROBABILITY_BOMB_ONE;
    printf("1 ");
    tempProbality += calcProbility(balance--);
  }
  return tempProbality;
}
//----------------------------------------------------------------------------//
//Вход
//----------------------------------------------------------------------------//
int main (){
  int rub;                                                                      //бюджет миротворческой акции
  printf("Введите сумма в рублях(не больше 1 200 000):\n");
  scanf("%d", &rub);
  printf("\n");
  printf("Бомбы:\n");


  float probabity;                                                              //наибольшая вероятности уничтожения
  probabity = calcProbility(rub);

  printf("\n");
  printf("Вероятность уничтожения: %10.2f\n", probabity);
}
