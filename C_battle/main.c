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

    printf("%s : %d(%d) ���� : %s(%d) \n", p->name, p->hp, p->power, p->w->name, p->w->power);
    val = p->hp / 10;
    for (i = 0; i < val; i++) {
        printf("��");
    }
    printf("\n");
}

//p�� total power�� target�� �����Ѵ�
void attack(Player* p, Player* target) {

    printf("%s�� %s�� �����մϴ�. \n", p->name, target->name);
    target->hp -= (p->power + p->w->power);
    printf("     %s�� ����� %s! ��!     %s hp => %d  \n", p->name, p->w->name, target->name, target->hp);

}
int main() {

    Player p1 = { "�丣",100,20 };
    Player p2 = { "¯��",100,10 };
    Weapon w1 = { "��ġ", 10 };
    Weapon w2 = { "������", 5 };
    Player* p, * target;

    p1.w = &w2;
    p2.w = &w1;

    showPlayer(&p1);
    showPlayer(&p2);

    srand((unsigned)time(NULL));
    //1:1 ���ư��� ������. �ѳ��� ���� ������

    printf("battle start! \n\n");
    while (1) {

        if (p1.hp <= 0 || p2.hp <= 0) break;
        //�Ʒ��� ���� �ѹ澿 ���ư��� ������ ����� ó�� ������ player�� �̱� Ȯ���� ����

         // attack(&p1,&p2);
         // showPlayer(&p2);

         // attack(&p2,&p1);
         // showPlayer(&p1);


        //�������� ¦���� p1->p2, Ȧ���� p2->p1 
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