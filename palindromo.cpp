#include<stdio.h>
#include<string.h>

struct Node {

    char value;
    Node *next;

    Node(char _value) {
        value = _value;
        next = NULL;
    }

    Node() {
        next = NULL;
    }

};

struct Stack {

    Node *t;

    Stack() {
        t = NULL;
    }

    bool empty() {
        return t == NULL;
    }

    void push(char value) {
        Node *n = new Node(value);

        if (empty()) {
            t = n;
            return;
        }

        n->next = t;
        t = n;
    }

    void pop() {

        if (empty()) {
            return;
        }

        Node *aux = t;
        t = t->next;
        delete(aux);
    }

    char top() {
        return t->value;
    }

    void palindroma(int tam){
        Stack b,c;
        for(int i=0; i<tam;i++){
            b.push(top());
            c.push(top());
            pop();
        }
        for(int j=0; j<tam; j++){
            push(c.top());
            c.pop();
        }
        int correto = 0;
        while(!empty() && !b.empty()){
            if(top()==b.top()){
                correto++;
                pop();
                b.pop();
            }else{
                break;
            }
        }
        if(correto == tam){
            printf("1");
        }else{
            printf("0");
        }

    }

};

    int main() {
        Stack s;
        char p[100];
        int caracter, i=0;
        while((caracter = getchar()) != '\n'&& caracter != EOF && i < 99){
            if(caracter!=' '){
                p[i++] = (char)caracter;
            }
        }
        p[i] = '\0';
        for(int j=0; j<strlen(p); j++){
            s.push(p[j]);
        }
        s.palindroma(strlen(p));
        return 0;
}
