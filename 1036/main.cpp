#include <cstdio>

struct node {
    char name[11];
    char gender;
    char id[11];
    int grade;


};

int main() {
    node lBoy, hGirl;
    lBoy.grade = 101;
    hGirl.grade = -1;
    int N;
    scanf("%d", &N);
    while (N--) {
        node tmp;
        tmp.grade = 0;

        scanf("%s %c %s %d", tmp.name, &tmp.gender, tmp.id, &tmp.grade);
        if (tmp.gender == 'M') {
            if (tmp.grade < lBoy.grade) {
                lBoy = tmp;
            }
        }
        else {
            if (tmp.grade > hGirl.grade) {
                hGirl = tmp;
            }
        }
    }
    if (lBoy.grade == 101) {
        if (hGirl.grade == -1) {//无男女
            printf("NA");

        }
        else {//无男
            printf("%s %s\nAbsent\nNA", hGirl.name, hGirl.id);
        }
    }
    else if (hGirl.grade == -1) {  //无女
        printf("Absent\n%s %s\nNA", lBoy.name, lBoy.id);
    }


    else { //正常
        printf("%s %s\n%s %s\n%d", hGirl.name, hGirl.id, lBoy.name, lBoy.id, hGirl.grade - lBoy.grade);

    }


    return 0;
}
