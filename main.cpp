/*

	Shutdown Killer v2.0 By Xia

*/

// #include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#include <thread>
using std::thread;
#include <vector>
using std::vector;


struct ThreadItem {
	thread worker;
};

void* ThreadFunction() {
	
	while(1){
		
		system("shutdown -a"); // Command Here!
		cout<<"from thread ID "<<std::this_thread::get_id()<<endl;
		
	}
	
}

int main(){
	
	// Get the amount of "processing units"
	int n = std::thread::hardware_concurrency();
	
	// Create array of threads
	vector<ThreadItem> threadlist;
	threadlist.resize(n);
	
	// Spawn a thread for each core
	for(int i = 0;i < n ;i++) {
		threadlist[i].worker = thread(ThreadFunction);
	}
	
	
	// Wait for them all to finish
	for(int i = 0;i < n;i++) {
		threadlist[i].worker.join();
	}
	
	
    return 0;

}

