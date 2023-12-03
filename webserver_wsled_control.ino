
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Adafruit_NeoPixel.h>

#define P1 4 
#define NUMPIXELS 64  // Number of leds in your strip

String rs;
String gs;
String bs;

Adafruit_NeoPixel matrix(NUMPIXELS, P1, NEO_GRB + NEO_KHZ800);

const char* ssid = "YOUR WIFI SSID";
const char* password = "YOUR WIFI PASSWORD";

AsyncWebServer server(80);

const char* RPARAM = "red";
const char* GPARAM = "green";
const char* BPARAM = "blue";

int c=0;

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        html {
            font-family: Arial, Helvetica, sans-serif;
            display: inline-block;
            text-align: center;
        }
        h1 {
            font-size: 1.8rem;
            color: rgb(248, 243, 243);
        }
        .head {
            overflow: hidden;
            background-color: #0A1128;
        }
        p {
            font-size: 1.4rem;
        }
        .slider {
            margin:0 auto;
            width: 70%;
            height: 15px;
            outline: 1px solid rgb(0, 0, 0);
        }
        .slider::-webkit-slider-thumb {
            width: 30px;
            height: 15px;
            border-radius: 1px;
            cursor: pointer;
            outline: 5px solid rgb(2, 0, 0);
        }
        body {
            margin: 0;
        }
    </style>
</head>
<body>
    <div class="head">
        <h1>ESP RGB CONTROL</h1>
    </div>
    <div class="form">
        <form>
            <p>
                <label for="r">RED:(<span id="rn"></span>)</label>
                <input type="range" id="r" class="slider" oninput="redvalue(this)" name="red" min="0" max="255">
            </p>
            <p>
                <label for="g">GREEN(<span id="gn"></span>):</label>
                <input type="range" id="g" class="slider" oninput="greenvalue(this)" name="green" min="0" max="255">
            </p>
            <p>
                <label for="b">BLUE(<span id="bn"></span>):</label>
                <input type="range" id="b" class="slider" oninput="bluevalue(this)" name="blue" min="0" max="255">
            </p>
            <p>
                <input type="submit" value="Submit" style="height:50px; width:100px">
            </p>    
        </form>  
    </div>    
    <script>
        function redvalue(element){
            var val = element.value;
            document.getElementById("rn").innerHTML = val;
        }
        function greenvalue(element){
            var val = element.value;
            document.getElementById("gn").innerHTML = val;
        }
        function bluevalue(element){
            var val = element.value;
            document.getElementById("bn").innerHTML = val;
        }
    </script>
</body>
</html>
)rawliteral";

 

void initWiFi() {
WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 Serial.print("Connecting to WiFi ..");
 while (WiFi.status() != WL_CONNECTED) {
 Serial.println("Wifi not found");
 delay(1000);
 }
 Serial.println(WiFi.localIP());
 }

void setup() {
  Serial.begin(115200);
  initWiFi();
  matrix.begin();

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/html", index_html);
   if (request->hasParam(RPARAM) & request->hasParam(GPARAM) & request->hasParam(BPARAM)) 
   {
     rs = request->getParam(RPARAM)->value();
     gs = request->getParam(GPARAM)->value();
     bs = request->getParam(BPARAM)->value();
   }
   else
   {
     rs = "0";
     gs = "0";
     bs = "0";
   }
     Serial.println(rs);
     Serial.println(gs);
     Serial.println(bs);

     for(int i=0; i<64; i++){ 
      matrix.setPixelColor(i,matrix.Color(rs.toInt(),gs.toInt(),bs.toInt()));
     }
    matrix.show();
    delay(1000);   
//   request->send_P(200, "text/plain", "OK");
 });



 server.begin(); 
}

void loop() {

  
}












  
