#include<string>
#include<iostream>
using namespace std;

//pure abstract class
class IcommunicationManger {

public:
	virtual void shareContent(string imageLink) = 0; 

};

class ImageGalleryA {
private:

	string images[5] = { "one.jpg","two.jpg","three.jpg","four.jpg","fiv.jpg" };
public:
	
	// share 
	void share(int index, IcommunicationManger* comManager) {
		comManager->shareContent(images[index]);
	}

};

class BluetoothManagerA : public IcommunicationManger {
public:
	void searchDevices() {}
	void pairdevice() {}
	void sendContent(int id) {}
	void turnOn() {}
	void turnOff() {}
	BluetoothManagerA() {}
	void shareContent(string imageLink) {
		cout << "image shared via Bluetooth" << endl;
	}
	
};

class WhatsAppManagerA : public IcommunicationManger {
public:
	void turnOn() {}
	void turnOff() {}
	void shareContent(int id) {}
	void joinGroup() {}
	void addMember() {}
	void createGroup() {}
	WhatsAppManagerA() {}
	void shareContent(string imageLink) {
		cout << "image shared via Whatsapp" << endl;
	}
	


};

class MailManagerA : public IcommunicationManger {

public:
	void pullNewMails() {}
	void senMails() {}
	void composeEmail() {}
	void addAttachement() {}
	MailManagerA() {}
	void shareContent(string imageLink) {
		cout << "image shared via Mail" << endl;
	}
	

};

int main() {

	MailManagerA* _mailManager = new  MailManagerA();
	BluetoothManagerA* _BluetoothManager = new  BluetoothManagerA();
	WhatsAppManagerA* _WhatsAppManager = new  WhatsAppManagerA();

	ImageGalleryA* imageMgmt = new  ImageGalleryA();
	imageMgmt->share(0,_BluetoothManager);

}