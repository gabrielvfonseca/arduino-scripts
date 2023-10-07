<?php

$dbServername = "localhost";
$dbUsername = "root"; // Default
$dbPassword = ""; // Default
$dbName = "arduino";

$connection = mysqli_connect($dbServername, $dbUsername, $dbPassword, $dbName);

// Check connection
if ($connection->connect_error) {
    die("Connection failed: " . $connection->connect_error);
}

$select = "SELECT id, data_sensorLM35, data_sensorMQ2 FROM sensorData";
$result = $connection->query($select);

$id = array();
$sensorLM35 = array();
$sensorMQ2 = array();

if ($result->num_rows > 0) {
    // output data of each row on the database
    $index = 0;
    while($row = $result->fetch_assoc()) {
        $id[$index] = $row["id"];
        $sensorLM35[$index] = $row["data_sensorLM35"];
        $sensorMQ2[$index] = $row["data_sensorMQ2"];

        //echo $id[$index] . $sensorLM35[$index] . $sensorMQ2[$index] . "<br>";
        $index++; // Increment +1
    }
}
else {
    echo "No results on database...";
}

$connection->close();

?>

<script>
// get last 4 values of the array
    var data = [
        { 
            id: 1, // Group Id
            ml35: 2, // Sensor ML35 value
            mq2: 3 // Sensor MQ2 value
        }
    ]

    document.addEventListener("DOMContentLoaded", getData);

    function getData() {
        for (var index = 0; index < 4; index++) {
            var id = "<?php echo $id[$index] ?>";
            var ml35 = "<?php echo $sensorLM35 ?>";
            var mq2 = "<?php echo $sensorMQ2 ?>";
            alert("id: " + id + "\n" + "ml35: " + ml35 + "\n" + "mq2: " + mq2);
        }
    }
</script>
