#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct dic {
    char word_eng[20];
    char word_kor[20];
};

struct dic word[7][10] = {{{"apple","사과"},{"airplane","비행기"},{"afternoon","오후"},{"academy","학원"},{"attract","끌다"},{"attitude","태도"},{"attribute","속성"},{"axis","축"},{"awkward","어색한"},{"awaken","깨우다"}},
{{"banana","바나나"},{"basketball","농구"},{"box","박스"},{"bed","침대"},{"bar","바"},{"buy","사다"},{"bad","안좋은"},{"back","등"},{"break","깨지다"},{"burn","타다"}},
{{"cut","베다"},{"clear","확실한"},{"call","부르다"},{"catch","잡다"},{"cover","가리다"},{"charge","요금"},{"come","오다"},{"cast","던지다"},{"crown","왕관"},{"crack","갈라지다"}},
{{"draw","그리다"},{"drive","운전하다"},{"dead","죽은"},{"drop","떨어지다"},{"deep","깊은"},{"dry","마른"},{"date","날짜"},{"dump","버리다"},{"drag","끌다"},{"dark","어두운"}},
{{"easy","쉬운"},{"escape","달아나다"},{"express","나타내다"},{"exercise","운동"},{"end","끝"},{"eye","눈"},{"even","짝수"},{"east","동쪽"},{"evil","사악한"},{"exit","출구"}},
{{"free","자유로운"},{"force","물리력"},{"fly","날다"},{"fall","떨어지다"},{"flat","평평한"},{"fancy","원하다"},{"fit","맞다"},{"fix","고정시키다"},{"form","종류"},{"fine","좋은"}},
{{"go","가다"},{"get","받다"},{"good","좋은"},{"give","주다"},{"great","큰"},{"ground","바닥"},{"game","게임"},{"gaurd","경비"},{"green","녹색"},{"gather","모이다"}}};

void randomnumarr(int* arr);
int flashcard();
int game();

int main(void) {
    int menu;
    int end = 1;
    system("clear");
    while(end) {
        printf(">> 영어 단어 암기 프로그램 <<\n");
        printf("1. 플래쉬 카드\t2. 게임\t3. 프로그램 종료\n\n");
        printf("번호를 입력하세요 : ");
        scanf("%d",&menu);
        switch(menu) { 
            case 1:
                flashcard();
                continue;
            case 2:
                game();
                system("clear");
                continue;
            case 3:
                printf("프로그램을 종료합니다.\n");
                end = 0;
                system("clear");
                break;
            default :
                printf("1 2 3 중에 입력해주세요.\n");
                continue;
        }
    }
    return 0;
}

void randomnumarr (int *arr) {
    int i = 0;
    int j, temp, arrnum;
    while (i < 10) {
        arrnum = 0;
        temp = (rand() % 10);

        for (j = 0; j < i; j++) {
            if(arr[j] == temp)
            {
                arrnum = 1;
                break;
            }
        }

        if (arrnum == 0)
        {
            arr[i] = temp;
            i++;
        }
        else
            continue;
    }
}

int flashcard() {
    int day,print_mode;

    printf("학습 일차 : ");
    scanf("%d", &day);
    printf("출력방식(수동모드 : 1, 자동모드 : 2) : ");
    scanf("%d", &print_mode);
    getchar();
    system("clear");

    if (print_mode == 1) {
        int arr[10] = {0}; 
        randomnumarr(arr);
        for (int i = 0; i < 10; i++) {
            printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n\n\n\n");
            printf("%s", word[day-1][arr[i]].word_eng);
            getchar();
            system("clear");
            printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n\n\n\n");
            printf("%s", word[day-1][arr[i]].word_kor);
            getchar();
            system("clear");
        }
        return 0;
    }
    if (print_mode == 2){
        int arr[10] = {0};
        randomnumarr(arr);
        for (int i = 0; i < 10; i++) {
            printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n\n\n\n");
            printf("%s\n", word[day-1][arr[i]].word_eng);
            sleep(1);
            system("clear");
            printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n\n\n\n");
            printf("%s\n", word[day-1][arr[i]].word_kor);
            sleep(1);
            system("clear");
        }
        return 0;
    }
}

int game() {
    int day, random, fail = 0, try = 1;
    srand((unsigned)time(NULL));
    random = (rand() % 10);

    printf("학습 일차 : ");
    scanf("%d", &day);
    getchar();
    system("clear");
    
    int leg;
    leg = strlen(word[day-1][random].word_eng);
    char arr[20] = "";
    int cor[20] = {0};
    char wd;

    for (int i = 0; i < leg; i++)
        arr[i] = '_';

    while(1) {
        int count = 0,con = 0;
        printf(">> 영어 단어 암기 프로그램 : 게임 <<\n");
        printf("(힌트) %s\n\n", word[day-1][random].word_kor);

        switch(fail) {
            case 0:
                printf("-------------------+\n\n\n\n\n");
                break;
            case 1:
                printf("-------------------+\n");
                printf("               O\n\n\n\n");
                break;
            case 2:
                printf("-------------------+\n");
                printf("               O\n");
                printf("               |\n\n\n");
                break;
            case 3:
                printf("-------------------+\n");
                printf("               O\n");
                printf("              /|\n\n\n");
                break;
            case 4:
                printf("-------------------+\n");
                printf("               O\n");
                printf("              /|\\\n\n\n");
                break;
            case 5:
                printf("-------------------+\n");
                printf("               O\n");
                printf("              /|\\\n");
                printf("              /\n\n");
                break;
            case 6:
                printf("-------------------+\n");
                printf("               O\n");
                printf("              /|\\\n");
                printf("              / \\\n\n");
                printf("게임이 종료되었습니다.\n");
                sleep(1);
                return 0;
            default:
                printf("게임이 종료되었습니다.\n");
                return 0;
        }
        for (int i = 0; i < leg; i++)
            printf("%c", arr[i]); 
        printf("\n");
        printf("%d번째 시도 : ", try);
        wd = getchar();
        getchar();
        for (int i = 0; i < leg; i++) {
            if(word[day-1][random].word_eng[i] == wd) {
                arr[i] = wd;
                count++;
                if (cor[i] == 1) {
                    fail++;
                }
                cor[i] = 1;
            }
        }
        if(count == 0 ) {
            fail++;
        }
        for (int j = 0; j < leg; j++) {
            if(cor[j] == 1) {
                con++;
            }
        }
        if (con == leg) {
            printf("     #####################\n");
            printf("     ### Congratulations! ###\n");
            printf("     #####################\n");
            sleep(3); 
            /* 
            자동으로 전체 메뉴로 돌아가고 모든 실행결과는 클리어 후 출력 하기 때문에
            축하메세지를 보이고 3초 후에 클리어하게끔 만들었습니다.
            */
            return 0;
        }
        try++;
        system("clear");
    }
}