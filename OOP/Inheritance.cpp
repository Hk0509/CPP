#include<iostream>
#include<list>
#include<vector>
using namespace std;

class YouTubeChannel{
    //Noone outside this class can access it
    private:
        string name;
        int subscribersCount;
        list<string> videos;

    //Derived(Child) class can access it
    protected:
        string ownerName;

    //Anyone can access it
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

class cookingYouTubeChannel :public YouTubeChannel{
    public:
        cookingYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName){
        }

        void Practice(){
            cout<<ownerName<<" should Cook..Taste...Repeat"<<endl;
        }

};

int main(){
   cookingYouTubeChannel cookingYTChannel("Hks' Kitchen", "Hk");
   YouTubeChannel ytChannel("TUF", "Striver");

    cookingYTChannel.publishVideo("Pizza");
    cookingYTChannel.publishVideo("Momos");
    cookingYTChannel.Subscribe();
    cookingYTChannel.getInfo();
    cookingYTChannel.Practice();
}