#include<stdio.h>
#include<stdlib.h>
#include <time.h>


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

    printf("    %s        %d      %d      %s      %d    ", p->name, p->hp, p->power, p->w->name, p->w->power);
    val = p->hp / 10;
    for (i = 0; i < val; i++) {
        printf("��");
    }
    printf("\n");
}

void showPlayer2(Player* target) {
    int i, val;

    printf("  %s hp => %d  ", target->name, target->hp);
    val = target->hp / 10;
    for (i = 0; i < val; i++) {
        printf("��");
    }
    printf("\n");
}

void changeName(Player* p, Player* target) {
    strcpy(p->name, "û��");
    strcpy(target->name, "����");
}

//p�� total power�� target�� �����Ѵ�
void attack(Player* p, Player* target) {

    printf("  %s�� [%d]�� ü�°� [%d]�� ������ ���� %s(%d)�� �Ἥ %s�� �����մϴ�. \n", p->name, p->hp, p->power, p->w->name, p->w->power, target->name);
    target->hp -= (p->power + p->w->power);

}

int main() {

    int num;

    //�÷��̾� 4��
    Player p1 = { "�丣",105,20 };
    Player p2 = { "¯��",110,10 };
    Player p3 = { "�Ѹ�",100,15 };
    Player p4 = { "����", 120, 5 };

    //���� 4����
    Weapon w1 = { "����", 5 };
    Weapon w2 = { "��ġ", 7 };
    Weapon w3 = { "ȭ��", 9 };
    Weapon w4 = { "����",12 };

    Player* p, * target;

    p1.w = &w1;
    p2.w = &w2;
    p3.w = &w3;
    p4.w = &w4;

    printf("---------------------------------------------------------------\n");
    printf("  �÷��̾�  /  ü��  /  �Ŀ�  /  ����  /  ���ط�  /  hp������\n");
    printf("  -----------------------------------------------------------  \n");
    showPlayer(&p1);
    showPlayer(&p2);
    showPlayer(&p3);
    showPlayer(&p4);
    printf("---------------------------------------------------------------\n");

    //����ڰ� �÷��̾ �����Ѵ�.
    printf("�÷��̾ �����ϼ���! �ºٰ� �� ���� �����Դϴ�!\n");
    printf("1.�丣  2.¯��  3.�Ѹ�  4.����\n");
    printf("����: ");
    scanf("%d", &num);
    
    switch (num) {
    case 1: p = &p1;
    case 2: p = &p2;
    case 3: p = &p3;
    case 4: p = &p4;
    }

    //���� ������ 1�� �ڸ� ���� ���� ��밡 �����ȴ�.
    srand((unsigned)time(NULL));
    
    //���� ������ 1�� �ڸ� ����...
    if (rand() % 10 == 0 || rand() % 10 == 1 || rand() % 10 == 2) target = &p1; // 0 �Ǵ� 1 �Ǵ� 2 �̸� �丣
    else if (rand() % 10 == 3 || rand() % 10 == 4) target = &p2;                // 3 �Ǵ� 4 �̸� ¯��
    else if (rand() % 10 == 5 || rand() % 10 == 6) target = &p3;                // 5 �Ǵ� 6 �̸� �Ѹ�
    else target = &p2;                                                          // 7 �Ǵ� 8 �Ǵ� 9 �̸� ����

    printf("\n����... %s�� �������� !!\n\n", target->name);

    //���� �������� �ºٰ� �Ǹ� û���� �������� �̸��� �ٲ㼭 �����Ѵ�.
    if (p->name == target->name) {

        printf("%s ���������� �ο��̱�.. û���� �������� ������ !\n");

        changeName(p, target);
    }

    //��Ʋ�� �����Ѵ�.
    printf("battle start! \n\n");
    while (1) {

        //���� ���ڰ� ¦���̸� �÷��̾ Ÿ���� �����Ѵ�.
        if (rand() % 2 == 0) {
            attack(p, target);
            showPlayer2(target);
        }
        //���� ���ڰ� Ȧ���̸� Ÿ���� �÷��̾ �����Ѵ�.
        else {
            attack(target, p);
            showPlayer2(p);
        }

        printf("\n");

        //�÷��̾�� Ÿ�� �� �� ���� ü���� 0 ���ϰ� �Ǹ� ��Ʋ�� �����Ѵ�.
        if (p->hp <= 0 || target->hp <= 0) break;
    }

    //���� �̰���� ����ϰ� ���α׷��� �����Ѵ�.
    if (p->hp <= 0) printf("%s Win! \n", target->name);
    else printf("%s Win! \n", p->name);
    
    return 0;
}