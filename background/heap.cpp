
#include "heap.hpp"
#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue(){
    currentQueueSize = 0;//start with no memes
    maxSize = 5;//start the array with size 5
    priorityQueue = new meme[maxSize];//declare the new array

}
PriorityQueue::~PriorityQueue(){
  delete[] priorityQueue;//free dynamic memory
}

int left(int i){return ((2*i)+1);}//left child begin at 0
int right(int i){return ((2*i) + 2);}//right child begin at 0
int parent(int i) { return (i)/2;}//parent with index start at 0
void swap(meme *x, meme *y){//swap the meme objects using pointers
    meme temp = *x;
    *x = *y;
    *y = temp;
}
void PriorityQueue::arrDouble(){//if we run out of space
  cout<<"doubling array from "<<maxSize<<" to "<<maxSize*2<<endl;

  meme *newArray = new meme[maxSize*2]; //create new array of double size

  //copy elements from old array
  for(int i=0; i<currentQueueSize; i++){
    newArray[i] = priorityQueue[i];
  }

  //delete old, smaller array
  delete[] priorityQueue;
  //old array becomes new, bigger array
  priorityQueue = newArray;
  //increase max size
  maxSize = maxSize*2;
}

void PriorityQueue::repairDownward(int nodeIndex){
    int l = left(nodeIndex);
    int r = right(nodeIndex);//store the variables
    int biggest = nodeIndex;

    if(l < currentQueueSize && (priorityQueue[l]).UpVotes > (priorityQueue[nodeIndex]).UpVotes)
        biggest = l;//left one has more UpVotes
    if(l < currentQueueSize && (priorityQueue[l]).UpVotes == (priorityQueue[nodeIndex]).UpVotes
    && (priorityQueue[l]).Time > (priorityQueue[nodeIndex]).Time)
        biggest = l;//size upvotes but the left has greater time (more recent)
    if(r < currentQueueSize && (priorityQueue[r]).UpVotes > (priorityQueue[biggest]).UpVotes)
        biggest = r;//the right has more upvotes
    if(r < currentQueueSize && (priorityQueue[r]).UpVotes == (priorityQueue[biggest]).UpVotes
    &&(priorityQueue[r]).Time > (priorityQueue[biggest]).Time)
        biggest = r;//size equal but the right has greater time (more recent)

    if(biggest != nodeIndex){//a child should become a parent
        swap(priorityQueue[nodeIndex], priorityQueue[biggest]);//switch the memes
        repairDownward(biggest);//recursive call
    }
}

void PriorityQueue::repairUpward(int nodeIndex){
    int sizeP = priorityQueue[parent(nodeIndex)].UpVotes;
    int sizeI = priorityQueue[nodeIndex].UpVotes;
    int CsizeP = priorityQueue[parent(nodeIndex)].Time;
    int CsizeI = priorityQueue[nodeIndex].Time;//store the variables we are going to compare

    bool stop = false;//to stop the loop while it's no longer needed
    while(nodeIndex != 0 && !stop){//until we get to the first one
        if(sizeP < sizeI){
            swap(priorityQueue[nodeIndex], priorityQueue[parent(nodeIndex)]);
            nodeIndex = parent(nodeIndex);//if the parent has a fewer upvotes
        }
        else if(sizeP == sizeI){//same upvotes
            while(nodeIndex != 0 && !stop){//loop through while same number of upvotes
                if(CsizeP < CsizeI && sizeP == sizeI){
                    swap(priorityQueue[nodeIndex], priorityQueue[parent(nodeIndex)]);
                    nodeIndex = parent(nodeIndex);//the size is the same but time needs swaping
                }
                else{
                    stop = true;//nothing else needs swaping
                }
                //update the variables
                sizeP = priorityQueue[parent(nodeIndex)].UpVotes;
                sizeI = priorityQueue[nodeIndex].UpVotes;
                CsizeP = priorityQueue[parent(nodeIndex)].Time;
                CsizeI = priorityQueue[nodeIndex].Time;
            }
        }
        else{
            stop = true;//nothing else needs swaping then
        }
        //update the variables
        sizeP = priorityQueue[parent(nodeIndex)].UpVotes;
        sizeI = priorityQueue[nodeIndex].UpVotes;
        CsizeP = priorityQueue[parent(nodeIndex)].Time;
        CsizeI = priorityQueue[nodeIndex].Time;
    }
}

void PriorityQueue::enqueue(std::string _Title, int _UpVotes, int _Time, std::string _URL){
    if(currentQueueSize == maxSize){
      arrDouble();//make sure we don't get seg fault
    }
    meme NewMeme;//new meme object
    currentQueueSize++;
    NewMeme.Time = _Time;
    NewMeme.Title = _Title;
    NewMeme.UpVotes = _UpVotes;
    NewMeme.URL = _URL;
    priorityQueue[currentQueueSize-1] = NewMeme;//set the value
    repairUpward(currentQueueSize-1);//re order from the one you inserted
}

void PriorityQueue::dequeue(){
    if(currentQueueSize == 0){
        cout << "Heap empty, cannot dequeue" << endl;//make sure its not empty
    }
    else{
        if(currentQueueSize == 1){
            currentQueueSize--;//if there is only one in there then just decrease the size

        }
        else{
            priorityQueue[0] = priorityQueue[currentQueueSize - 1];//put the last one first
            currentQueueSize--;//decrease the size
            repairDownward(0);//re order the vector
        }

    }
}

meme PriorityQueue::peek(){
    if(currentQueueSize == 0){
        cout << "Heap empty, nothing to peek" << endl;

    }
    return priorityQueue[0];//the one on top
}

bool PriorityQueue::isEmpty(){
    if(currentQueueSize == 0){
        return true;//if empty
    }
    else{
        return false;
    }
}