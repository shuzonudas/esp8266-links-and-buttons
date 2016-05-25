#include "LCD.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "BTCL ADSL";
const char* pass = "your_password";

ESP8266WebServer server(80);

void root()
{
	char temp[400];

	snprintf(temp, 400,
		"<html>\
  <head>\
  </head>\
  <body>\
    <h1>How to html page really good</h1>\
	<a href =\"/number?value=0\">Bright</a>\
	<a href =\"/number?value=512\">Medium</a>\
	<a href =\"/number?value=1023\">Low</a>\
	<a href =\"/string?input=button\"> <button> <h3> button <\h3> </button> </a>\
	<a href =\"/string?input=give me food\"> <button> <h3> food <\h3> </button> </a>\
	<a href =\"/string?input=let me sleep\"> <button> <h3> sleep <\h3> </button> </a>\
  </body>\
</html>");
	server.send(200, "text/html", temp);


	/*
	server.send(200, "text/plain", "1->Open /number?value=90 to print number on LCD \r\n\
2->Open /string?input=putYourString to print text on LCD \
		");
	*/
}

void handle_string() {
	char inputString[100];
	server.arg("input").toCharArray(inputString, 99, 0);
	Serial.println(inputString);

	// print on the LCD
	setCursor(0, 50);
	print(inputString);
	print("          ");

	server.send(200, "text/plain",inputString);
}

void handle_number()
{
	String sval = server.arg("value");
	String xval = server.arg("muga");

	Serial.println(sval.toInt());
	Serial.println(xval.toFloat());
	int ival = sval.toInt();
	Serial.println(ival);
// print on the LCD
	setCursor(0, 50);
	print(ival);
	print("          ");

	analogWrite(13, ival);

	server.send(200, "text/plain", String(ival, DEC));
}

void setup(void) {
	Serial.begin(115200);
	Serial.println("");

	init_LCD();
	rotate(1);
	setBackColor(0x00, 0x00, 0x00);
	fillScreen();
	
	setTextSize(2);
	setColor(0xFF, 0xFF, 0xFF);
	setCursor(0, 2);
	println("Connecting..");
	WiFi.begin(ssid, pass);
	// Wait for connection
	setCursor(0, 20);
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
		print(".");
	}


	Serial.println("");
	Serial.print("Connected to ");
	Serial.println(ssid);
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());

	setCursor(0, 2);
	print("Connected to:");
	println(ssid);

	IPAddress ipadd;
	char ipAddConverted2String[26];
	ipadd = WiFi.localIP();
	sprintf(ipAddConverted2String, "%d.%d.%d.%d", ipadd[0], ipadd[1], ipadd[2], ipadd[3]);
	println(ipAddConverted2String);


	server.on("/", root);
	server.on("/number", handle_number);
	server.on("/string", handle_string);
	server.begin();
	Serial.println("HTTP server started");

}

void loop(void) {
	server.handleClient();
}
