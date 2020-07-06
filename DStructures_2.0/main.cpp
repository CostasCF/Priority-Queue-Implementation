#include <iostream>
using namespace std;

//δημιουργια binary tree
struct BtNode {
    int data; // μεταβλητη που περιεχει το στοιχειο του κομβου του δεντρου
    BtNode* left; // pointer που δειχνει στο αριστερο παιδι
    BtNode* right; // pointer που δειχνει στο δεξι παιδι
};

BtNode* GetNewNode(int data){
    BtNode* newNode = new BtNode(); //δεσμευουμε την μνημη για το νεο στοιχειο που εισαγουμε
    //θα μπορουοσαμε να χρησιμοποιήσουμε και την malloc εδω περα πχ, BtNode* newNode = (BtNode*)malloc(sizeof(BtNode));
    newNode->data = data; //εισαγουμε στην νεα δεσμευμενη μνημη τα δεδομενα της παραμετρου data
    newNode->left = newNode->right = NULL;//οριζουμε δεξια και αριστερα την μνημη του στοιχειου στο κενο
    return newNode;
}

//μεθοδος για εισαγωγη κομβων στο δεντρο
BtNode* insert(BtNode* rootPtr, int data) {
    if(rootPtr == NULL){
        rootPtr = GetNewNode(data);
    }
    else if(data <= rootPtr->data){
        rootPtr->left = insert(rootPtr->left,data); //δημιουργια αριστερου παιδιου
    }
    else{
        rootPtr->right = insert(rootPtr->right,data); //δημιουργια δεξιου παιδιου
    }
    return rootPtr;
}

bool Search(BtNode* rootPtr, int data){
    if(rootPtr == NULL) return  false;
    else if(rootPtr->data == data) return true; // εαν το στοιχειο αντιστοιχει στην θεση μνημης, επεστρεψε true
    else if(data <= rootPtr->data) return  Search(rootPtr->left,data); // εαν το στοιχειο ειναι μικροτερο απο το main στοιχειο, ψαξε το αριστερο παιδι
    else return Search(rootPtr->right,data); // αλλιως αν ειναι μεγαλυτερο, ψαξε το δεξι παιδι
}
int main() {
    BtNode* rootPtr; // pointer που δειχνει στην ρίζα του δεντρου
    rootPtr = NULL; //αρχικοποιουμαι το δεντρο στο κενο
    rootPtr = insert(rootPtr,  12);
    rootPtr = insert(rootPtr, 20);

    int  number;
    cout<<"Enter the number you want to search in the binary tree"<<endl;
    cin>>number;
    if(Search(rootPtr,number) == true) cout <<"found\n";
    else cout<<"Not found\n";
}