#include <iostream>
#include <fstream>
#include "heap.hpp"
#include <cmath>
using namespace std;

void addFile(PriorityQueue &PQ){
    ifstream my_file;
    string part;
    string line;
    my_file.open("memes.txt");//open file
    if(!my_file.is_open()){
        cout << "Failed to open the file." << endl;//if can't open
    }
    else{
        int count = 0;
        string url;
        int upvote, Time;
        string title;
        int counter = 0;
        while(getline(my_file, line)){//read in the lines
            if(counter == 0){//first line is the title of a meme
                title = line;
                counter++;
            }
            else if(counter == 1){//second line is its URL
                url = line;
                counter++;
            }
            else if(counter == 2){//third line is its number of upvotes
                upvote = stoi(line);
                counter++;
            }
            else{
                Time = stoi(line);//last line in set of four is the time=
                PQ.enqueue(title, (100 * round(upvote/100.0)), Time, url);//enqueue with upvotes 
                //rounded to nearest hundreth
                counter = 0;//next line is start of new meme
            }
        }
    }
}
int main(){
    PriorityQueue PQ;//open queue
    addFile(PQ);
    const char *path="C:\\Users\\Max\\OneDrive\\ds-project\\public\\memes.html";//wrtie the file here
    ofstream file(path);//create file object with correct path
    //file.open("memes.html");//open the file
    
    if(file.is_open()){
        cout << "file is open" << endl;
        file << "<!DOCTYPE html>\n <html>\n <body>\n";

        while(!PQ.isEmpty()){//write the meme's info to file
            meme p = PQ.peek();
            file << "<h2>" << p.Title << "</h2>\n";
            cout<<p.Title<<endl;
            file << "<img src=\"" << p.URL << "\" alt=\"MEME\">\n";
            cout<<p.URL<<endl;
            PQ.dequeue();//dequeue the meme and move on to next one 
        }

        file << "</body>\n </html>";
        file.close();
    }
    else{
        cout << "could not open file" << endl;
    }

}