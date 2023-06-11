#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Error! Gagal Mengalokasikan Memori" << endl;
        return nullptr;
    }
    newNode->data = data;
    newNode->kiri = newNode->kanan = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return root;
    }
    queue<Node*> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node* temp = queue.front();
        queue.pop();
        if (temp->kiri != nullptr) {
            queue.push(temp->kiri);
        } else {
            temp->kiri = createNode(data);
            return root;
        }
        if (temp->kanan != nullptr) {
            queue.push(temp->kanan);
        } else {
            temp->kanan = createNode(data);
            return root;
        }
    }
    return root;
}

void cetakTree(Node* root, string indent, bool last) {
    if (root != nullptr) {
        cout << indent;
        if (last) {
            cout << "`-- ";
            indent += "    ";
        } else {
            cout << "|-- ";
            indent += "|   ";
        }
        cout << root->data << endl;
        cetakTree(root->kiri, indent, false);
        cetakTree(root->kanan, indent, true);
    }
}

void preOrder(Node* root, string indent, bool last) {
    if (root != nullptr) {
        cout << indent;
        if (last) {
            cout << "`-- ";
            indent += "    ";
        } else {
            cout << "|-- ";
            indent += "|   ";
        }
        cout << root->data << endl;
        preOrder(root->kiri, indent, false);
        preOrder(root->kanan, indent, true);
    }
}

void inOrder(Node* root, string indent, bool last) {
    if (root != nullptr) {
        inOrder(root->kiri, indent + "    ", false);
        cout << indent;
        if (last) {
            cout << "`-- ";
            indent += "    ";
        } else {
            cout << "|-- ";
            indent += "|   ";
        }
        cout << root->data << endl;
        inOrder(root->kanan, indent, true);
    }
}

void postOrder(Node* root, string indent, bool last) {
    if (root != nullptr) {
        postOrder(root->kiri, indent + "    ", false);
        postOrder(root->kanan, indent + "    ", false);
        cout << indent;
        if (last) {
            cout << "`-- ";
            indent += "    ";
        } else {
            cout << "|-- ";
            indent += "|   ";
        }
        cout << root->data << endl;
    }
}

void cetakNumbersPRE(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        cetakNumbersPRE(root->kiri);
        cetakNumbersPRE(root->kanan);
    }
}

void cetakNumbersIN(Node* root) {
    if (root != nullptr) {
        cetakNumbersIN(root->kiri);
        cout << root->data << " ";
        cetakNumbersIN(root->kanan);
    }
}

void cetakNumbersPOST(Node* root) {
    if (root != nullptr) {
        cetakNumbersPOST(root->kiri);
        cetakNumbersPOST(root->kanan);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;
    bool dataInserted = false;

    while (true) {
        cout << "MENU" << endl;
        cout << "----" << endl;
        cout << "1. Tambah" << endl;
        cout << "2. Lihat Pohon" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int count;
                cout << "Berapa jumlah angka yang ingin Anda masukkan? ";
                cin >> count;

                cout << "Masukkan angka: ";
                for (int i = 0; i < count; i++) {
                    int num;
                    cin >> num;
                    root = insertNode(root, num);
                }
                dataInserted = true;
                break;
            }
            case 2: {
                if (!dataInserted) {
                    cout << "DATA MASIH KOSONG" << endl << endl;
                    break;
                }

                cout << endl;
                cout << "Pohon:" << endl;
                cetakTree(root, "", true);
                cout << endl;

                cout << "Traversal Pohon (dalam pre-order, in-order, dan post-order):" << endl;
                cout << "-------------------------------------------------------------" << endl;

                cout << "Pre-order traversal: " << endl;
                preOrder(root, "", true);
                cout << endl;
                cout << "Bilangan: ";
                cetakNumbersPRE(root);
                cout << endl;
                cout << "-------------------------------------------------------------" << endl;

                cout << "In-order traversal: " << endl;
                inOrder(root, "", true);
                cout << endl;
                cout << "Bilangan: ";
                cetakNumbersIN(root);
                cout << endl;
                cout << "-------------------------------------------------------------" << endl;

                cout << "Post-order traversal: " << endl;
                postOrder(root, "", true);
                cout << endl;
                cout << "Bilangan: ";
                cetakNumbersPOST(root);
                cout << endl;
                cout << "-------------------------------------------------------------" << endl;

                break;
            }
            case 3:
                cout << "Terima kasih!" << endl;
                exit(0);
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
