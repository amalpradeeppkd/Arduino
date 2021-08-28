String pass1="hi";
void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	pinMode(10,OUTPUT);
	pinMode(13,OUTPUT);
}

void loop() {
	// put your main code here, to run repeatedly:
	String pass;
	int count=0;
	while(count<3)
	{
		if(Serial.available()){
			Serial.println("Welcome Amal");
			Serial.println("Enter Password");
			pass=Serial.readString();
			if(pass1 == pass)
			{
				digitalWrite(10,HIGH);
				digitalWrite(13,LOW);
				Serial.println("Door Open");
				count++;
				break;
			}
			else if(pass1!=pass){
				digitalWrite(10,LOW);
				digitalWrite(13,HIGH);
				Serial.println("Door Locked");
				count++;
				if(count==3)
				{
					while(true)
					{
						digitalWrite(10,HIGH);
						digitalWrite(13,HIGH);
						delay(100);
						digitalWrite(10,LOW);
						digitalWrite(13,LOW);
						delay(100);
					}
				}
			}
		}
	}
}
