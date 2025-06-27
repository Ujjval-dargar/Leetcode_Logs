struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        next = NULL;
        prev = NULL;
    }
};

class MyHashMap {
public:
    Node* head = NULL;

    MyHashMap() {}

    Node* check(int key) {
        Node* curr = head;
        while (curr != NULL) {
            if (curr->key == key)
                break;
            curr = curr->next;
        }

        return curr;
    }

    void put(int key, int value) {
        Node* curr = check(key);

        if (curr != NULL) {
            curr->val = value;
        } else {
            Node* nw = new Node(key, value);
            nw->next = head;
            if (head)
                head->prev = nw;
            head = nw;
        }
    }

    int get(int key) {

        Node* curr = check(key);

        if (curr != NULL) {
            return curr->val;
        }

        return -1;
    }

    void remove(int key) {
        Node* curr = check(key);

        if (curr != NULL) {

            Node* prev = curr->prev;
            Node* nxt = curr->next;

            if (prev) {
                prev->next = nxt;
                if (nxt)
                    nxt->prev = prev;
            } else {
                if (nxt) {
                    head = nxt;
                    nxt->prev = NULL;
                } else {
                    head = NULL;
                }
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */