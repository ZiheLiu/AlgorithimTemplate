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

void insert(char *str) {
    Node *cur_node = root;
    for(int i = 0; i < strlen(str); i++) {
        int index = str[i] - 'a';
        if (!(cur_node->next[index])) {
            Node *new_node = new Node;
            //memset(new_node, 0, sizeof(Node));
            cur_node->next[index] = new_node;
        }
        cur_node->value ++;
        cur_node = cur_node->next[index];
    }
    cur_node->value ++;
}

int search(char *str) {
    Node *cur_node = root;
    for(int i= 0;i < strlen(str); i++) {
        int index = str[i] - 'a';
        if (!(cur_node->next[index])) {
            return 0;
        }
        cur_node = cur_node->next[index];
    }
    return cur_node->value;
}

int main() {
    root = new Node;
   // memset(root, 0, sizeof(Node));

    char str[15];
    while(gets(str) && strlen(str)) {
        insert(str);
    }

    while(gets(str)) {
        printf("%d\n", search(str));
    }
    return 0;
}
