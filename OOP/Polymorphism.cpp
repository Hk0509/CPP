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
        int contentQuality;

    //Anyone can access it
    public:
        YouTubeChannel(string name, string ownerName){
            this -> name = name;
            this -> ownerName = ownerName;
            subscribersCount = 0;
            contentQuality = 0;
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

        void checkAnalytics(){
            if(contentQuality<5)
            cout<<name<<"' has Poor content quality!!"<<endl;
            else
            cout<<name<<" has Good content quality!!"<<endl;
        }
};

class cookingYouTubeChannel :public YouTubeChannel{
    public:
        cookingYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName){
        }

        void Practice(){
            cout<<ownerName<<" should Cook..Taste...Repeat"<<endl;
            contentQuality++;
        }

};

class singingYouTubeChannel :public YouTubeChannel{
    public:
        singingYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName){
        }

        void Practice(){
            cout<<ownerName<<" should practice singing....take a break....and drink warm."<<endl;
            contentQuality++;
        }

};

int main(){
   cookingYouTubeChannel cookingYTChannel("Hks' Kitchen", "Hk");
   singingYouTubeChannel singingYTChannel("Himanshu Sings", "Himanshu");
   cookingYouTubeChannel* yt1 = &cookingYTChannel;
   singingYouTubeChannel* yt2 = &singingYTChannel;

    cookingYTChannel.publishVideo("Pizza");
    cookingYTChannel.publishVideo("Momos");
    cookingYTChannel.Subscribe();
    cookingYTChannel.Practice();
    cookingYTChannel.Practice();
    cookingYTChannel.Practice();
    cookingYTChannel.Practice();
    cookingYTChannel.Practice();
    cookingYTChannel.Practice();
    singingYTChannel.Practice();
    singingYTChannel.Practice();

    yt1 -> checkAnalytics();
    yt2 -> checkAnalytics();
    // cookingYTChannel.getInfo();
}