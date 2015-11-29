#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(int argc, const char **argv)
{
	int n;
	int m;
	int offset;
	int temp;

	cout << "inserisci il numero di sensori che sia maggiore o uguale a 3: ";
	cin >> n;
	while(n<3){
		cout << "inserisci il numero di sensori che sia maggiore o uguale a 3: ";
		cin >> n;
	}


	cout << "inserisci il numero di round che sia maggiore o uguale a 3: ";
	cin >> m;
	while(m<3){
		cout << "inserisci il numero di round che sia maggiore o uguale a 3: ";
		cin >> m;
	}

	cout << "inserisci la temperatura di partenza: ";
	cin >> temp;

	cout << "inserisci la variazione massima di temperatura: ";
	cin >> offset;

	ofstream file("Objects UMC.txt");
	file << "Objects: " << endl;

	srand((unsigned)time(0));
	int offsetTemperature[m];
	stringstream stringOffset[n+1];
	stringstream update;
	for(int i=1; i<=n; i++){
		//temp = (rand()%90-30); // valori tra -30 e +59
		stringOffset[i-1] << "[";
		for(int j=0; j< m-1 ; j++){
			offsetTemperature[j] = (rand()%(offset*2))-offset; //valori tra [-offset, +offset -1]
			stringOffset[i-1] << offsetTemperature[j] << ", ";
		}
		offsetTemperature[m-1] = (rand()%(offset*2))-offset;
		stringOffset[i-1] << offsetTemperature[m-1] << "]";


		if(i==1){
			file << "sensor1: Head ( rightSensor = sensor2 , temperature = " << temp << ", round = " << m <<", myupdate = update, offsetTemperature = " << stringOffset[i-1].str() << " )" << endl;
			update << "sensor" << i << ", ";
		}else if (i==n){
			file << "sensor" <<  n <<": Tail ( leftSensor = sensor" << (n-1) << ", temperature = " << temp << ", myupdate = update, offsetTemperature = " << stringOffset[n-1].str() << " )" << endl;
			update << "sensor" << i << "], ";
		}else{
			file <<	"sensor" << i <<": Intermediate ( rightSensor = sensor" << (i+1) <<", leftSensor = sensor" << (i-1) <<", temperature = " << temp << ", myupdate = update, offsetTemperature = " << stringOffset[i-1].str() << " )" << endl;
			update << "sensor" << i << ", ";
		}

	}
	for(int j=0; j< m-1 ; j++){
		offsetTemperature[j] = (rand()%(offset*2))-offset; //valori tra [-offset, +offset -1]
		stringOffset[n] << offsetTemperature[j] << ", ";
	}
	offsetTemperature[m-1] = (rand()%(offset*2))-offset;
	stringOffset[n] << offsetTemperature[m-1] << "]";
	file << "update : UpdateSensor ( nowRound = " << m << ", sensor = [" <<  update.str() << "temperature = [" << stringOffset[n].str() << ")" << endl;


	file.close();
	return 0;


}
