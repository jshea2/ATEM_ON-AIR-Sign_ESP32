#include <WiFi.h>
#include <WiFiUdp.h>
#include <ATEMmin.h>

// WiFi credentials
const char* ssid = "SSID";  // Replace with your SSID
const char* password = "password";  // Replace with your password

// ATEM device IP address
const IPAddress atemIP(192, 168, 10, 240); // Replace with your ATEM IP Address

// ATEMmin instance
ATEMmin atem;

// Function to connect to WiFi
void connectToWiFi() {
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi connected.");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

// Function to check the streaming status of ATEM
void checkATEMStatus() {
    if (atem.isConnected()) {
        Serial.println("ATEM is connected.");

        uint16_t streamingFlags = atem.getStreamingStatusFlags();

        if (atem.getStreamStreaming()) {
            Serial.println("ATEM is currently streaming.");
        } else if (atem.getStreamIdle()) {
            Serial.println("ATEM stream is idle.");
        } else if (atem.getStreamConnecting()) {
            Serial.println("ATEM is connecting to the stream.");
        } else if (atem.getStreamStopping()) {
            Serial.println("ATEM is stopping the stream (still streaming).");
        } else if (atem.getStreamInvalidState()) {
            Serial.println("ATEM stream is in an invalid state.");
        } else if (atem.getStreamUnknownError()) {
            Serial.println("ATEM has encountered an unknown streaming error.");
        } else {
            Serial.println("ATEM streaming status is unknown.");
        }

        Serial.print("Streaming Status Flags: ");
        Serial.println(streamingFlags, HEX);

    } else {
        Serial.println("ATEM is not connected.");
    }
}

void setup() {
    // Start serial communication
    Serial.begin(115200);

    // Connect to WiFi
    connectToWiFi();

    // Initialize ATEM connection
    atem.begin(atemIP);
    atem.connect();
    pinMode(15, OUTPUT);

    // Allow some time for the ATEM to connect
    delay(5000);
}

void loop() {
    // Run the ATEM loop to maintain connection
    atem.runLoop();

    // Check the ATEM status
    if (atem.isConnected()) {
        if (atem.getStreamStreaming()) {
            // If ATEM is connected and streaming, set pin 15 HIGH
            digitalWrite(15, HIGH);
            Serial.println("Pin 15 HIGH: ATEM is streaming.");
        } else if (atem.getStreamConnecting()) {
            // If ATEM is connecting, blink pin 15
            Serial.println("Pin 15 blinking: ATEM is connecting.");
            digitalWrite(15, HIGH); // Turn relay on
            // delay(200); // Wait for 200 ms
            // digitalWrite(15, LOW);  // Turn relay off
            // delay(200); // Wait for 200 ms
        } else {
            // If ATEM is idle or in any other state, set pin 15 LOW
            digitalWrite(15, LOW);
            Serial.println("Pin 15 LOW: ATEM is idle or in another state.");
        }
    } else {
        // If ATEM is not connected, set pin 15 LOW
        digitalWrite(15, LOW);
        Serial.println("Pin 15 LOW: ATEM is not connected.");
    }

    // Check the ATEM status every 200 ms
    delay(200);
}
