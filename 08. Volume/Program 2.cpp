#include <iostream>
#include <cmath>
using namespace std;

double getSphereVolume(double radius){
    double volume;
    volume = (4.0/3.0)*3.14159*radius*radius*radius;
    return volume;
}
double getConeVolume(double radius, double height){
    double volume;
	volume = (1/3.0)*3.14159*radius*radius*height;
	return volume;
}
double getPrismVolume(double l, double w, double h){
    double volume;
	volume = l*w*h;
	return volume;
}
double getCubeVolume(double side){
    double volume;
	volume = pow(side,3);
	return volume;
}
double getValue(){
    double value;
    while (true) {
        cin>>value;
        if (value < 0) {
            cout <<"Invalid... Must be a Positive"<<endl;
        }
        else {
            break;
        }
        cout <<"Re-Enter: ";
    }
    return value;
}

int main(){
    int choice;
    while (true) {
        cout<<"\nComputing the volume of any of the following:"<<endl;
        cout<<"1 - Sphere"<<endl;
        cout<<"2 - Cone"<<endl;
        cout<<"3 - Rectangular Prism"<<endl;
        cout<<"4 - Cube"<<endl;
        cout<<"5 - Quit"<<endl;
        cout<<"Enter Choice: ";
        cin>>choice;
        
		switch (choice) {
        case 1: {
            double radius;
            cout<<"Enter Radius: ";
            radius = getValue();
            cout<<"Volume of Sphere: "<<getSphereVolume(radius)<<endl;
            continue;
        }
        case 2: {
            double radius, height;
            cout<<"Enter Radius: ";
            radius = getValue();
            cout<<"Enter Height: ";
            height = getValue();
            cout<<"Volume of cone: "<<getConeVolume(radius, height)<<endl;
            continue;
        }
        case 3: {
            double l, w, h;
            cout<<"Enter length: ";
            l = getValue();
            cout<<"Enter width: ";
            w = getValue();
            cout<<"Enter height: ";
            h = getValue();
            cout<<"Volume of Rectangular Prism: "<<getPrismVolume(l, w, h)<<endl;
            continue;
        }
        case 4: {
            double side;
            cout<<"Enter the side/edge of the cube: ";
            side = getValue();
            cout<<"Volume of cube: "<<getCubeVolume(side)<<endl;
            continue;
        }
        case 5: {
            break;
        }
        default: {
            cout<<"Invalid Option..."<<endl;
            continue;
        }
    	}
        break;
    }
    return 0;
}







