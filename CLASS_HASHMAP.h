#include <bits/stdc++.h>
 using namespace std;

 template<typename v>
 class MapNode{
public:
string key;
v value;

MapNode*next;
MapNode(string key, v value){
    this->key=key;
    this->value=value;
    next=NULL;

}
~MapNode(){
    delete next;
}

 };
 template<typename v>
 class ourMAp{
     
MapNode<v>** buckets;
int size;
int count;
int numBuckets;
public:
ourMAp(){
    count=0;
    numBuckets=5;
    buckets=new MapNode<v>*[numBuckets];
    for(int i=0;i<numBuckets;i++){
        buckets[i]=NULL;
    }
}
~ourMAp(){
    for(int i=0;i<numBuckets;i++){
        delete buckets[i];
    }
    delete [] buckets;

}
int getsize(){
    return count;
}
double getloadfactor(){
return (1.0*count)/numBuckets;
}
v getvalue(string key){
int bucketIndex=getBucketIndex( key);
MapNode<v>*head=buckets[bucketIndex];
while(head!=NULL){
if(head->key==key){
    return head->value;
}

    head=head->next;
}
return 0;
}

void insert(string key,v value){
int bucketIndex=getBucketIndex( key);
MapNode<v>*head=buckets[bucketIndex];
while(head!=NULL){
    if(head->key==key){
        head->value=value;
        return;
    }
    head=head->next;
}
MapNode<v>* node=new MapNode<v>( key, value);
node->next=head;
buckets[bucketIndex]=node;
count++;
// LOAD FACTOR CHECKING
double loadfactor=(1.0*count)/numBuckets;
if(loadfactor>0.7){
    rehash();
}


}
v remove(string key){
    
int bucketIndex=getBucketIndex( key);
MapNode<v>*head=buckets[bucketIndex];
MapNode<v>* prev=NULL;

while(head!=NULL){
    if(head->key==key){
        if(prev!=NULL){
            prev->next=head->next;
        }
        else{
            buckets[bucketIndex]=head->next;
        }
        v value=head->value;
        head->next=NULL;
        delete head;
        return value;
    }
prev=head;
head=head->next;

}
return 0;
}
private:
int getBucketIndex(string key){
    int hashcode=0;
    int currentcoefficent=1;

for(int i=key.length()-1;i>=0;i--){
    hashcode+=key[i]*currentcoefficent;
    hashcode=hashcode%numBuckets;
    currentcoefficent*=37;
    currentcoefficent=currentcoefficent%numBuckets;
}
return hashcode%numBuckets;

}
void rehash(){
    MapNode<v>** temp=buckets;
buckets=new MapNode<v>*[2*numBuckets];
for(int i=0;i<2*numBuckets;i++){
    buckets[i]=NULL;
}
int oldbucketcount=numBuckets;
numBuckets *=2;
count =0;
 
for(int i=0;i<oldbucketcount;i++){
MapNode<v>*head=temp[i];
while (head!=NULL)
{
    string key=head->key;
    v value=head->value;
    insert(key,value);//INSERT WILL BE MADE IN NEW BUCKET 
    head=head->next;
}



} 
for(int i=0;i<oldbucketcount;i++){
MapNode<v>*head=temp[i];
delete head;
}
delete [] temp;

}

 };