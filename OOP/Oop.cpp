#include<iostream>
#include<list>
#include<vector>
using namespace std;

class YouTubeChannel{
    private:
        string name;
        string ownerName;
        int subscribersCount;
        list<string> videos;

    public:
        YouTubeChannel(string name, string ownerName){
            this -> name = name;
            this -> ownerName = ownerName;
            subscribersCount = 0;
        }

        void getInfo(){
            cout<<name<<endl;
            cout<<ownerName<<endl;
            cout<<subscribersCount<<endl;

            for(auto it: videos){
                cout<<it<<endl;
            } 
        } 

        void Subscribe(){
            subscribersCount++;
        }

        void unSubscribe(){
            if(subscribersCount > 0)
            subscribersCount--;
        }

        void publishVideo(string title){
            videos.push_back(title);
        }

        void getName(){
            cout<<name<<endl;
        }

        string setName(string name){
            return this -> name = name;
        }
};

int main(){
    // YouTubeChannel ytChannel;
    // ytChannel.name = "Take You Forward";
    // ytChannel.ownerName = "Striver";
    // ytChannel.subscribersCount = 100000;
    // ytChannel.videos = {"Graph", "Dynamic Programming"};

    YouTubeChannel ytChannel("Take You Forward", "Striver");
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.unSubscribe();
    ytChannel.publishVideo("Graphs");
    // ytChannel.setName("TUF");
    // ytChannel.getName();

    ytChannel.getInfo();
}