
#include<stdio.h>

struct Node {

    int value;
    Node *next;

    Node(int _value) {
        value = _value;
        next = NULL;
    }

    Node() {
        next = NULL;
    }

};

struct List {

    Node *start;
    Node *end;

    List() {
        start = NULL;
        end = NULL;
    }

    bool empty() {
        return start == NULL;
    }

    void pushBack(int value) {

        Node *n = new Node(value);

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        end->next = n;
        end = n;

    }

    void popFront() {

        if (empty()) return;

        if (start == end) {
            delete(start);
            start = NULL;
            end = NULL;
            return;
        }

        Node *aux = start;
        start = start->next;
        delete(aux);

    }

        void print() {
        Node *aux = start;
        while (aux != NULL) {
            printf("%d ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }

};

int main() {

    List a, b, c;
    int n, valor;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &valor);
        a.pushBack(valor);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &valor);
        b.pushBack(valor);
    }
    for(int i=0;i<n;i++){
        c.pushBack(a.start->value);
        c.pushBack(b.start->value);
        a.popFront();
        b.popFront();
    }

    c.print();

    return 0;
}
