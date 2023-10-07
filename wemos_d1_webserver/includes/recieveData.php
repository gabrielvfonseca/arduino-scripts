<?php

// Check connection
if ($connection->connect_error) {
    die("Connection failed: " . $connection->connect_error);
}

$select = "SELECT id, data_sensorLM35, data_sensorMQ2 FROM sensorData";
$result = $connection->query($select);

if ($result->num_rows > 0) {
    // output data of each row on the database
    while($row = $result->fetch_assoc()) {
        echo "<br>" . $row["id"] . $row["data_sensorLM35"] . $row["data_sensorMQ2"] . "<br>";
    }
}
else {
    echo "No results on database...";
}

$connection->close();