#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Door {
public:
	virtual void open() {}
	virtual void close() {}
};

class IDoorStateNotifier {
public:
	virtual void notify(string status) = 0;

};

class Buzzer : public IDoorStateNotifier {
public: 
	void makeNoise() {}
	void notify(string status) {
		cout << " Buzzer is Notified: Door status is " << status << endl;
		makeNoise();
	}
};

class SMSManager : public IDoorStateNotifier{

public:void sendNotificationMessage() {}
	  void notify(string status)
	  {
		  cout << " SMSManager is Notified: Door status is " << status << endl;
		  this->sendNotificationMessage();
	  }

};

class VisualizationManager : public IDoorStateNotifier{
public:
void turnVideoOn() {}
void turnVideoOff() {}
void notify(string status)
{
	cout << " VisualizationManager Notified : Door status is " << status << endl;
}
};




class SecuredDoor : public Door {
private:
	IDoorStateNotifier* notifierRef;
public:
	SecuredDoor(IDoorStateNotifier* notifierRefArg) : notifierRef{ notifierRefArg } {}
	void open() override {
		this->notifierRef->notify("open");
	}

	void close() override {
		this->notifierRef->notify("closed");
	}

	
};

class Notifier : public IDoorStateNotifier {
private:
	vector<IDoorStateNotifier*> notifierList;

public:
	
	void notify(string status) {
		for (int i = 0; i < notifierList.size(); i++)
		{
			notifierList[i]->notify(status);
		}
	}
	void addNotifier(IDoorStateNotifier* notifierArg) {
		notifierList.push_back(notifierArg);
	
	}
};
int main()
{
	Buzzer buzzerObj;
	SMSManager smsManagerObj;
	VisualizationManager visualManagerObj;

	Notifier notifierObj;
	notifierObj.addNotifier(&buzzerObj);
	notifierObj.addNotifier(&smsManagerObj);
	notifierObj.addNotifier(&visualManagerObj);

	SecuredDoor sd1{ &notifierObj };
	sd1.open();
	sd1.close();


}