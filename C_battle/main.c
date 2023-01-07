#include<stdio.h>
#include<stdlib.h>
#include <time.h>
/*

typedef struct weapon {
    char name[100];
    int power;
}Weapon;

typedef struct player {
    char name[100];
    int hp;
    int power;
    Weapon* w;
}Player;

void showPlayer(Player* p) {
    int i, val;

    printf("%s : %d(%d) 무기 : %s(%d) \n", p->name, p->hp, p->power, p->w->name, p->w->power);
    val = p->hp / 10;
    for (i = 0; i < val; i++) {
        printf("■");
    }
    printf("\n");
}

//p가 total power로 target을 공격한다
void attack(Player* p, Player* target) {

    printf("%s가 %s를 공격합니다. \n", p->name, target->name);
    target->hp -= (p->power + p->w->power);
    printf("     %s의 무기는 %s! 악!     %s hp => %d  \n", p->name, p->w->name, target->name, target->hp);

}
int main() {

    Player p1 = { "토르",100,20 };
    Player p2 = { "짱구",100,10 };
    Weapon w1 = { "망치", 10 };
    Weapon w2 = { "돌멩이", 5 };
    Player* p, * target;

    p1.w = &w2;
    p2.w = &w1;

    showPlayer(&p1);
    showPlayer(&p2);

    srand((unsigned)time(NULL));
    //1:1 돌아가며 때리기. 한놈이 죽을 때까지

    printf("battle start! \n\n");
    while (1) {

        if (p1.hp <= 0 || p2.hp <= 0) break;
        //아래와 같이 한방씩 돌아가며 때리는 방식은 처음 공격한 player가 이길 확률이 높음

         // attack(&p1,&p2);
         // showPlayer(&p2);

         // attack(&p2,&p1);
         // showPlayer(&p1);


        //랜덤공격 짝수면 p1->p2, 홀수면 p2->p1 
        if (rand() % 2 == 0) {
            p = &p1;
            target = &p2;
        }
        else {
            p = &p2;
            target = &p1;
        }
        attack(p, target);
        showPlayer(target);
    }

    if (p1.hp <= 0) printf("%s Win! \n", p2.name);
    else printf("%s Win! \n", p1.name);

}
*/