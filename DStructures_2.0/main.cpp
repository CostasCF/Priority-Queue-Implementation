#include <iostream>
using namespace std;

//δημιουργια binary tree
struct BtNode {
    int data; // μεταβλητη που περιεχει το στοιχειο του κομβου του δεντρου
    BtNode* left; // pointer που δειχνει στο αριστερο παιδι
    BtNode* right; // pointer που δειχνει στο δεξι παιδι
};

BtNode* getNewNode(int data){
    BtNode* newNode = new BtNode(); //δεσμευουμε την μνημη για το νεο στοιχειο που εισαγουμε
    //θα μπορουοσαμε να χρησιμοποιήσουμε και την malloc εδω περα πχ, BtNode* newNode = (BtNode*)malloc(sizeof(BtNode));
    newNode->data = data; //εισαγουμε στην νεα δεσμευμενη μνημη τα δεδομενα της παραμετρου data
    newNode->left = newNode->right = NULL;//οριζουμε δεξια και αριστερα την μνημη του στοιχειου στο κενο
    return newNode;
}


//μεθοδος ευρεσης μεγιστου
void deleteMax(BtNode* maxNode){

}

//αυτο μπορει να γινει και με αναδρομη
BtNode* findMax(BtNode* rootPtr){ //για να βρουμε το μεγιστο πρεπει να διασχιζουμε το δεντρο συνεχεια δεξια
    BtNode* current = rootPtr;
    if(rootPtr == NULL){ //εαν το δεντρο ειναι αδειο, επεστρεψε αυτο το error
        cout << "Error: Tree is empty\n";
        return  NULL;
    }

    BtNode* nextNode = current->right;
    BtNode* max;
    while(nextNode != NULL) { //οσο δεξια υπαρχει κομβος
        if (nextNode->data >= current->data) { //αν το επομενο δεξιο παιδι ειναι μεγαλυτερο του current
            max = nextNode; //ορισε για max το υποπαιδι
        }
        current = nextNode; //πηγαινε στο επομενα
        nextNode = nextNode->right; //αλλαξε τον pointer σε αυτον τον κομβο που βρεθηκε
    }
    return max ;
}

/*
 * Πρεπει να ελεγχουμε ολοκληρο το υποδεντρο με την ριζα του και επειτα να εφαρμοζουμε την random για να τα πεταει μερικα στα δεξια παιδιαψ
 * */
//μεθοδος για εισαγωγη κομβων στο δεντρο
BtNode* insert(BtNode* rootPtr, int data){
    if(rootPtr == NULL){
        rootPtr = getNewNode(data);
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
bool search(BtNode *rootPtr, int data){
    if(rootPtr == NULL) return  false;
    else if(rootPtr->data == data) return true; // εαν το στοιχειο αντιστοιχει στην θεση μνημης, επεστρεψε true
    else if(data <= rootPtr->data) return search(rootPtr->left, data); // εαν το στοιχειο ειναι μικροτερο απο το main στοιχειο, ψαξε το αριστερο παιδι
    else return search(rootPtr->right, data); // αλλιως αν ειναι μεγαλυτερο, ψαξε το δεξι παιδι
}


int main() {
    BtNode* rootPtr; // pointer που δειχνει στην ρίζα του δεντρου
    rootPtr = NULL; //αρχικοποιουμαι το δεντρο στο κενο
    rootPtr = insert(rootPtr,  12);     rootPtr = insert(rootPtr,52);
    rootPtr = insert(rootPtr, 20);    rootPtr = insert(rootPtr,2);
    rootPtr = insert(rootPtr, 4);    rootPtr = insert(rootPtr, 100);
    rootPtr = insert(rootPtr, 10);    rootPtr = insert(rootPtr,245);
    rootPtr = insert(rootPtr, 5);    rootPtr = insert(rootPtr, 2);



    BtNode* maxNode = findMax(rootPtr);
    deleteMax(maxNode);
    cout<<"The maximum is: " << maxNode->data<<endl;
    int  number;
    cout<<"Enter the number you want to search in the binary tree"<<endl;
    cin>>number;
    if(search(rootPtr, number) == true) cout <<"found\n";
    else cout<<"Not found\n";
}