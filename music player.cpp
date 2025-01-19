#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    
    string Name;
    string Artist;
    string Genre;
    int Duration;
    
    Node* next;
    Node* prev;
};

Node* start = NULL;

void swap(Node* n1,Node* n2){
    
    if(n1==NULL || n2==NULL || n1==n2) return;
    
    //"prev" part
    if(n1->prev!=NULL){
        n1->prev->next = n2;
    }else {
        start=n2;
    }
    
    if(n2->prev!=NULL){
        n2->prev->next = n1;
    }else {
        start=n1;
    }
    
    Node* temp;
    temp=n1->prev;
    n1->prev=n2->prev;
    n2->prev=temp;
    
    //"next" part
    if(n1->next!=NULL){
        n1->next->prev=n2;
    }
    
    if(n2->next!=NULL){
        n2->next->prev=n1;
    }
    
    Node* temp2;
    temp2=n1->next;
    n1->next=n2->next;
    n2->next=temp2;
    
}

void AddSong(){
    
    
    string Name;
    string Artist;
    string Genre;
    int Duration;

    cout << "Song name: ";
    cin>>Name;
    cout << "Artist name: ";
    cin>>Artist;
    cout << "Duration (in minutes): ";
    cin >> Duration;
    cout << "Genre: ";
    cin>>Genre;    
    
    Node* newnode;
    Node* p;
    newnode = new (Node);
    newnode->Name = Name;
    newnode->Artist = Artist;
    newnode->Genre = Genre;
    newnode->Duration = Duration;
    newnode->next = NULL;
    newnode->prev =NULL;
    
    if (start == NULL) { 
            start = newnode;
        }else{
        
            p =start;
            while(p->next!= NULL) {
                p=p->next;
            }
            
            newnode->prev = p;
            p->next = newnode ;
        }
    
}

void MakePlaylist(){
    
    int n;
    cout << "Enter the number of songs: ";
    cin >> n;
    

    for (int i = 0; i < n; i++) {
        
        string Name;
        string Artist;
        string Genre;
        int Duration;

        cout << "\nEnter details for song " << i + 1 << ":\n";
        cout << "Song name: ";
        cin>>Name;
        cout << "Artist name: ";
        cin>>Artist;
        cout << "Duration (in minutes): ";
        cin >> Duration;
        cout << "Genre: ";
        cin>>Genre;

        //AddSong(Name, Artist, Genre, Duration);
        //instead of function
        
        Node* newnode;
        Node* p;
        newnode = new Node;
        newnode->Name = Name;
        newnode->Artist = Artist;
        newnode->Genre = Genre;
        newnode->Duration = Duration;
        newnode->next = NULL;
        newnode->prev =NULL;
        
        if (start == NULL) { 
            start = newnode;
        }else{
        
            p =start;
            while(p->next!= NULL) {
                p=p->next;
            }
            
            newnode->prev = p;
            p->next = newnode ;
        }
        
    }
}

void DisplaySongs(){
    Node* p;
    p=start;
    int i=1;
    while(p!=NULL){
        cout<<endl<<i<<endl;
        cout<<"name: ";
        cout<<p->Name<<endl;
        cout<<"artist: ";
        cout<<p->Artist<<endl;
        cout<<"genre: ";
        cout<<p->Genre<<endl;
        cout<<"duration: ";
        cout<<p->Duration<<endl;
        
        p=p->next;
        i++;
    }
}

void DeleteSong() {
    int choice;
    cout<<"\nby what parameter do you want to Delete?\n";
    cout<<"1. by Name\n";
    cout<<"2. by Artist\n";
    cout<<"3. by Genre\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    
    switch(choice){
        
        case 1:{
            string n;
            
            cout<<"\nEnter name you want to Delete :";
            
            cin>> n;
            Node* p;
            p=start;
            
            while(p)
            {
                if(p->Name==n){
                    
                    if (start == p)
                    start = p->next;
                    
                    if(p->prev!=NULL)
                    p->prev->next=p->next;
                    if(p->next!=NULL)
                    p->next->prev=p->prev;
                    
                    delete p;
                    
                }
                p=p->next;
            }
            
            cout<<"\ndeletion done.\n";
            break;
            
        }
        
        case 2:{
            string a;
            
            cout<<"\nEnter Artist you want to Delete :";
            
            cin>> a;
            Node* p;
            p=start;
            
            while(p)
            {
                if(p->Artist==a){
                    
                    if (start == p)
                    start = p->next;
                    
                    if(p->prev!=NULL)
                    p->prev->next=p->next;
                    if(p->next!=NULL)
                    p->next->prev=p->prev;
                    
                    delete p;
                    
                }
                p=p->next;
            }
            cout<<"\ndeletion done.\n";
            break;
            
        }
        
        case 3:{
            string g;
            
            cout<<"\nEnter the Genre you want to Delete :";
            
            cin>> g;
            Node* p;
            p=start;
            
            while(p)
            {
                if(p->Genre==g){
                    
                    if (start == p)
                    start = p->next;
                    
                    if(p->prev!=NULL)
                    p->prev->next=p->next;
                    if(p->next!=NULL)
                    p->next->prev=p->prev;
                    
                    //delete p;
                    
                }
                p=p->next;
            }
            
            cout<<"\ndeletion done.\n";
            break;
            
        }
        
    }
}

void DeleteDuplicates() {
    Node* p;
    Node* q;
    p=start;
    q=start->next;
    
    for(;p!=NULL;p=p->next){
        q=p->next;
        for(;q!=NULL;q=q->next){
            
            if(p->Name==q->Name && p->Artist==q->Artist){
                
                if(q->prev!=NULL)
                    q->prev->next=q->next;
                    if(q->next!=NULL)
                    q->next->prev=q->prev;
            }
        }
    }
    cout<<"\ndeleting duplicates done. \n";
    
}

void Search() {
    int choice;
    cout<<"\nEnter what you want to Search?\n";
    cout<<"1. by Name\n";
    cout<<"2. by Artist\n";
    cout<<"3. by Genre\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    
    switch(choice){
        case 1:{
            string s;
            cout<<"\nEnter the name: ";
            cin>>s;
            Node* p;
            p=start;
            
            while(p){
                if(p->Name==s){
                    cout<<"name: ";
                    cout<<p->Name<<endl;
                    cout<<"artist: ";
                    cout<<p->Artist<<endl;
                    cout<<"genre: ";
                    cout<<p->Genre<<endl;
                    cout<<"duration: ";
                    cout<<p->Duration<<endl;
                    
                }
                p=p->next;
            }
            break;
        }
        
        case 2:{
            string s;
            cout<<"\nEnter the Artist: ";
            cin>>s;
            Node* p;
            p=start;
            
            while(p){
                if(p->Artist==s){
                    cout<<"name: ";
                    cout<<p->Name<<endl;
                    cout<<"artist: ";
                    cout<<p->Artist<<endl;
                    cout<<"genre: ";
                    cout<<p->Genre<<endl;
                    cout<<"duration: ";
                    cout<<p->Duration<<endl;
                    
                   
                }
                p=p->next;
            }
            break;
        }
        
        case 3:{
            string s;
            cout<<"\nEnter the Genre: ";
            cin>>s;
            Node* p;
            p=start;
            
            while(p){
                if(p->Genre==s){
                    cout<<"name: ";
                    cout<<p->Name<<endl;
                    cout<<"artist: ";
                    cout<<p->Artist<<endl;
                    cout<<"genre: ";
                    cout<<p->Genre<<endl;
                    cout<<"duration: ";
                    cout<<p->Duration<<endl;
                    
                    
                }
                p=p->next;
            }
            break;
        }
    }
    
}

void Sort() {
    int choice;
    cout<<"\nEnter by what you want to sort?\n";
    cout<<"1. by Name\n";
    cout<<"2. by Artist\n";
    cout<<"3. by Genre\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    
    switch(choice){
        case 1:{
            string s;
            cout<<"\nEnter the name: ";
            cin>>s;
            
            Node* p;
            Node* q;
            p=start;
            q=start;
            
            while(p){
                if(p->Name==s){
                    
                    swap(p,q);
                    if(q->next!=NULL)
                    q=q->next;
                    p=q;
                }
                p=p->next;
            }
            break;
            
        }
        case 2:{
            string s;
            cout<<"\nEnter the Artist: ";
            cin>>s;
            
            Node* p;
            Node* q;
            p=start;
            q=start;
            
            while(p){
                if(p->Artist==s){
                    
                    swap(p,q);
                    if(q->next!=NULL)
                    q=q->next;
                    p=q;
                }
                p=p->next;
            }
            break;
        }
        case 3:{
            string s;
            cout<<"\nEnter the Genre: ";
            cin>>s;
            
            Node* p;
            Node* q;
            p=start;
            q=start;
            
            while(p){
                if(p->Genre==s){
                    
                    swap(p,q);
                    if(q->next!=NULL)
                    q=q->next;
                    p=q;
                }
                p=p->next;
            }
            break;
        }
    }
}


void move(){
    int choice;
    int number;
    cout<<"\nwhich song you want to move?(enter its number): ";
    cin>>number;
    cout<<"\nmove up or move down?\n";
    cout<<"1. move up\n";
    cout<<"2. move down\n";
    cin>>choice;
    
    switch(choice){
        case 1:{
            
            Node* p;
            Node* q;
            p=start;
            q=start->next;
            
            if(number==1){
                cout<<"your song is already at toppest level.";
                    break;
            }
            
            for(int i=0;i<number-2;i++){
                p=p->next;
                
                if(q->next!=NULL){
                    q=q->next;
                }
                else{
                    cout<<"your song is already at toppest level.";
                    break;
                }
            }
            
            swap(p,q);
            
            break;
        }
        case 2:{
            Node* p;
            Node* q;
            p=start;
            q=start->next;
            
            for(int i=0;i<number-1;i++){
                p=p->next;
                
                if(q->next!=NULL){
                    q=q->next;
                }
                else{
                    cout<<"your song is already at lowest level.";
                    break;
                }
            }
            
            swap(p,q);
            
            break;
        }
    }
}

void RandomPlay(){
    
    srand(time(0));
    Node* p;
    Node* q;
    p=start;
    q=start->next;
    
    for(;p!=NULL;p=p->next){
        q=p->next;
        for(;q!=NULL;q=q->next){
            
            if(rand()%2==0)
                swap(p,q);
        }
    }
    cout<<"\n\nsongs randomized!!\n\n";
}

int main()
{
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Make a Playlist\n";
        cout << "2. AddSong\n";
        cout << "3. Delete Song\n";
        cout << "4. Search \n";
        cout << "5. Sort \n";
        cout << "6. move up/down\n";
        cout << "7. display songs\n";
        cout << "8. Deleting duplicate songs\n";
        cout << "9. RandomPlay\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin  >> choice;
        
        
        switch(choice){
                
            case 1:{
                MakePlaylist();
                break;
            }
            case 2:{
                AddSong();
                break;
            }
            case 3:{
                DeleteSong();
                break;
            }
            case 4:{
                Search();
                break;
            }
            case 5:{
                Sort();
                break;
            }
            case 6:{
                move();
                break;
            }
            case 7:{
                DisplaySongs();
                break;
            }
            case 8:{
                DeleteDuplicates();
                break;
            }
            case 9:{
                RandomPlay();
                break;
            }
        } 
    }while(choice!=0);
    



    return 0;
}

