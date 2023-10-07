<?php

// Database login
$dbServername = "sql4.freesqldatabase.com:3306";
$dbUsername = "sql4424482";
$dbPassword = "DGsTZJdEdI";
$dbName = "sql4424482";

$connection = mysqli_connect($dbServername, $dbUsername, $dbPassword, $dbName);

// Check connection
if ($connection->connect_error) {
    die("Connection failed: " . $connection->connect_error);
}

$select = "SELECT id, serverStatus, data_sensorLM35, data_sensorMQ2 FROM alarm ORDER BY id DESC LIMIT 10";
$result = $connection->query($select);

$id = array();
$sensorLM35 = array();
$sensorMQ2 = array();

if ($result-> num_rows > 0) {
    // output data of each row on the database
    $index = 0;
    while($row = $result->fetch_assoc()) {
        $id[$index] = $row["id"];
        $sensorLM35[$index] = $row["data_sensorLM35"];
        $sensorMQ2[$index] = $row["data_sensorMQ2"];
        $serverStatus = $row["serverStatus"];
        $index++; // Increment +1
    }
}
else {
    echo "No results on database...";
}

$connection->close();

?>