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

//μεθοδος ευρεσης μεγιστου
int FindMax(BtNode* rootPtr){

}

//μεθοδος ευρεσης ελαχιστου
//αυτο μπορει να γινει και με αναδρομη
int FindMin(BtNode* rootPtr){ //για να βρουμε το ελαχιστο πρεπει να διασχιζουμε το δεντρο συνεχεια αριστερα
    if(rootPtr == NULL){ //εαν το δεντρο ειναι αδειο, επεστρεψε αυτο το error
        cout << "Error: Tree is empty\n";
        return -1;
    }
    BtNode* current = rootPtr;
    while(current->left != NULL){ //οσο αριστερα υπαρχει κομβος
        current = current ->left; //αλλαξε τον pointer σε αυτον τον κομβο που βρεθηκε
    }
    return current->data;
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

//μεθοδος αναζητησης κομβων
bool Search(BtNode* rootPtr, int data){
    if(rootPtr == NULL) return  false;
    else if(rootPtr->data == data) return true; // εαν το στοιχειο αντιστοιχει στην θεση μνημης, επεστρεψε true
    else if(data <= rootPtr->data) return  Search(rootPtr->left,data); // εαν το στοιχειο ειναι μικροτερο απο το main στοιχειο, ψαξε το αριστερο παιδι
    else return Search(rootPtr->right,data); // αλλιως αν ειναι μεγαλυτερο, ψαξε το δεξι παιδι
}
int main() {
    BtNode* rootPtr; // pointer που δειχνει στην ρίζα του δεντρου
    rootPtr = NULL; //αρχικοποιουμαι το δεντρο στο κενο
    rootPtr = insert(rootPtr,  12);     rootPtr = insert(rootPtr,52);
    rootPtr = insert(rootPtr, 20);    rootPtr = insert(rootPtr,2);
    rootPtr = insert(rootPtr, 4);    rootPtr = insert(rootPtr, 100);
    rootPtr = insert(rootPtr, 10);    rootPtr = insert(rootPtr,245);
    rootPtr = insert(rootPtr, 5);    rootPtr = insert(rootPtr, 1205);



    int min = FindMin(rootPtr);
    cout<<"The minimum is: " << min<<endl;
    int  number;
    cout<<"Enter the number you want to search in the binary tree"<<endl;
    cin>>number;
    if(Search(rootPtr,number) == true) cout <<"found\n";
    else cout<<"Not found\n";
}