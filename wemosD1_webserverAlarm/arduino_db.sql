/* Create table in db using SQL*/
create table sensorData (
    id int not null,
    data_sensorLM35 int(2) not null, 
    data_sensorMQ2 int(2) not null
)

create table arduinoActions (
    ledStatus varchar(5),
    sensibilityServer varchar(255),
    preciselyServer varchar(255)
)


/* Insert data in db using SQL*/
INSERT INTO arduino.sensorData (id, data_sensorLM35, data_sensorMQ2) VALUES (1, 2, 3);
INSERT INTO arduino.arduinoactions (ledStatus, sensibilityServer, preciselyServer) VALUES ("ON", 400, 4);