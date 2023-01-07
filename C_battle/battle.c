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
        printf("■");
    }
    printf("\n");
}

void showPlayer2(Player* target) {
    int i, val;

    printf("  %s hp => %d  ", target->name, target->hp);
    val = target->hp / 10;
    for (i = 0; i < val; i++) {
        printf("■");
    }
    printf("\n");
}

void changeName(Player* p, Player* target) {
    strcpy(p->name, "청팀");
    strcpy(target->name, "백팀");
}

//p가 total power로 target을 공격한다
void attack(Player* p, Player* target) {

    printf("  %s가 [%d]의 체력과 [%d]의 힘으로 무기 %s(%d)를 써서 %s를 공격합니다. \n", p->name, p->hp, p->power, p->w->name, p->w->power, target->name);
    target->hp -= (p->power + p->w->power);

}

int main() {

    int num;

    //플레이어 4명
    Player p1 = { "토르",105,20 };
    Player p2 = { "짱구",110,10 };
    Player p3 = { "둘리",100,15 };
    Player p4 = { "포뇨", 120, 5 };

    //무기 4가지
    Weapon w1 = { "각목", 5 };
    Weapon w2 = { "망치", 7 };
    Weapon w3 = { "화살", 9 };
    Weapon w4 = { "권총",12 };

    Player* p, * target;

    p1.w = &w1;
    p2.w = &w2;
    p3.w = &w3;
    p4.w = &w4;

    printf("---------------------------------------------------------------\n");
    printf("  플레이어  /  체력  /  파워  /  무기  /  피해량  /  hp게이지\n");
    printf("  -----------------------------------------------------------  \n");
    showPlayer(&p1);
    showPlayer(&p2);
    showPlayer(&p3);
    showPlayer(&p4);
    printf("---------------------------------------------------------------\n");

    //사용자가 플레이어를 선택한다.
    printf("플레이어를 선택하세요! 맞붙게 될 상대는 랜덤입니다!\n");
    printf("1.토르  2.짱구  3.둘리  4.포뇨\n");
    printf("숫자: ");
    scanf("%d", &num);
    
    switch (num) {
    case 1: p = &p1;
    case 2: p = &p2;
    case 3: p = &p3;
    case 4: p = &p4;
    }

    //랜덤 숫자의 1의 자리 수에 따라 상대가 결정된다.
    srand((unsigned)time(NULL));
    
    //랜덤 숫자의 1의 자리 수가...
    if (rand() % 10 == 0 || rand() % 10 == 1 || rand() % 10 == 2) target = &p1; // 0 또는 1 또는 2 이면 토르
    else if (rand() % 10 == 3 || rand() % 10 == 4) target = &p2;                // 3 또는 4 이면 짱구
    else if (rand() % 10 == 5 || rand() % 10 == 6) target = &p3;                // 5 또는 6 이면 둘리
    else target = &p2;                                                          // 7 또는 8 또는 9 이면 포뇨

    printf("\n상대는... %s로 정해졌다 !!\n\n", target->name);

    //만약 동족끼리 맞붙게 되면 청팀과 백팀으로 이름을 바꿔서 경쟁한다.
    if (p->name == target->name) {

        printf("%s 동족끼리의 싸움이군.. 청팀과 백팀으로 나눈다 !\n");

        changeName(p, target);
    }

    //배틀을 시작한다.
    printf("battle start! \n\n");
    while (1) {

        //랜덤 숫자가 짝수이면 플레이어가 타깃을 공격한다.
        if (rand() % 2 == 0) {
            attack(p, target);
            showPlayer2(target);
        }
        //랜덤 숫자가 홀수이면 타깃이 플레이어를 공격한다.
        else {
            attack(target, p);
            showPlayer2(p);
        }

        printf("\n");

        //플레이어와 타깃 중 한 명의 체력이 0 이하가 되면 배틀을 종료한다.
        if (p->hp <= 0 || target->hp <= 0) break;
    }

    //누가 이겼는지 출력하고 프로그램을 종료한다.
    if (p->hp <= 0) printf("%s Win! \n", target->name);
    else printf("%s Win! \n", p->name);
    
    return 0;
}