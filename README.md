# mosquitto-export-data

Mosquitto Export Data plugin for the Mosquitto MQTT broker

### Build

apt install libwebsockets-dev libc-ares2 libc-ares-dev openssl uuid uuid-dev gcc g++ make wget libcjson1 libcjson-dev

wget http://mosquitto.org/files/source/mosquitto-2.0.11.tar.gz && tar xzvf mosquitto-2.0.11.tar.gz

cd mosquitto-2.0.11 && make && make install

systemctl unmask mosquitto service && systemctl start mosquitto


make MOSQUITTO_SRC=/root/mosquitto-2.0.11 && make install

/usr/local/sbin/mosquitto -c /etc/mosquitto/mosquitto.conf