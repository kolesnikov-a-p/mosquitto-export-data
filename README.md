# mosquitto-export-data

Mosquitto Export Data plugin for the Mosquitto MQTT broker

### Build

apt install libwebsockets-dev libc-ares2 libc-ares-dev openssl uuid uuid-dev gcc make wget

wget http://mosquitto.org/files/source/mosquitto-2.0.11.tar.gz && tar xzvf mosquitto-2.0.11.tar.gz

cd mosquitto-2.0.11


make MOSQUITTO_SRC=/root/mosquitto-2.0.11

