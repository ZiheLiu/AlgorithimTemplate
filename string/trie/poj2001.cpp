#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

// link: http://acm.hdu.edu.cn/showproblem.php?pid=1251
struct Node {
    int value;
    Node *next[26];

    Node() {
        value = 0;
        memset(next, NULL, sizeof(next));
    }
};
Node *root;
char strs[1002][22];

void insert(char *str) {
    Node *cur_node = root;
    for(int i = 0; i < strlen(str); i++) {
        int index = str[i] - 'a';
        if (!(cur_node->next[index])) {
            Node *new_node = new Node;
            cur_node->next[index] = new_node;
        }
        cur_node->value ++;
        cur_node = cur_node->next[index];
    }
    cur_node->value ++;
}

void search(char *str) {
    Node *cur_node = root;
    for(int i= 0;i < strlen(str); i++) {
        int index = str[i] - 'a';
        printf("%c", str[i]);
        if(cur_node->next[index]->value==1) {
            return ;
        }
        cur_node = cur_node->next[index];
    }
}

int main() {
    root = new Node;

    char str[22];
    int len = 0;
    while(scanf("%s", strs[len])!=EOF) {
        insert(strs[len]);
        ++ len;
    }
    for(int i = 0; i < len; i++) {
        printf("%s ", strs[i]);
        search(strs[i]);
        printf("\n");
    }
    return 0;
}
