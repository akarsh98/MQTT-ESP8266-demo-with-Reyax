# MQTT-Based-Home-Automation-Board-Reyax-MQTT-Broker

Video tutorial : [https://youtu.be/ULMnPckZp1M](https://youtu.be/Eg-_IFHFcZg)

![alt text](https://github.com/akarsh98/MQTT-ESP8266-demo-with-Reyax/blob/main/Home%20Automation%20Board/7.JPG)

In this project, we are going to make a Home Automation Board which is made with the help of ESP8266 and whose work is based on MQTT. MQTT is a lightweight messaging protocol that works on Publish and Subscribe mechanism. In between, there is a broker who receives messages from the publisher and makes them available to the Subscriber. So by using this MQTT technology, we are going to make a Board that is capable of connecting over to the Internet and we can control our home appliances over the Internet using this board.
![alt text](https://github.com/akarsh98/MQTT-ESP8266-demo-with-Reyax/blob/main/Home%20Automation%20Board/9.JPG)

We have made the project on a Custom PCB of our own. It has the ESP8266 microcontroller chip and to that, we have connected a relay. A relay is a kind of electronic switch which is capable of acting as a switch in high voltage applications and requires a small current for its application. So what we have done is that through this relay we have connected an LED to the ESP8266 and we will control the LED from our phone/tablet.

![alt text](https://github.com/akarsh98/MQTT-ESP8266-demo-with-Reyax/blob/main/Home%20Automation%20Board/15.JPG)

For controlling the LED we have an app named "IoT OnOff" installed on our phone/tablet. We can create a dashboard on the app and by configuring the dashboard we can connect it to the MQTT Broker. Once both the devices i.e. our phone/table and our PCB are connected to the Broker they both will act as clients and will be able to communicate to each other and once everything will be done we would see that when we toggle the switch ON or OFF, the LED on the board also turns ON or OFF in accordance to the command that we sent. So by using this board we can control our home appliances easily over the Internet. We can also increase the number of relays by modifying the PCBs design and with that, we can control several different appliances by using just a single board.

![alt text](https://github.com/akarsh98/MQTT-ESP8266-demo-with-Reyax/blob/main/Home%20Automation%20Board/jlcpcb.JPG)


You must check out [JLCPCB](https://jlcpcb.com/aka) for ordering PCBs online for cheap!

You get 10 good quality PCBs manufactured and shipped to your doorstep for 2$ and some shipping. You will also get a discount on shipping on your first order. To design your own PCB head over to easyEDA, once that is done upload your Gerber files onto [JLCPCB](https://jlcpcb.com/aka) to get them manufactured with good quality and quick turnaround time.
