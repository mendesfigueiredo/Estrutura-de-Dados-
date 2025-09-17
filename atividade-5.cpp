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
    int c;

    List() {
        start = NULL;
        end = NULL;
        c = 0;
    }

    bool empty() {
        return start == NULL;
    }

    void pushBack(int value) {

        Node *n = new Node(value);
        c++;

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        end->next = n;
        end = n;

    }

    void pushFront(int value) {

        Node *n = new Node(value);
        c++;

        if (empty()) {
            start = n;
            end = n;
            return;
        }

        n->next = start;
        start = n;

    }

    void print() {
        //printf("start: %d end: %d\n", start, end);
        Node *aux = start;
        while (aux != NULL) {
            //printf("[%d] %d [%d] -> ", aux, aux->value, aux->next);
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }

    // O(1)
    int size() {
        return c;
    }

    // O(1)
    void popFront() {

        if (empty()) return;

        c--;

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

    // O(n)
    void popBack() {

        if (empty()) return;

        c--;

        if (start == end) {
            delete(start);
            start = NULL;
            end = NULL;
            return;
        }

        Node *newEnd = start;
        while (newEnd->next != end) {
            newEnd = newEnd->next;
        }

        delete(end);
        end = newEnd;
        end->next = NULL;

    }
    
    void atv5(){
        if(size()<=1){
            printf("Lista e <=1, nao e possivel realizar!");
            return;
        }else{
            int value;
            scanf("%d", &value);
            Node *novo = new Node(value);
            c++;
            
            if(start->next == end){
                novo->next = end;
                start->next = novo;
                return;
            }
            
            Node *aux = start;
            while(aux->next != end){
                aux = aux->next;
                
            }
            
            novo->next = end;
            aux->next = novo;
        }
    }
};

int main() {
    List l;
    
    l.pushBack(10);
    l.pushBack(3);
    l.pushBack(5);
    l.pushBack(8);
    l.print();
    
    l.atv5();
    l.print();
    printf("\n");

    return 0;
}