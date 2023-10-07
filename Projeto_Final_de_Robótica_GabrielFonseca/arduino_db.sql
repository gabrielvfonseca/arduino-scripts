/*
 * Dev by Gabriel. 
 * WebServer project with Arduino D1.
 * More info on README.md file.
 * 13/07/2021
*/


/* Create table in db using SQL*/
create table alarm (
    id int not null PRIMARY KEY,
    serverStatus varchar(255) not null,
    data_sensorLM35 int(2) not null, 
    data_sensorMQ2 int(2) not null
)

/* Insert data in db using SQL*/
INSERT INTO sql4424482.alarm (id, serverStatus, data_sensorLM35, data_sensorMQ2) VALUES (1, 1, 3, 6) 